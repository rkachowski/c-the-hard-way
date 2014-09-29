#ifndef __queue_h_
#define __queue_h_

#include <lcthw/list.h>

typedef List Queue;

#define Queue_create List_create

#define Queue_destroy List_destroy

#define Queue_send List_unshift

#define Queue_recv List_pop

#define Queue_count List_count

#define QUEUE_FOREACH(V, M) LIST_FOREACH(V, first, next, M)
#define Queue_peek List_last

#endif
