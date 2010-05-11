#ifndef __MOCK_H__
#define __MOCK_H__

#include <glib.h>

#define UPGRADEABLE(_t, _n) _t (*_n)

UPGRADEABLE(void, mock_do_something) (void);
UPGRADEABLE(void, mock_do_another)   (void);
void mock_init (void);

#endif /* __MOCK_H__ */
