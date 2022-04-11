CC = clang
CFLAGS = -Wall -Wextra -std=c11 -pedantic

compile:
	$(CC) $(CFLAGS) -o pa pa.c pstack.c

run: compile
	./pa
