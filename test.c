#include "array.c"
#include <stdlib.h>
#include <stdio.h>

int main() {
    int s = 4;
    struct array a = array.new(s, "int");

    *a.at(&a, 0) = 4;
    *a.at(&a, 1) = 3;
    printf("%i\n", a.size);
    a.print(&a);
    *a.at(&a, 2) += 1;
    printf("%i\n", *a.at(&a, 2));
    
    a.push_back(&a, 5);
    a.print(&a);
    a.pop_back(&a);
    a.print(&a);

    a.insert(&a, 2, 10);
    a.print(&a);
    a.pop(&a, 2);
    a.print(&a);

    printf("bitsize of struct array\t%i\n", sizeof(a));
    printf("size of array\t%i\n", a.size);
    printf("bitsize of array\t%i\n", sizeof(a.ptr));
    printf("bitsize of element\t%i\n", sizeof(*a.at(&a,0)));
    printf("bitsize of int\t%i\n", sizeof(int));
    free(a.ptr);

    // struct array af = array.new(3, "float");
    

    return 0;
}