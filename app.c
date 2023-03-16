#include <assert.h>
#include "./object_pool.h"
#include "./object.h"

int main(int argc, char const *argv[])
{
    const int POOL_CAPACITY = 3;
    object_t** pool = new_pool(POOL_CAPACITY);
    init_pool(pool, POOL_CAPACITY);
    assert(pool_size(pool, POOL_CAPACITY) == 0);

    object_t* obj1 = get_object(pool, POOL_CAPACITY);
    init_object(obj1, 1, "object1");
    assert(pool_size(pool, POOL_CAPACITY) == 0);

    return_object(pool, obj1, POOL_CAPACITY);
    assert(pool_size(pool, POOL_CAPACITY) == 1);

    dispose_pool(pool, POOL_CAPACITY);
    return 0;
}
