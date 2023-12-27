#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef enum {
    LENGTH,
    STRIDE,
    CAPACITY,
    NUM_PROPERTIES
} Header;

/*
arr[0] = length;
arr[1] = stride;
arr[2] = capacity
what is returned is &arr[3]
*/


static size_t arr_len(void *arr) {
    return ((size_t *)arr - NUM_PROPERTIES)[LENGTH];
}
static size_t arr_cap(void *arr) {
    return ((size_t *)arr - NUM_PROPERTIES)[CAPACITY];
}
static size_t arr_stride(void *arr) {
    return ((size_t *)arr - NUM_PROPERTIES)[STRIDE];
}


extern void  *_arr_create(size_t stride);
extern void  *_arr_add(void *arr, void *num);

#define arr_create(type) _arr_create(sizeof(type))
#define arr_delete(arr) free(((size_t *)arr) - NUM_PROPERTIES)                             
#define arr_add_raw(arr, num)       \
    do {                            \
        __auto_type temp = num;   \
        arr = _arr_add(arr, &temp);  \
    } while (0)
#define arr_add(arr, num)           \
    do {                            \
        arr = _arr_add(arr, &num);  \
    } while(0)