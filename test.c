#include "array.c"
#include <stdlib.h>
#include <stdio.h>

int main() {
    int s = 4;
    struct array a = array.new(s, "int");

    *a.at(&a, 0) = 4;
    *a.at(&a, 1) = 3;
    printf("%i\n", a.size);
    array.print(&a);
    array.push_back(&a, 100);
    array.print(&a);

    printf("\n");
    printf("bitsize of struct array\t%i\n", sizeof(a));
    printf("size of array\t%i\n", a.size);
    printf("bitsize of array\t%i\n", sizeof(a.ptr));
    printf("bitsize of element\t%i\n", sizeof(*a.at(&a,0)));
    printf("bitsize of int\t%i\n", sizeof(int));
    free(a.ptr);

    // struct array af = array.new(3, "float");
    

    return 0;
}