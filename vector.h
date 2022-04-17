#ifndef VECTOR_H
#define VECTOR_H

#include <stddef.h>
#include <string.h> // strok, strlen
#include <stdio.h> // puts 
#include <stdlib.h> // malloc
#include <stdbool.h> // bool


typedef char* string;

typedef enum {STRING, INT, FLOAT, BOOL} DataType;
typedef struct vector {
	size_t size;
	DataType type;
	void* ptr;
} vector;


// init
vector new_string_vector(string* strarr, size_t size); 
vector new_int_vector(int* arr, size_t size);
vector new_flt_vector(float* arr, size_t size);
vector new_bool_vector(bool* arr, size_t size);
#define new_vector(arr, size) _Generic(arr, string*: new_string_vector, int*: new_int_vector, float*: new_flt_vector, bool*: new_bool_vector)(arr, size)


void* as_ptr(vector v, size_t* rsize);

// get
void get_string(vector arr, size_t i, string* rval);
void get_int(vector arr, size_t i, int* rval);
void get_float(vector arr, size_t i, float* rval);
void get_bool(vector arr, size_t i, bool* rval);
#define get(vector, i, ret) _Generic(ret, string*: get_string, int*: get_int, float*: get_float, bool*: get_bool)(vector, i, ret)

// at
void at_string(vector arr, size_t i, string** rptr);
void at_int(vector arr, size_t i, int** rptr);
void at_float(vector arr, size_t i, float** rptr);
void at_bool(vector arr, size_t i, bool** rptr);
#define at(v, i, ret) _Generic(ret, string**: at_string, int**: at_int, float**: at_float, bool**: at_bool)(v, i, ret)

void realloc_vector(vector *arr);
// Reserve additional capacityIn C++, it
void reserve(vector *arr, size_t n);
// lowers size of vector
void truncate(vector* arr, size_t len);


// resize
void _resize_null(vector *arr, size_t size, void* null);
void resize_string(vector* arr, size_t size, string val);
void resize_int(vector* arr, size_t size, int val);
void resize_flt(vector* arr, size_t size, float val);
void resize_bool(vector* arr, size_t size, bool val);
#define resize(vector, size, val) _Generic(val, string: resize_string, int: resize_int, float: resize_flt, bool: resize_bool, void*: _resize_null)(vector, size, val)


// pop
void pop_string(vector* arr, string* rval);
void pop_int(vector* arr, int* rval);
void pop_flt(vector* arr, float* rval);
void pop_bool(vector* arr, bool* rval);
#define pop(vector, ret) _Generic(ret, string*: pop_string, int*: pop_int, float*: pop_flt, bool*: pop_bool)(vector, ret)


// push
void push_string(vector* arr, string val);
void push_int(vector* arr, int val);
void push_flt(vector* arr, float val);
void push_bool(vector* arr, bool val);
#define push(vector, val) _Generic(val, string: push_string, int: push_int, float: push_flt, bool: push_bool)(vector, val)


// append
void append(vector* arr, vector arr1);
// clear 
void clear(vector* arr);
bool is_empty(vector arr);


// insert
void insert_string(vector* arr, const int pos, string val);
void insert_int(vector* arr, int pos, int val);
void insert_flt(vector* arr, int pos, float val);
void insert_bool(vector* arr, int pos, bool val);
#define insert(vector, i, val) _Generic(val, string: insert_string, int: insert_int, float: insert_flt, bool: insert_bool)(vector, i, val)


// remove
void remove_string(vector* arr, const int pos, string* rval);
void remove_int(vector* arr, int pos, int* rval);
void remove_flt(vector* arr, int pos, float* rval);
void remove_bool(vector* arr, int pos, bool* rval);
#define remove(vector, i, rval) _Generic(rval, string*: remove_string, int*: remove_int, float*: remove_flt, bool*: remove_bool)(vector, i, rval)


// filter
vector filter_string(vector arr, bool (*f)(string));
vector filter_int(vector arr, bool (*f)(int));
vector filter_flt(vector arr, bool (*f)(float));
vector filter_bool(vector arr, bool (*f)(bool));
#define filter(vector, f) _Generic(f, bool(*)(string): filter_string, bool(*)(int): filter_int, bool(*)(float): filter_flt, bool(*)(bool): filter_bool)(vector, f)


// map
void map_string(vector* arr, void (*f)(string*));
void map_int(vector* arr, void (*f)(int*));
void map_float(vector* arr, void (*f)(float*));
void map_bool(vector* arr, void (*f)(bool*));
#define map(vector, f) _Generic(f, void(*)(string*): map_string, void(*)(int*): map_int, void(*)(float*): map_float, void(*)(bool*): map_bool)(vector, f)


vector split_off(vector* arr, size_t at);


// contains
bool contains_string(vector arr, const string val);
bool contains_int(vector arr, int val);
bool contains_float(vector arr, float val);
bool contains_bool(vector arr, bool val);
#define contains(vector, val) _Generic(val, string: contains_string, int: contains_int, float: contains_float, bool: contains_bool)(vector, val)


// fill
void fill_string(vector* arr, const string val);
void fill_int(vector* arr, int val);
void fill_float(vector* arr, float val);
void fill_bool(vector* arr, bool val);
#define fill(vector, val) _Generic(val, string: fill_string, int: fill_int, float: fill_float, bool: fill_bool)(vector, val)


void print(vector arr);
void println(vector arr);


#endif
