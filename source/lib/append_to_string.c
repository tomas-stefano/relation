#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "append_to_string.h"

char *append_to_string(char *destination, char *append_string) {
	destination = realloc(destination, strlen(destination) + strlen(append_string) + 1);
	if(destination == NULL) {
		printf("Out of Memory!! Fuuuuuuuu");
	  	exit(1);
	}
	strcat(destination, append_string);
	return destination;
}

char *append_to_string_with_size(char *destination, char *append_string, long long size) {
	destination = realloc(destination, strlen(destination) + size + 1);
	if(destination == NULL) {
		printf("Out of Memory!! Fuuuuuuuu");
		exit(1);
	}
	strcat(destination, append_string);
	return destination;
}