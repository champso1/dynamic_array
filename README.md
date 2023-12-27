## Dynamic Array in C

This is a small project which was to implement some of the basic features of the C++ std::vector in order to, in essence, create a dynamic array. 

Taking heavy inspiration from [this article](https://solarianprogrammer.com/2017/01/08/c99-c11-dynamic-array-mimics-cpp-vector-api-improvements/), it works as a standard C array, which means that any ordinary C program will be able to read it as if it were a normal array. A block of memory is allocated, and the first few bytes are used for information such as size/length, and a pointer to the first part of memory past this data is returned.

Some nifty preprocessor macros, from which I took inspiration here [this GitHub repo](https://github.com/eignnx/dynarray), allow the type of data to be "passed" as an argument:

`
int *arr = arr_create(int);
`

Data can be added/pushed to this array like so:

`
arr_add_raw(arr, 5);
`
or
`
int num = 5;
arr_add(arr, &num);
`

The size of the allocated memory is doubled each time it's capacity is reached, just like an std::vector.



## Considerations
This is far from a complete project; it only works for primitive types like integers, and does not work with things like pointer arithmetic (incrementing the pointer without subsequenty decrementing it back will break the program). That's all I planned on using it for, but adding support (and safety) for custom types as well as more functionality from the std::vector will be useful.
