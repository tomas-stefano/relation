#include <cgreen/cgreen.h>
#include "relation.h"
#include "relation/sql_literal.h"

static void should_set_and_get_the_name_of_the_literal() {
	SqlLiteral sql_literal = new_sql_literal("*");
	assert_string_equal(sql_literal, "*");
}

static void should_set_and_get_a_normal_field_name() {
	SqlLiteral sql_literal = new_sql_literal("name");
	assert_string_equal(sql_literal, "name");
}

TestSuite *sql_literal_suite() {
	TestSuite *suite = create_test_suite();
	add_test(suite, should_set_and_get_the_name_of_the_literal);
	add_test(suite, should_set_and_get_a_normal_field_name);
	return suite;
}