#include "array.c"
#include <stdlib.h>
#include <stdio.h>



int main() {
    int s = 5;
    struct array a = new_array(s, "int");

    *at(&a, 0) = 4;
    *at(&a, 1) = 3;
    printf("%i\n", a.size);
    print(&a);
    push_back(&a, 100);
    print(&a);

    printf("\n");
    printf("bitsize of struct array\t%i\n", sizeof(a));
    printf("size of array\t%i\n", a.size);
    printf("bitsize of array\t%i\n", sizeof(a.ptr));
    printf("bitsize of element\t%i\n", sizeof(*at(&a,0)));
    printf("bitsize of int\t%i\n", sizeof(int));
    printf("testing:\t%d\n", *(int*)a);
    free(a.ptr);
    float t = 3.0;
    

    // struct array af = array.new(3, "float");
    

    return 0;
}