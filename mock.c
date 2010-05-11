#include "mock.h"

#define TRACE g_debug("%s():%d", G_STRFUNC, __LINE__)

void
_mock_do_something (void)
{
#ifndef DISABLE_TRACE
	TRACE;
#endif
}

void
_mock_do_another (void)
{
#ifndef DISABLE_TRACE
	TRACE;
#endif
}

void
mock_init (void)
{
	mock_do_something = _mock_do_something;
	mock_do_another = _mock_do_another;
}
