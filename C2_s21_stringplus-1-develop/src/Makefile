C_FLAGS = -Wall -Werror -Wextra -std=c11
C_FILES = s21_*.c
OBJ_FILES = $(C_FILES:.c=.o)

all: clean s21_string.a

s21_string.a:
	gcc $(C_FLAGS) -c $(C_FILES)
	ar rcs s21_string.a $(OBJ_FILES)
	ranlib s21_string.a
	rm -f $(OBJ_FILES)

test:
	gcc $(C_FLAGS) tests/test.c tests/tests*.c -lcheck -coverage -lpthread -pthread $(C_FILES) -o test -lm -lsubunit
	./test
	rm -rf *.gcda *.gcno

gcov_report: clean s21_string.a
	gcc $(C_FLAGS) tests/test.c tests/tests*.c -lcheck -coverage -lpthread -pthread $(C_FILES) -o gcov_report -lm -lsubunit
	./gcov_report
	lcov -t "gcovreport" -o gcovreport.info -c -d .
	genhtml -o report gcovreport.info

	rm -rf *.gcda *.gcno

memory_check: clean
	gcc $(C_FLAGS) tests/test.c tests/tests*.c -lcheck -lpthread -pthread $(C_FILES) -o memory_test.o -lm -lsubunit
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./memory_test.o

clean:
	rm -f *.o
	rm -f *.a
	rm -f test_suit*
	rm -f gcov_report
	rm -f test
	rm -f *.gcda
	rm -f *.gcno
	rm -f *.info
	rm -f *.log
	rm -rf report/

