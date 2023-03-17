#ifndef _OBJECT_POOL_H_
#define _OBJECT_POOL_H_

#include <stdbool.h>
#include "./object.h"

object_t** new_pool(int capacity);
object_t** init_pool(object_t** pool, int capacity);
int pool_size(object_t** pool, int capacity);
object_t* get_object(object_t** pool, int capacity);
bool return_object(object_t** pool, object_t** obj, int capacity);
void dispose_pool(object_t** pool, int capacity);

#endif // _OBJECT_POOL_H_
