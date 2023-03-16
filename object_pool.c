#include <stdlib.h>
#include <string.h>
#include "./object.h"

object_t** new_pool(int capacity)
{
    if (capacity < 0) return NULL;
    object_t** pool = (object_t**) malloc(sizeof(object_t*) * capacity);
    return pool;
}

object_t** init_pool(object_t** pool, int capacity)
{
    for (int i = 0; i < capacity; i++)
    {
        *(pool + i) = NULL;
    }
    return pool;
}

int pool_size(object_t** pool, int capacity)
{
    int n = 0;
    for (int i = 0; i < capacity; i++)
    {
        object_t* obj = *(pool + i);
        if (obj != NULL) n++;
    }
    return n;
}

object_t* get_object(object_t** pool, int capacity)
{
    for (int i = 0; i < capacity; i++)
    {
        object_t* obj = *(pool + i);
        if (obj != NULL) return obj;
    }
    return new_object();
}

void return_object(object_t** pool, object_t* obj, int capacity)
{
    for (int i = 0; i < capacity; i++)
    {
        if (*(pool + i) == NULL)
        {
            *(pool + i) = obj;
            return;
        }
    }
    dispose_object(obj);
}

void dispose_pool(object_t** pool, int capacity)
{
    for (int i = 0; i < capacity; i++)
    {
        object_t* obj = *(pool + i);
        if (obj == NULL) continue;
        dispose_object(obj);
    }
    free(pool);
}
