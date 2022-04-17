#ifndef VECTOR_H
#define VECTOR_H

#include <stddef.h>
#include <string.h> // strok, strlen
#include <stdio.h> // puts 
#include <stdlib.h> // malloc
#include <stdbool.h> // bool


typedef enum {STRING, INT, FLOAT, BOOL} DataType;
struct vector {
	size_t size;
	DataType type;
	void* ptr;
};


// init
struct vector new_string_vector(char** strarr, size_t size); 
struct vector new_int_vector(int* arr, size_t size);
struct vector new_flt_vector(float* arr, size_t size);
struct vector new_bool_vector(bool* arr, size_t size);
#define new_vector(arr, size) _Generic(arr, char**: new_string_vector, int*: new_int_vector, float*: new_flt_vector, bool*: new_bool_vector)(arr, size)



void* as_ptr(struct vector v, size_t* rsize);

// get
void get_string(struct vector arr, size_t i, char** return_val);
void get_int(struct vector arr, size_t i, int* return_val);
void get_float(struct vector arr, size_t i, float* return_val);
void get_bool(struct vector arr, size_t i, bool* return_val);
#define get(vector, i, ret) _Generic(ret, char**: get_string, int*: get_int, float*: get_float, bool*: get_bool)(vector, i, ret)


void realloc_vector(struct vector *arr);
// Reserve additional capacity
void reserve(struct vector *arr, size_t n);
// lowers size of vector
void truncate(struct vector* arr, size_t len);


// resize
void resize_string(struct vector* arr, size_t size, char* val);
void resize_int(struct vector* arr, size_t size, int val);
void resize_flt(struct vector* arr, size_t size, float val);
void resize_bool(struct vector* arr, size_t size, bool val);
#define resize(vector, size, val) _Generic(val, char*: resize_string, int: resize_int, float: resize_flt, bool: resize_bool)(vector, size, val)


// pop
void pop_string(struct vector* arr, char** rval);
void pop_int(struct vector* arr, int* rval);
void pop_flt(struct vector* arr, float* rval);
void pop_bool(struct vector* arr, bool* rval);
#define pop(vector, ret) _Generic(ret, char**: pop_string, int*: pop_int, float*: pop_flt, bool*: pop_bool)(vector, ret)


// push
void push_string(struct vector* arr, char* val);
void push_int(struct vector* arr, int val);
void push_flt(struct vector* arr, float val);
void push_bool(struct vector* arr, bool val);
#define push(vector, val) _Generic(val, char*: push_string, int: push_int, float: push_flt, bool: push_bool)(vector, val)


// append
void append(struct vector* arr, struct vector arr1);
// clear 
void clear(struct vector* arr);
bool is_empty(struct vector arr);


// insert
void insert_string(struct vector* arr, const int pos, char* val);
void insert_int(struct vector* arr, int pos, int val);
void insert_flt(struct vector* arr, int pos, float val);
void insert_bool(struct vector* arr, int pos, bool val);
#define insert(vector, i, val) _Generic(val, char*: insert_string, int: insert_int, float: insert_flt, bool: insert_bool)(vector, i, val)


// remove
void remove_string(struct vector* arr, const int pos, char** rval);
void remove_int(struct vector* arr, int pos, int* rval);
void remove_flt(struct vector* arr, int pos, float* rval);
void remove_bool(struct vector* arr, int pos, bool* rval);
#define remove(vector, i, rval) _Generic(rval, char**: remove_string, int*: remove_int, float*: remove_flt, bool*: remove_bool)(vector, i, rval)


// filter
struct vector filter_string(struct vector arr, bool (*f)(char*));
struct vector filter_int(struct vector arr, bool (*f)(int));
struct vector filter_flt(struct vector arr, bool (*f)(float));
struct vector filter_bool(struct vector arr, bool (*f)(bool));
#define filter(vector, f) _Generic(f, bool(*)(char*): filter_string, bool(*)(int): filter_int, bool(*)(float): filter_flt, bool(*)(bool): filter_bool)(vector, f)


// map
void map_string(struct vector* arr, void (*f)(char**));
void map_int(struct vector* arr, void (*f)(int*));
void map_float(struct vector* arr, void (*f)(float*));
void map_bool(struct vector* arr, void (*f)(bool*));
#define map(vector, f) _Generic(f, void(*)(char**): map_string, void(*)(int*): map_int, void(*)(float*): map_float, void(*)(bool*): map_bool)(vector, f)


struct vector split_off(struct vector* arr, size_t at);


// contains
bool contains_string(struct vector arr, const char* val);
bool contains_int(struct vector arr, int val);
bool contains_float(struct vector arr, float val);
bool contains_bool(struct vector arr, bool val);
#define contains(vector, val) _Generic(val, char*: contains_string, int: contains_int, float: contains_float, bool: contains_bool)(vector, val)


// fill
void fill_string(struct vector* arr, const char* val);
void fill_int(struct vector* arr, int val);
void fill_float(struct vector* arr, float val);
void fill_bool(struct vector* arr, bool val);
#define fill(vector, val) _Generic(val, char*: fill_string, int: fill_int, float: fill_float, bool: fill_bool)(vector, val)

void print(struct vector arr);
void println(struct vector arr);


#endif
