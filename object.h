#ifndef _OBJECT_H_
#define _OBJECT_H_

typedef struct object
{
    unsigned int id;
    char* hash_code;
} object_t;


object_t* new_object();
object_t* init_object(object_t* obj, unsigned int id, const char* hash_code);
void dispose_object(object_t* obj);

#endif
