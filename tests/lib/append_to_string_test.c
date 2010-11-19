#include <cgreen/cgreen.h>
#include "append_to_string.h"

static char *allocate_string() {
	char *destination = (char *) malloc(sizeof(1));
	destination[0] = NULL;
	return destination;
}

static void should_concatenation_a_empty_string() {
	char *destination = allocate_string();
	append_to_string(destination, "abc");
	assert_string_equal("abc", destination);
}

static void should_concatenate_a_exist_string() {
	char *destination = allocate_string();
	append_to_string(destination, "foo");
	append_to_string(destination, "bar");
	assert_string_equal("foobar", destination);
}

static void should_concatenate_and_reallocate_a_bigger_string() {
	int i;
	char *destination = allocate_string();
	for(i = 0; i < 10; i++) {
		append_to_string(destination, "a");
	}
	assert_string_equal("aaaaaaaaaa", destination);
}

TestSuite *append_to_string_suite() {
	TestSuite *suite = create_test_suite();
	add_test(suite, should_concatenation_a_empty_string);
	add_test(suite, should_concatenate_a_exist_string);
	add_test(suite, should_concatenate_and_reallocate_a_bigger_string);
	return suite;
}