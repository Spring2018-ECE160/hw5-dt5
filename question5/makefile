CC=gcc
CFLAGS=-I. -Wall -Werror

question5: main.c
	$(CC) $(CFLAGS) main.c -o question5

clean:
	rm question5

format:
	find . -name "*.[ch]" | xargs clang-format -style=Google -i
	
.PHONY: clean format
