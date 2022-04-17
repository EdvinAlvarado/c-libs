#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include "vector.h"
#include "split.c"

bool is_even(float i) {return i > 2.f;}
void time_two(float* i) {*i *= 2;}

int main() {
	char input[] = "hello world! How are you?";
	char orig[strlen(input)];
	strcpy(orig, input);
	
	char** results;
	size_t result_size;
	results = split(input, " ", &result_size);
	
	struct vector arr = new_vector(results, result_size);
	println(arr);

	float intarr[] = {5,4,3,2,1};
	struct vector int_vector = new_vector(intarr, 5);
	float x = 10;
	get(int_vector, 3., &x);
	printf("%f\n", x);
	println(int_vector);

	puts("as_ptr");	
	size_t iarr_size;
	float* iarr = (float*)as_ptr(int_vector, &iarr_size);
	iarr[1] = 1000.;
	printf("%f\n", iarr[1]);
	println(int_vector);

	puts("reserve");
	reserve(&int_vector, 10);
	println(int_vector);
	
	puts("truncate");
	truncate(&int_vector, 5);
	println(int_vector);

	puts("resize");
	resize(&int_vector, 10, 100.f);
	println(int_vector);

	puts("pop");
	float p;	
	pop(&int_vector, &p);
	println(int_vector);
	printf("%f\n", p);

	puts("push");
	push(&int_vector, p);
	println(int_vector);

	puts("append");
	struct vector v = new_vector(intarr, 5);
	append(&int_vector, v);
	println(int_vector);

	puts("clear");
	clear(&int_vector);
	println(int_vector);

	puts("insert");
	insert(&v, 1, 100.f);
	println(v);
	
	float r = 0;
	puts("remove");
	remove(&v, 1, &r);
	println(v);
	printf("%f\n", r);

	puts("filter");
	struct vector v_fil = filter(v, is_even);
	println(v_fil);

	puts("map");
	println(v);
	map(&v, time_two);
	println(v);

	puts("contains");
	if (contains(v, 10.f)) {printf("contains: %f\n", 10.f);}

	puts("fill");
	fill(&v, 1000.f);
	println(v);
}
