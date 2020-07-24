#include <stdint.h>

typedef struct intarray intarray;
struct intarray {
    int32_t* array;
    int size;
};

int32_t* add_int(int32_t* a, int32_t* b, int size);