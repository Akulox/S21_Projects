#include "test.h"

int main(void) {
  int fail_count = 0;
  setlocale(LC_ALL, "en_US.UTF-8");

  Suite *test_list[] = {

      // INITIAL
      tests_memchr(),
      tests_memcmp(),
      tests_memcpy(),
      tests_memset(),
      tests_strncat(),
      tests_strchr(),
      tests_strncmp(),
      tests_strncpy(),
      tests_strcspn(),
      tests_strerror(),
      tests_strlen(),
      tests_strpbrk(),
      tests_strrchr(),
      tests_strstr(),
      tests_strtok(),

      tests_sscanf(),
      tests_sprintf(),

      // ADDITIONAL
      tests_to_upper(),
      tests_to_lower(),
      tests_insert(),
      tests_trim(),

      // OTHER
      tests_wchar_wcstombs(),

  };

  size_t num_tests = sizeof(test_list) / sizeof(test_list[0]);

  for (size_t i = 0; i < num_tests; i++) {
    Suite *s = test_list[i];
    SRunner *runner = srunner_create(s);

    if (runner != NULL) {
      srunner_set_fork_status(runner, CK_NOFORK);
      srunner_run_all(runner, CK_NORMAL);
      fail_count += srunner_ntests_failed(runner);
      srunner_free(runner);
      (fail_count > 0) ? printf("Failed!") : printf("Succeeded!");
      putchar('\n');
    }
  }

  return 0;
}
