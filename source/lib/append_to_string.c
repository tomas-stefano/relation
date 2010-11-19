#include <stdlib.h>
#include <string.h>
#include "append_to_string.h"

char *append_to_string(char *destination, char *append_string) {
	destination = realloc(destination, strlen(destination) + strlen(append_string) + 1);
	strcat(destination, append_string);
	return destination;
}