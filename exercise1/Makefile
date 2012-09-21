all: exercise1

exercise1: main.c my-student.c my-student.h
	$(CC) -g -o $@ main.c my-student.c -Wall -Werror $(shell pkg-config --cflags --libs gobject-2.0)

clean:
	rm -f exercise1
