#include "array.h"
#include <stdlib.h>
#include <stdio.h>

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
static int sum(struct array *this) {
    int s = 0;
    for (int i = 0; i < this->size; i++) {s += *at(this, i);}
    return s;
}
static float sum_f(struct array *this) {
    float s = 0;
    for (int i = 0; i < this->size; i++) {s += *at_f(this, i);}
    return s;
}
void print(struct array *this) {
    for (int i = 0; i < this->size; i++) {printf("%i\t", *at(this, i));}
    printf("\n");
}
void print_f(struct array *this) {
    for (int i = 0; i < this->size; i++) {printf("%f\t", *at_f(this, i));}
    printf("\n");
}
void push_back(struct array *this, int n) {
    this->size += 1;
    this->ptr = (int*) realloc(this->ptr, this->size * sizeof(int));
    *this->at(this, this->size - 1) = n;
}
void push_back_f(struct array *this, float n) {
    this->size += 1;
    this->ptr = (float*) realloc(this->ptr, this->size * sizeof(float));
    *at_f(this, this->size - 1) = n;
}
void pop_back(struct array *this) {
    this->size -= 1;
    this->ptr = (int*) realloc(this->ptr, this->size * sizeof(int));
}
void pop_back_f(struct array *this) {
    this->size -= 1;
    this->ptr = (float*) realloc(this->ptr, this->size * sizeof(float));
}
void insert(struct array *this, unsigned int index, int n) {
    if (index >= this->size) {
        printf("ERROR: out of range");
    }
    else {
        this->size += 1;
        this->ptr = (int*) realloc(this->ptr, this->size * sizeof(int));        
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
        this->ptr = (float*) realloc(this->ptr, this->size * sizeof(float));        
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
void pop(struct array *this, unsigned int index) {
    if (index >= this->size) {
        printf("ERROR: out of range");
    }
    else {             
        for (int i = index; i < this->size - 1; i++) { 
            *at(this, i) = *at(this, i + 1);
        }
        this->size -= 1;
        this->ptr = (int*) realloc(this->ptr, this->size * sizeof(int));
    } 
}
void pop_f(struct array *this, unsigned int index) {
    if (index >= this->size) {
        printf("ERROR: out of range");
    }
    else {             
        for (int i = index; i < this->size - 1; i++) { 
            *at(this, i) = *at(this, i + 1);
        }
        this->size -= 1;
        this->ptr = (float*) realloc(this->ptr, this->size * sizeof(float));
    } 
}

static struct array new(unsigned int arrsize, char* type) {
    if (type == "int") {
        return (struct array){.ptr=(int*)calloc(arrsize, sizeof(int)), .size=arrsize,  .at=at};
    }
    else if (type == "float") {
        return (struct array){.ptr=(float*)calloc(arrsize, sizeof(float)), .size=arrsize, .at=at_f};
    }
    
}
const struct arrayClass array={.new=&new, .print=print,  .at=at, .push_back=push_back, .pop_back=pop_back, .insert=insert, .pop=pop, .sum=sum, .print_f=print_f, .at=at_f, .push_back_f=push_back_f, .pop_back=pop_back_f, .insert_f=insert_f, .pop=pop_f, .sumf=sum_f, .at_f=at_f};