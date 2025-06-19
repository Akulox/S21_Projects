C = gcc
CAT = s21_cat
CFLAGS = -Wall -Werror -Wextra -std=c11

all: $(CAT)

$(CAT):
	$(C) $(CFLAGS) $(CAT).c -o $(CAT)
test:
	chmod +x test_cat.sh
	bash test_cat.sh

clean:
	rm -rf $(CAT)
	rm -rf test_output
rebuild: clean all

