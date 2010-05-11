#include "mock.h"
#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>

static gpointer
thread_func (gpointer data)
{
	while (TRUE) {
		g_debug("Iter...");
		mock_do_something();
		mock_do_another();
		g_usleep(G_USEC_PER_SEC / 2);
	}
	return NULL;
}

gint
main (gint   argc,
      gchar *argv[])
{
	void *lib;
	void *sym;

	g_thread_init(NULL);
	mock_init();

	g_thread_create(thread_func, NULL, FALSE, NULL);
	g_print("Press ENTER to load new library.\n");

	while (getc(stdin) != '\n');

	lib = dlopen("libmock-trace.so", RTLD_LAZY);
	g_assert(lib);
	sym = dlsym(lib, "_mock_do_something");
	g_assert(sym);
	g_atomic_pointer_set(&mock_do_something, sym);
	sym = dlsym(lib, "_mock_do_another");
	g_assert(sym);
	g_atomic_pointer_set(&mock_do_another, sym);
	g_debug("Upgraded");

	g_usleep(G_USEC_PER_SEC * 1000);
	return 0;
}
