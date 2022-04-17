#include "vector.h"
#include <stddef.h>


// init
vector new_string_vector(string* arr, size_t size) {
	string* ptr = (string*)malloc(size * sizeof(string)); 
	for (int i = 0; i < size; i++) {
		ptr[i] = (string)malloc(strlen(arr[i]) * sizeof(char));
		strcpy(ptr[i], arr[i]);
	}
	return (vector) {
		.ptr = ptr,
		.size = size,
		.type = STRING,
	};
}
vector new_int_vector(int* arr, size_t size) {
	int* ptr = (int*)malloc(size * sizeof(int)); 
	for (int i = 0; i < size; i++) {
		ptr[i] = arr[i];
	}
	return (vector) {
		.ptr = ptr,
		.size = size,
		.type = INT,
	};
}
vector new_flt_vector(float* arr, size_t size) {
	float* ptr = (float*)malloc(size * sizeof(float)); 
	for (int i = 0; i < size; i++) {
		ptr[i] = arr[i];
	}
	return (vector) {
		.ptr = ptr,
		.size = size,
		.type = FLOAT,
	};
}
vector new_bool_vector(bool* arr, size_t size) {
	bool* ptr = (bool*)malloc(size * sizeof(bool)); 
	for (int i = 0; i < size; i++) {
		ptr[i] = arr[i];
	}
	return (vector) {
		.ptr = ptr,
		.size = size,
		.type = BOOL,
	};
}


void* as_ptr(vector v, size_t* rsize) {
	*rsize = v.size;
	return v.ptr;
}

// get
void get_string(vector arr, size_t i, string* rval) {
	if (i < 0 || i >= arr.size) {puts("out of bounds");}
	if (arr.type != STRING) {puts("wrong type");}
	*rval = ((string*)arr.ptr)[i];
}
void get_int(vector arr, size_t i, int* rval) {
	if (i < 0 || i >= arr.size) {puts("out of bounds");}
	if (arr.type != INT) {puts("wrong type");}
	*rval = ((int*) arr.ptr)[i];
}
void get_float(vector arr, size_t i, float* rval) {
	if (i < 0 || i >= arr.size) {puts("out of bounds");}
	if (arr.type != FLOAT) {puts("wrong type");}
	*rval = ((float*) arr.ptr)[i];
}
void get_bool(vector arr, size_t i, bool* rval) {
	if (i < 0 || i >= arr.size) {puts("out of bounds");}
	if (arr.type != BOOL) {puts("wrong type");}
	*rval = ((bool*) arr.ptr)[i];
}


// at
void at_string(vector arr, size_t i, string** rptr) {
	if (i < 0 || i >= arr.size) {puts("out of bounds");}
	if (arr.type != STRING) {puts("wrong type");}
	*rptr = &((string*)arr.ptr)[i];
}
void at_int(vector arr, size_t i, int** rptr) {
	if (i < 0 || i >= arr.size) {puts("out of bounds");}
	if (arr.type != INT) {puts("wrong type");}
	*rptr = &((int*) arr.ptr)[i];
}
void at_float(vector arr, size_t i, float** rptr) {
	if (i < 0 || i >= arr.size) {puts("out of bounds");}
	if (arr.type != FLOAT) {puts("wrong type");}
	*rptr = &((float*) arr.ptr)[i];
}
void at_bool(vector arr, size_t i, bool** rptr) {
	if (i < 0 || i >= arr.size) {puts("out of bounds");}
	if (arr.type != BOOL) {puts("wrong type");}
	*rptr = &((bool*) arr.ptr)[i];
}

void realloc_vector(vector *this) {
    switch (this->type) {
        case STRING: this->ptr = (string*) realloc(this->ptr, this->size * sizeof(string)); break;
        case INT: this->ptr = (int*) realloc(this->ptr, this->size * sizeof(int)); break;
        case FLOAT: this->ptr = (float*) realloc(this->ptr, this->size * sizeof(float)); break;
        case BOOL: this->ptr = (bool*) realloc(this->ptr, this->size * sizeof(bool)); break;
        default: puts("Type not supported");
    }
}


// Reserve additional capacity
void reserve(vector *arr, size_t n) {
	arr->size += n;
	realloc_vector(arr);
}


// resize
void truncate(vector* arr, size_t len) {
	if (len < arr->size) {
		arr->size = len;
		realloc_vector(arr);
	}

}


// resize
void _resize_null(vector *arr, size_t size, void* null) {
	arr->size = size;
	realloc_vector(arr);
}
void resize_string(vector* arr, size_t size, string val) {
	if (arr->type != STRING) {puts("wrong type");}
	bool bigger = (size > arr->size);
	size_t prev_size = arr->size;
	arr->size = size;
	realloc_vector(arr);
	if (bigger){
		for (int i = prev_size; i < arr->size; i++) {
			((string*) arr->ptr)[i] = val;
		}
	}
}
void resize_int(vector* arr, size_t size, int val) {
	if (arr->type != INT) {puts("wrong type");}
	bool bigger = (size > arr->size);
	size_t prev_size = arr->size;
	arr->size = size;
	realloc_vector(arr);
	if (bigger){
		for (int i = prev_size; i < arr->size; i++) {
			((int*) arr->ptr)[i] = val;
		}
	}
}
void resize_flt(vector* arr, size_t size, float val) {
	if (arr->type != FLOAT) {puts("wrong type");}
	bool bigger = (size > arr->size);
	size_t prev_size = arr->size;
	arr->size = size;
	realloc_vector(arr);
	if (bigger){
		for (int i = prev_size; i < arr->size; i++) {
			((float*) arr->ptr)[i] = val;
		}
	}
}
void resize_bool(vector* arr, size_t size, bool val) {
	if (arr->type != BOOL) {puts("wrong type");}
	bool bigger = (size > arr->size);
	size_t prev_size = arr->size;
	arr->size = size;
	realloc_vector(arr);
	if (bigger){
		for (int i = prev_size; i < arr->size; i++) {
			((bool*) arr->ptr)[i] = val;
		}
	}
}


// pop
void pop_string(vector* arr, string* rval) {
	if (arr->type != STRING) {puts("wrong type");}
	*rval = ((string*) arr->ptr)[arr->size-1];
	arr->size--;
	realloc_vector(arr);
}
void pop_int(vector* arr, int* rval) {
	if (arr->type != INT) {puts("wrong type");}
	*rval = ((int*) arr->ptr)[arr->size-1];
	arr->size--;
	realloc_vector(arr);
}
void pop_flt(vector* arr, float* rval) {
	if (arr->type != FLOAT) {puts("wrong type");}
	*rval = ((float*) arr->ptr)[arr->size-1];
	arr->size--;
	realloc_vector(arr);
}
void pop_bool(vector* arr, bool* rval) {
	if (arr->type != BOOL) {puts("wrong type");}
	*rval = ((bool*) arr->ptr)[arr->size-1];
	arr->size--;
	realloc_vector(arr);
}


// push
void push_string(vector* arr, string val) {
	if (arr->type != STRING) {puts("wrong type");}
	arr->size++;
	realloc_vector(arr);
	((string*) arr->ptr)[arr->size-1] = val;
}
void push_int(vector* arr, int val) {
	if (arr->type != INT) {puts("wrong type");}
	arr->size++;
	realloc_vector(arr);
	((int*) arr->ptr)[arr->size-1] = val;
}
void push_flt(vector* arr, float val) {
	if (arr->type != FLOAT) {puts("wrong type");}
	arr->size++;
	realloc_vector(arr);
	((float*) arr->ptr)[arr->size-1] = val;
}
void push_bool(vector* arr, bool val) {
	if (arr->type != BOOL) {puts("wrong type");}
	arr->size++;
	realloc_vector(arr);
	((float*) arr->ptr)[arr->size-1] = val;
}


// consumes the latter vector
void append(vector* this, vector arr) {
	if (this->type != arr.type) {puts("vector are different types");}
	size_t pos = this->size;
	this->size += arr.size;
	realloc_vector(this);
	for (size_t i = 0; i < arr.size; i++) {
	    switch (this->type) {
			case STRING: strcpy(((string*) this->ptr)[pos+i], ((string*) arr.ptr)[i]); break;
			case INT: ((int*) this->ptr)[pos+i] = ((int*) arr.ptr)[i]; break;
			case FLOAT: ((float*) this->ptr)[pos+i] = ((float*) arr.ptr)[i]; break;
			case BOOL:  ((bool*) this->ptr)[pos+i] = ((bool*) arr.ptr)[i]; break;
			default: puts("Type not supported");
		}	
	}
}

// clear 
void clear(vector* arr) {
	arr->size = 0;
	realloc_vector(arr);
}

bool is_empty(vector arr) {
	return arr.size == 0;
}


// insert
void insert_string(vector* arr, const int pos, string val) {
	if (pos < 0 || pos >= arr->size) {puts("out of bounds");}
	if (arr->type != STRING) {puts("wrong type");}
	arr->size++;
	realloc_vector(arr);
	for (size_t i = arr->size-1; i > pos; i--) {
		((string*) arr->ptr)[i] = ((string*) arr->ptr)[i-1];
	}
	((string*) arr->ptr)[pos] = val;
}
void insert_int(vector* arr, int pos, int val) {
	if (pos < 0 || pos >= arr->size) {puts("out of bounds");}
	if (arr->type != INT) {puts("wrong type");}
	arr->size++;
	realloc_vector(arr);
	for (size_t i = arr->size-1; i > pos; i--) {
		((int*) arr->ptr)[i] = ((int*) arr->ptr)[i-1];
	}
	((int*) arr->ptr)[pos] = val;
}
void insert_flt(vector* arr, int pos, float val) {
	if (pos < 0 || pos >= arr->size) {puts("out of bounds");}
	if (arr->type != FLOAT) {puts("wrong type");}
	arr->size++;
	realloc_vector(arr);
	for (size_t i = arr->size-1; i > pos; i--) {
		((float*) arr->ptr)[i] = ((float*) arr->ptr)[i-1];
	}
	((float*) arr->ptr)[pos] = val;
}
void insert_bool(vector* arr, int pos, bool val) {
	if (pos < 0 || pos >= arr->size) {puts("out of bounds");}
	if (arr->type != BOOL) {puts("wrong type");}
	arr->size++;
	realloc_vector(arr);
	for (size_t i = arr->size-1; i > pos; i--) {
		((bool*) arr->ptr)[i] = ((bool*) arr->ptr)[i-1];
	}
	((bool*) arr->ptr)[pos] = val;
}


// remove
void remove_string(vector* arr, const int pos, string* rval) {
	if (pos < 0 || pos >= arr->size) {puts("out of bounds");}
	if (arr->type != STRING) {puts("wrong type");}
	*rval = ((string*) arr->ptr)[pos];
	for (size_t i = pos; i < arr->size-1; i++) {
		((string*) arr->ptr)[i] = ((string*) arr->ptr)[i+1];
	}
	arr->size--;
	realloc_vector(arr);
}
void remove_int(vector* arr, int pos, int* rval) {
	if (pos < 0 || pos >= arr->size) {puts("out of bounds");}
	if (arr->type != INT) {puts("wrong type");}
	*rval = ((int*) arr->ptr)[pos];
	for (size_t i = pos; i < arr->size-1; i++) {
		((int*) arr->ptr)[i] = ((int*) arr->ptr)[i+1];
	}
	arr->size--;
	realloc_vector(arr);
}
void remove_flt(vector* arr, int pos, float* rval) {

	if (pos < 0 || pos >= arr->size) {puts("out of bounds");}
	if (arr->type != FLOAT) {puts("wrong type");}
	*rval = ((float*) arr->ptr)[pos];
	for (size_t i = pos; i < arr->size-1; i++) {
		((float*) arr->ptr)[i] = ((float*) arr->ptr)[i+1];
	}
	arr->size--;
	realloc_vector(arr);
}
void remove_bool(vector* arr, int pos, bool* rval) {
	if (pos < 0 || pos >= arr->size) {puts("out of bounds");}
	if (arr->type != BOOL) {puts("wrong type");}
	*rval = ((bool*) arr->ptr)[pos];
	for (size_t i = pos; i < arr->size-1; i++) {
		((bool*) arr->ptr)[i] = ((bool*) arr->ptr)[i+1];
	}
	arr->size--;
	realloc_vector(arr);
}


// filter
vector filter_string(vector arr, bool (*f)(string)) {
	if (arr.type != STRING) {puts("wrong type");}
	vector new_arr = new_vector((string*)malloc(0), 0);
	for (size_t i = 0; i < arr.size-1; i++) {
		string val = ((string*) arr.ptr)[i];
		if (f(val)) {push(&new_arr, val);}
	}
	return new_arr;
}
vector filter_int(vector arr, bool (*f)(int)) {
	if (arr.type != INT) {puts("wrong type");}
	vector new_arr = new_vector((int*)malloc(0), 0);
	for (size_t i = 0; i < arr.size-1; i++) {
		int val = ((int*) arr.ptr)[i];
		if (f(val)) {push(&new_arr, val);}
	}

	return new_arr;
}
vector filter_flt(vector arr, bool (*f)(float)) {
	if (arr.type != FLOAT) {puts("wrong type");}
	vector new_arr = new_vector((float*)malloc(0), 0);
	for (size_t i = 0; i < arr.size-1; i++) {
		float val = ((float*) arr.ptr)[i];
		if (f(val)) {push(&new_arr, val);}
	}
	return new_arr;
}
vector filter_bool(vector arr, bool (*f)(bool)) {
	if (arr.type != BOOL) {puts("wrong type");}
	vector new_arr = new_vector((bool*)malloc(0), 0);
	for (size_t i = 0; i < arr.size-1; i++) {
		bool val = ((bool*) arr.ptr)[i];

		if (f(val)) {push(&new_arr, val);}
	}
	return new_arr;
}


// map
void map_string(vector* arr, void (*f)(string*)) {
	if (arr->type != STRING) {puts("wrong type");}
	for (size_t i = 0; i < arr->size; i++) {
		f(&((string*)arr->ptr)[i]);
	}

}
void map_int(vector* arr, void (*f)(int*)) {
	if (arr->type != INT) {puts("wrong type");}
	for (size_t i = 0; i < arr->size; i++) {
		f(&((int*)arr->ptr)[i]);
	}
}
void map_float(vector* arr, void (*f)(float*)) {
	if (arr->type != FLOAT) {puts("wrong type");}
	for (size_t i = 0; i < arr->size; i++) {
		f(&((float*)arr->ptr)[i]);
	}
}
void map_bool(vector* arr, void (*f)(bool*)) {
	if (arr->type != BOOL) {puts("wrong type");}
	for (size_t i = 0; i < arr->size; i++) {
		f(&((bool*)arr->ptr)[i]);
	}
}


vector split_off(vector* arr, size_t at) {
	if (at > arr->size-1) {puts("out of bounds");}
	size_t new_len = arr->size - at;
	vector split_v;
	    switch (arr->type) {
			case STRING: split_v = new_vector((string*)arr->ptr + new_len*sizeof(string), new_len); break;
			case INT: split_v = new_vector((int*)arr->ptr + new_len*sizeof(int), new_len); break;
			case FLOAT: split_v = new_vector((float*)arr->ptr + new_len*sizeof(float), new_len); break;
			case BOOL: split_v = new_vector((bool*)arr->ptr + new_len*sizeof(bool), new_len); break;
			default: puts("Type not supported");
		}
	arr->size = new_len; 
	return split_v;
}


// contains
bool contains_string(vector arr, const string val) {
	if (arr.type != STRING) {puts("wrong type");}
	for (size_t i = 0; i < arr.size; i++) {
		if (((string*)arr.ptr)[i] == val) {return true;}
	}
	return false;
}
bool contains_int(vector arr, int val) {
	if (arr.type != INT) {puts("wrong type");}
	for (size_t i = 0; i < arr.size; i++) {
		if (((int*)arr.ptr)[i] == val) {return true;}
	}
	return false;
}
bool contains_float(vector arr, float val) {
	if (arr.type != FLOAT) {puts("wrong type");}
	for (size_t i = 0; i < arr.size; i++) {
		if (((float*)arr.ptr)[i] == val) {return true;}
	}
	return false;
}
bool contains_bool(vector arr, bool val) {
	if (arr.type != BOOL) {puts("wrong type");}
	for (size_t i = 0; i < arr.size; i++) {
		if (((bool*)arr.ptr)[i] == val) {return true;}
	}
	return false;
}


// fill
void fill_string(vector* arr, const string val) {
	if (arr->type != STRING) {puts("wrong type");}
	for (size_t i = 0; i < arr->size; i++) {
		strcpy(((string*)arr->ptr)[i], val);
	}
}
void fill_int(vector* arr, int val) {
	if (arr->type != INT) {puts("wrong type");}
	for (size_t i = 0; i < arr->size; i++) {
		((int*)arr->ptr)[i] = val;
	}
}
void fill_float(vector* arr, float val) {
	if (arr->type != FLOAT) {puts("wrong type");}
	for (size_t i = 0; i < arr->size; i++) {
		((float*)arr->ptr)[i] = val;
	}
}
void fill_bool(vector* arr, bool val) {
	if (arr->type != BOOL) {puts("wrong type");}
	for (size_t i = 0; i < arr->size; i++) {
		((bool*)arr->ptr)[i] = val;
	}
}

void print(vector arr) {
	printf("{");
	for (int i = 0; i < arr.size; i++) {
		switch (arr.type) {
			case STRING: printf("%s", ((string*)arr.ptr)[i]); break;
			case INT: printf("%i", ((int*)arr.ptr)[i]); break;
			case FLOAT: printf("%f", ((float*)arr.ptr)[i]); break;
			case BOOL: printf("%d", ((bool*)arr.ptr)[i]); break;
			default: puts("Type not supported");
		}
		if (i < arr.size-1) {printf(", ");}
	}
	printf("}");
}

void println(vector arr) {
	print(arr);
	printf("\n");
}
