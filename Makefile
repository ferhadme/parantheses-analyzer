CC = clang
CFLAGS = -Wall -Wextra -std=c11 -pedantic

run: compile
	./pa

compile:
	$(CC) $(CFLAGS) -o pa pa.c pstack.c
