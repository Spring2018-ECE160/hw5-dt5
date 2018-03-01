CC=gcc
CFLAGS=-I. -Wall -Werror

question3: format main.c
	$(CC) $(CFLAGS) main.c -o question3

clean:
	rm question3

format:
	find . -name "*.[ch]" | xargs clang-format -style=Google -i
	
.PHONY: clean format
