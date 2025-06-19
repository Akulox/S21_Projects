#define _GNU_SOURCE
#include <getopt.h>
#include <locale.h>
#include <regex.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  int i, s, v, n, h, o, l, c;
} GrepFlags;

typedef struct {
  char **data;
  size_t size;
  size_t capacity;
} StringList;

void searchFile(FILE *file, const char *filename, StringList *patterns,
                const GrepFlags *flags, int fileCount, int compFlags);
void initList(StringList *list, size_t initialCapacity);
void addString(StringList *list, const char *str);
void freeList(StringList *list);
void parseArguments(int argc, char **argv, GrepFlags *flags,
                    StringList *patterns);

int main(int argc, char *argv[]) {
  setlocale(LC_ALL, "ru_RU.UTF-8");
  StringList patterns;
  initList(&patterns, 1);
  GrepFlags flags = {0, 0, 0, 0, 0, 0, 0, 0};
  parseArguments(argc, argv, &flags, &patterns);

  int fileCount = argc - optind;

  int compFlags = REG_NEWLINE;
  if (flags.i) compFlags |= REG_ICASE;

  for (int i = optind; i < argc; i++) {
    FILE *fp;
    fp = fopen(argv[i], "r");

    if (!fp) {
      if (!flags.s)
        fprintf(stderr, "%s: %s: No such file or directory\n", argv[0],
                argv[i]);
      continue;
    }
    searchFile(fp, argv[i], &patterns, &flags, fileCount, compFlags);

    fclose(fp);
  }
  freeList(&patterns);
  return 0;
}

void searchFile(FILE *file, const char *filename, StringList *patterns,
                const GrepFlags *flags, int fileCount, int compFlags) {
  if (patterns->size == 0) {
    fprintf(stderr, "No.\n");
    return;
  }
  char *line = NULL;
  int matchCount = 0;
  size_t len = 0;
  int lineCount = 0;
  while (getline(&line, &len, file) != -1) {
    int isMatch = 0;
    ++lineCount;
    regex_t regex;

    for (size_t j = 0; j < patterns->size; j++) {
      regmatch_t foundedExp;
      if (regcomp(&regex, patterns->data[j], compFlags)) {
        fprintf(stderr, "Regcomp failure\n");
        break;
      }
      if (regexec(&regex, line, 1, &foundedExp, 0) == 0) {
        isMatch = 1;

        if (flags->v) {
          regfree(&regex);
          continue;
        } else if (flags->o && !flags->l && !flags->c) {
          const char *lineCopy = line;
          while (regexec(&regex, lineCopy, 1, &foundedExp, 0) == 0) {
            if (fileCount > 1 && !flags->h) printf("%s:", filename);
            if (flags->n) printf("%d:", lineCount);
            printf("%.*s\n", (int)(foundedExp.rm_eo - foundedExp.rm_so),
                   lineCopy + foundedExp.rm_so);
            lineCopy += foundedExp.rm_eo;
          }
          regfree(&regex);
          continue;
        }
        regfree(&regex);
        break;
      }
      regfree(&regex);
    }
    if (flags->v) isMatch = !isMatch;
    if (isMatch) {
      matchCount++;
      if (flags->l) {
        printf("%s\n", filename);
        break;
      }
      if (flags->c) continue;
      if (!flags->o) {
        if (fileCount > 1 && !flags->h) printf("%s:", filename);
        if (flags->n) printf("%d:", lineCount);
        printf("%s", line);
      }
    }
  }

  if (flags->c && !flags->l) {
    if (fileCount > 1 && !flags->h) printf("%s:", filename);
    printf("%d\n", matchCount);
  }
  free(line);
}

void parseArguments(int argc, char **argv, GrepFlags *flags,
                    StringList *patterns) {
  static struct option long_options[] = {{"regexp", 1, 0, 'e'},
                                         {"file", 1, 0, 'f'},
                                         {"files-with-matches", 0, 0, 'l'},
                                         {"count", 0, 0, 'c'},
                                         {"ignore-case", 0, 0, 'i'},
                                         {"no-messages", 0, 0, 's'},
                                         {"invert-match", 0, 0, 'v'},
                                         {"line-number", 0, 0, 'n'},
                                         {"no-filename", 0, 0, 'h'},
                                         {"only-matching", 0, 0, 'o'},
                                         {"help", 0, 0, 1},
                                         {0, 0, 0, 0}};

  while (1) {
    int option_index = 0;
    int c =
        getopt_long(argc, argv, "e:f:lcisvnho", long_options, &option_index);

    if (c == -1) break;
    if (c == 1) {
      printf("No help for you.\n");
      break;
    }
    switch (c) {
      case 'e':
        addString(patterns, optarg);
        break;
      case 'f':
        FILE *file = fopen(optarg, "r");
        if (!file) {
          fprintf(stderr, "%s: %s: No such file or directory\n", argv[0],
                  optarg);
          freeList(patterns);
          exit(EXIT_FAILURE);
        }

        char *line = NULL;
        size_t len = 0;
        while (getline(&line, &len, file) != -1) {
          size_t length = strlen(line);
          if (length > 0 && line[length - 1] == '\n') line[length - 1] = '\0';
          addString(patterns, line);
        }
        free(line);
        fclose(file);
        break;
      case 'l':
        flags->l = 1;
        break;
      case 'c':
        flags->c = 1;
        break;
      case 'i':
        flags->i = 1;
        break;
      case 's':
        flags->s = 1;
        break;
      case 'v':
        flags->v = 1;
        break;
      case 'n':
        flags->n = 1;
        break;
      case 'h':
        flags->h = 1;
        break;
      case 'o':
        flags->o = 1;
        break;

      default:
        printf("Try '%s --help' for more information.\n", argv[0]);
    }
  }
  if (patterns->size == 0 && optind < argc) addString(patterns, argv[optind++]);
}

void initList(StringList *list, size_t initialCapacity) {
  list->data = (char **)malloc(initialCapacity * sizeof(char *));
  if (list->data == NULL) {
    fprintf(stderr, "Memory error 0");
    freeList(list);
    exit(EXIT_FAILURE);
  }
  list->size = 0;
  list->capacity = initialCapacity;
}

void addString(StringList *list, const char *str) {
  if (list->size >= list->capacity) {
    size_t newCapacity = list->capacity * 2;
    char **newData = (char **)realloc(list->data, newCapacity * sizeof(char *));
    if (newData == NULL) {
      fprintf(stderr, "Memory error 1");
      freeList(list);
      exit(EXIT_FAILURE);
    }
    list->data = newData;
    list->capacity = newCapacity;
  }
  list->data[list->size] = strdup(str);
  if (list->data[list->size] == NULL) {
    fprintf(stderr, "Copy error 0");
    freeList(list);
    exit(EXIT_FAILURE);
  }
  list->size++;
}

void freeList(StringList *list) {
  for (size_t i = 0; i < list->size; i++) {
    free(list->data[i]);
  }
  free(list->data);
  list->data = NULL;
  list->size = 0;
  list->capacity = 0;
}
