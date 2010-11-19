#include <cgreen/cgreen.h>
#include "integer_to_char.h"

static void should_return_a_empty_string_with_base_less_than_two() {
	char *character = malloc(sizeof(100));
	integer_to_char(10, character, 1);
	assert_string_equal("", character);
}

static void should_return_a_empty_string_with_base_greater_than_thirty_five() {
	char *character = malloc(sizeof(100));
	integer_to_char(10, character, 36);
	assert_string_equal("", character);
}

static void should_convert_little_numbers_to_char() {
	char *character = malloc(sizeof(100));
	integer_to_char(0, character, 10);
	assert_string_equal("0", character);
	integer_to_char(10, character, 10);
	assert_string_equal("10", character);
	integer_to_char(99, character, 10);
	assert_string_equal("99", character);
}

static void should_convert_high_numbers_to_char() {
	char *character = malloc(sizeof(10000));
	integer_to_char(506978, character, 10);
	assert_string_equal("506978", character);
	integer_to_char(10000000, character, 10);
	assert_string_equal("10000000", character);	
	integer_to_char(1000000000, character, 10);
	assert_string_equal("1000000000", character);		
}

TestSuite *integer_to_char_suite() {
	TestSuite *suite = create_test_suite();
	
	/* describe #integer_to_char */
	add_test(suite, should_return_a_empty_string_with_base_less_than_two);
	add_test(suite, should_return_a_empty_string_with_base_greater_than_thirty_five);
	add_test(suite, should_convert_little_numbers_to_char);
	add_test(suite, should_convert_high_numbers_to_char);
	
	return suite;
}