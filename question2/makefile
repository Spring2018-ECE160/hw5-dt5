CC=gcc
CFLAGS=-I. -Wall -Werror

question2: main.c
	$(CC) $(CFLAGS) main.c -o question2

clean:
	rm question2

format:
	find . -name "*.[ch]" | xargs clang-format -style=Google -i
	
.PHONY: clean format
