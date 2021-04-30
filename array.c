#include "array.h"
#include <stdlib.h>
#include <stdio.h>

// Current implementation is fully functional for most use of int and float arrays. Only really missing generalizing at in such a way that I won't need (type*)at

/*
One method for creating a generic is to write function pointers inside the array struct. 
However, this only permits generic void functions with same-type variables.
For the sake of cleanliness and maximum functionality, this more quasi OOP method was depreciated for a more function driven method.
Under this, an explanation of function driven advantages.
The greatest disadvantage of this method is that it contaminates 'main' with various functions that only work for this data type, which could had been easily segregrated with a OOP friendly programming language.
*/

/* 
_Generic permits functions with different return types IF AND ONLY IF the function variables given have different types.
void functions that have the same types for variables can me made generic by using a switch-case function and array member variable 'type'.
No method has been found to make generic functions for functions with different return types but same variable types. (e.g at or sum).
*/
int* at(struct array *this, unsigned int pos) {
    if (pos < 0 || pos >= this->size) {
        printf("ERROR: out of range");
    }
    return (this->ptr + pos*sizeof(int));    
}
float* at_f(struct array *this, unsigned int pos) {
    if (pos < 0 || pos >= this->size) {
        printf("ERROR: out of range");
    }
    return (this->ptr + pos*sizeof(float));   
}
//-----------------------------------------------------
static int sum(struct array *this) {
    int s = 0;
    for (int i = 0; i < this->size; i++) {s += *(int*)(this->ptr + i*sizeof(int));}
    return s;
}
static float sum_f(struct array *this) {
    float s = 0;
    for (int i = 0; i < this->size; i++) {s += *at_f(this, i);}
    return s;
}
//----------------------------------------------------------------
void print(struct array *this) {
    switch (this->type) {
        case INT:
            for (int i = 0; i < this->size; i++) {printf("%i\t", *at(this, i));}
            break;
        case FLOAT:
            for (int i = 0; i < this->size; i++) {printf("%f\t", *at_f(this, i));}
            break;
        default: printf("Type not supported\n");
    }
    printf("\n");
}
//----------------------------------------------------------------------
void reallocate_array_size(struct array *this) {
    switch (this->type) {
        case INT: this->ptr = (int*) realloc(this->ptr, this->size * sizeof(int)); break;
        case FLOAT: this->ptr = (float*) realloc(this->ptr, this->size * sizeof(float)); break;
        default: printf("Type not supported\n");
    }
}
//-------------------------------------------------------------------------
void push_back_i(struct array *this, int n) {
    this->size += 1;
    reallocate_array_size(this);
    *at(this, this->size - 1) = n;
}
void push_back_f(struct array *this, float n) {
    this->size += 1;
    reallocate_array_size(this);
    *at_f(this, this->size - 1) = n;
}
#define push_back(ARR, N) _Generic((N), int: push_back_i, float: push_back_f)(ARR, N)
//--------------------------------------------------------------------------
void pop_back(struct array *this) {
    if (this->size > 0) {
        this->size -= 1;
        reallocate_array_size(this);    
    }
    else {printf("Array is empty\n");}
}
//-------------------------------------------------------------------------------
void insert_i(struct array *this, unsigned int index, int n) {
    if (index >= this->size) {
        printf("ERROR: out of range");
    }
    else {
        this->size += 1;
        reallocate_array_size(this);       
        for (int i = this->size - 1; i >= index; i--) {
            if (i == index) {
                *at(this, index) = n;
            }
            else {
                *at(this, i) = *at(this, i - 1);
            }
        }
    }
}
void insert_f(struct array *this, unsigned int index, float n) {
    if (index >= this->size) {
        printf("ERROR: out of range");
    }
    else {
        this->size += 1;
        reallocate_array_size(this);     
        for (int i = this->size - 1; i >= index; i--) {
            if (i == index) {
                *at(this, index) = n;
            }
            else {
                *at(this, i) = *at(this, i - 1);
            }
        }
    }
}
#define insert(ARR, INDEX, N) _Generic((N), int: insert_i, float: insert_f)(ARR, INDEX, N)
//-------------------------------------------------------------------------------------
void pop(struct array *this, unsigned int index) {
    if (index >= this->size) {
        printf("ERROR: out of range\n");
    }
    else if (this->size == 0) {
        printf("ERROR: array empty\n");
    }
    else {             
        for (int i = index; i < this->size - 1; i++) { 
            *at(this, i) = *at(this, i + 1);
        }
        this->size -= 1;
        reallocate_array_size(this);        
    } 
}
//--------------------------------------------------------------------------------
static struct array new_array(unsigned int arrsize, char* type) {
    if (type == "int") {
        return (struct array){
            .ptr=(int*)calloc(arrsize, sizeof(int)), 
            .size=arrsize,  
            .type=INT
        };
    }
    else if (type == "float") {
        return (struct array){
            .ptr=(float*)calloc(arrsize, sizeof(float)), 
            .size=arrsize, 
            .type=FLOAT
        };
    }
}
const struct arrayClass array={.new=&new};