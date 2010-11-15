#include <cgreen/cgreen.h>
#include "relation.h"

static void initialize_should_have_limit_member() {
	SelectStatement select_statement;
	select_statement.limit = 1;
	assert_equal(select_statement.limit, 1);
}

static void initialize_should_be_possible_to_assign_a_sql_literal() {
	SelectStatement select_statement;
	SqlLiteral sql_literal_name = "name";
	select_statement.projections = &sql_literal_name;
	assert_string_equal(select_statement.projections[0], "name");
}

TestSuite *select_statement_suite() {
	TestSuite *suite = create_test_suite();	
	add_test(suite, initialize_should_have_limit_member);
	add_test(suite, initialize_should_be_possible_to_assign_a_sql_literal);
	return suite;
}
