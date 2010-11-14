#include <cgreen/cgreen.h>
#include "relation.h"

static void initialize_should_have_limit_member() {
	SelectStatement select_statement;
	select_statement.limit = 1;
	assert_equal(select_statement.limit, 1);
}

static void initialize_should_have_projections_member_as_array_of_strings() {
	SelectStatement select_statement;
	SqlLiteral sql_literal_name = "name";
	SqlLiteral sql_literal_email = "email";
	select_statement.projections = &sql_literal_name;
	select_statement.projections[1] = sql_literal_email;
	assert_string_equal(select_statement.projections[0], "name");	
	assert_string_equal(select_statement.projections[1], "email");
}

TestSuite *select_statement_suite() {
	TestSuite *suite = create_test_suite();	
	add_test(suite, initialize_should_have_limit_member);
	add_test(suite, initialize_should_have_projections_member_as_array_of_strings);
	return suite;
}
