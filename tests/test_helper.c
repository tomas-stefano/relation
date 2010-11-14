#include <stdio.h>

void pending(char *test_name) {
	printf("\033[0;33m Pending test %s\n\e[0m", test_name);
}

