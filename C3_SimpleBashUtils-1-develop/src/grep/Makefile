C = gcc
GREP = s21_grep
CFLAGS = -Wall -Werror -Wextra -std=c11

all: $(GREP)

$(GREP):
	$(C) $(CFLAGS) $(GREP).c -o $(GREP)
test:
	chmod +x test_grep.sh
	bash test_grep.sh

clean:
	rm -rf $(GREP)
	rm -rf test_output

rebuild: clean all

