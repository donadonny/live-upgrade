all: libmock.so libmock-trace.so main

libmock.so: mock.c
	$(CC) -g -o $@ -fPIC -shared mock.c -Wall -Werror $(shell pkg-config --libs --cflags glib-2.0) -DDISABLE_TRACE=1

libmock-trace.so: mock.c
	$(CC) -g -o $@ -fPIC -shared mock.c -Wall -Werror $(shell pkg-config --libs --cflags glib-2.0)

main: main.c
	$(CC) -g -o $@ main.c -Wall -Werror $(shell pkg-config --libs --cflags glib-2.0 gthread-2.0) -L. -lmock -ldl

clean:
	rm -rf libmock.so libmock-trace.so main
