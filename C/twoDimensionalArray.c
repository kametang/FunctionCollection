#include <stdlib.h>

void ** twoDA(int row, int col, int size)
{
    void **array;
    void *p;
    int i;
    array = (void**)malloc((row+1)*8+row*col*size);
    for(i = 0, p = (void*)(array+row+1); i < row; i++, p += col)
        array[i] = p;
    array[i] = 0;
    return array;
}