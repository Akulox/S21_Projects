#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int b, E, n, s, T, v;
} CatFlags;

void print_help(char *name);
void parseArguments(int argc, char **argv, CatFlags *flags);
void print_file_by_cat(FILE *file, CatFlags flags);

int main(int argc, char *argv[]) {
  CatFlags flags = {0, 0, 0, 0, 0, 0};
  parseArguments(argc, argv, &flags);

  for (int i = optind; i < argc; i++) {
    FILE *file = fopen(argv[i], "r");

    if (file == NULL) {
      printf("%s: %s: No such file or directory\n", argv[0], argv[i]);
      continue;
    }
    print_file_by_cat(file, flags);
    fclose(file);
  }

  return 0;
}

void parseArguments(int argc, char **argv, CatFlags *flags) {
  while (1) {
    int option_index = 0;
    static struct option long_options[] = {{"number-nonblank", 0, 0, 'b'},
                                           {"number", 0, 0, 'n'},
                                           {"squeeze-blank", 0, 0, 's'},
                                           {"show-tabs", 0, 0, 'T'},
                                           {"show-nonprinting", 0, 0, 'v'},
                                           {"help", 0, 0, 1},
                                           {0, 0, 0, 0}};

    int c = getopt_long(argc, argv, "benstvuET", long_options, &option_index);
    if (c == -1) break;

    if (c == 1) {
      printf("No help for you.\n");
      break;
    }
    switch (c) {
      case 'v':
        flags->v = 1;
        break;
      case 'b':
        flags->b = 1;
        flags->n = 1;
        break;
      case 'e':
        flags->E = 1;
        flags->v = 1;
        break;
      case 'E':
        flags->E = 1;
        break;
      case 'n':
        flags->n = 1;
        break;
      case 's':
        flags->s = 1;
        break;
      case 'T':
        flags->T = 1;
        break;
      case 't':
        flags->T = 1;
        flags->v = 1;
        break;
      case 'u':
        break;
      default:
        printf("Try '%s --help' for more information.\n", argv[0]);
    }
  }
}

void print_file_by_cat(FILE *file, CatFlags flags) {
  int ch;
  int lines = 1;
  int newline = !flags.b;
  int bIgnore = 1;
  int sIgnore = 0;
  int ignoreOutput = 0;

  while ((ch = fgetc(file)) != EOF) {
    if (flags.s) {
      if (sIgnore > 1) {
        if (ch == '\n')
          ignoreOutput = 1;
        else
          sIgnore = 0;
      }
      if (ch == '\n') {
        sIgnore++;
      }
    }
    if (flags.n && !ignoreOutput) {
      if (flags.b && bIgnore && ch != '\n') {
        newline = 1;
        bIgnore = 0;
      }
      if (newline) {
        newline = 0;
        printf("%6d\t", lines++);
      }
      if (ch == '\n') {
        if (!flags.b)
          newline = 1;
        else
          bIgnore = 1;
      }
    }
    if (flags.E && !ignoreOutput) {
      if (ch == '\n') {
        putchar('$');
      }
    }
    if (flags.T) {
      if (ch == '\t') {
        printf("^I");
        ignoreOutput = 1;
      }
    }
    if (flags.v && ch != '\n' && ch != '\t') {
      if (ch >= 128) {
        printf("M-");
        ch -= 128;
      }
      if (ch < 32 || ch == 127) {
        printf("^");
        ch = (ch < 32) ? ch + 64 : '?';
      }
    }
    if (!ignoreOutput) {
      putchar(ch);
    } else
      ignoreOutput = 0;
  }
}
