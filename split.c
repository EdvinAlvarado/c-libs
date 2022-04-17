#include <stddef.h>
#include <string.h> // strok, strlen
#include <stdio.h> // puts 
#include <stdlib.h> // malloc


// str gets modified
char** split(char* str, const char* delim, size_t* size) {
	// init
	char** results = malloc(strlen(str) * sizeof(char*));
	for (int i = 0; i < strlen(str); i++) {
		results[i] = (char*) malloc(strlen(str) * sizeof(char));
	}
	
	// write
	char* t = strtok(str, " ");
	int i = 0;
	while (t) {
		results[i++] = t;
		t = strtok(NULL, " ");
	}
	
	// return
	*size = i;
	return results;
}

