#include <assert.h>
#include <string.h>
#include <stdbool.h>
#include "object_pool.h"
#include "object.h"

int main(int argc, char const *argv[])
{
    // should dispose object being returned to the pool if there is no empty slot
    {
        // arrange
        const int POOL_CAPACITY = 1;
        object_t** pool = new_pool(POOL_CAPACITY);
        init_pool(pool, POOL_CAPACITY);

        // act
        object_t* obj1 = get_object(pool, POOL_CAPACITY);
        init_object(obj1, 1, "object1");
        object_t* obj2 = get_object(pool, POOL_CAPACITY);
        init_object(obj2, 2, "object2");

        bool ret1 = return_object(pool, &obj1, POOL_CAPACITY);
        bool ret2 = return_object(pool, &obj2, POOL_CAPACITY);

        // assert
        assert(pool_size(pool, POOL_CAPACITY) == 1);
        assert(obj1 == NULL);
        assert(ret1 == true);
        assert(obj2 == NULL);
        assert(ret2 == false);

        // cleanup
        // obj1 is disposed by the pool
        // obj2 is disposed by return_object call because there is no empty slot
        dispose_pool(pool, POOL_CAPACITY);
    }

    // should return object to the pool for future reuse if there is at least one empty slot
    {
        // arrange
        const int POOL_CAPACITY = 3;
        object_t** pool = new_pool(POOL_CAPACITY);
        init_pool(pool, POOL_CAPACITY);

        // act
        object_t* obj = get_object(pool, POOL_CAPACITY);
        init_object(obj, 1, "object1");
        return_object(pool, &obj, POOL_CAPACITY);

        // assert
        assert(pool_size(pool, POOL_CAPACITY) == 1);
        assert(obj == NULL);

        // cleanup
        // obj1 is disposed by pool
        dispose_pool(pool, POOL_CAPACITY);
    }

    // should be able to initialize newly allocated object
    {
        // arrange
        const int POOL_CAPACITY = 3;
        object_t** pool = new_pool(POOL_CAPACITY);
        init_pool(pool, POOL_CAPACITY);

        // act
        object_t* obj1 = get_object(pool, POOL_CAPACITY);
        init_object(obj1, 1, "object1");

        object_t* obj2 = get_object(pool, POOL_CAPACITY);
        init_object(obj2, 2, "object2");

        // assert
        assert(pool_size(pool, POOL_CAPACITY) == 0);
        assert(strcmp(obj1->hash_code, "object1") == 0);
        assert(obj1->id == 1);
        assert(strcmp(obj2->hash_code, "object2") == 0);
        assert(obj2->id == 2);

        // cleanup
        dispose_object(obj1);
        dispose_object(obj2);
        dispose_pool(pool, POOL_CAPACITY);
    }

    // get_object allocates new object if all slots are empty
    {
        // arrange
        const int POOL_CAPACITY = 3;
        object_t** pool = new_pool(POOL_CAPACITY);
        init_pool(pool, POOL_CAPACITY);

        // act
        object_t* obj = get_object(pool, POOL_CAPACITY);

        // assert
        assert(pool_size(pool, POOL_CAPACITY) == 0);
        assert(obj != NULL);

        // cleanup
        dispose_object(obj);
        dispose_pool(pool, POOL_CAPACITY);
    }

    // should create empty object pool
    {
        const int POOL_CAPACITY = 3;
        object_t** pool = new_pool(POOL_CAPACITY);

        init_pool(pool, POOL_CAPACITY);

        assert(pool_size(pool, POOL_CAPACITY) == 0);
        assert(pool[0] == NULL);
        assert(pool[1] == NULL);
        assert(pool[2] == NULL);

        dispose_pool(pool, POOL_CAPACITY);
    }
    return 0;
}
