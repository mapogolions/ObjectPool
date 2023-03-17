#include <stdlib.h>
#include <string.h>
#include "./object.h"

object_t* new_object()
{
    object_t* obj = (object_t*) malloc(sizeof(object_t));
    return obj;
}

object_t* init_object(object_t* obj, unsigned int id, const char* hash_code)
{
    if (obj->hash_code != NULL)
    {
        free(obj->hash_code);
    }
    obj->hash_code = (char*) malloc(strlen(hash_code) + 1);
    strcpy(obj->hash_code, hash_code);
    obj->id = id;
    return obj;
}

void dispose_object(object_t* obj)
{
    free(obj->hash_code);
    free(obj);
}
