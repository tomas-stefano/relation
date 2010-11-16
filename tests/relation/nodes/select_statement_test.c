#include <cgreen/cgreen.h>
#include "relation.h"

static void initialize_should_have_limit_member() {
	SelectStatement select_statement;
	select_statement.limit = 1;
	assert_equal(select_statement.limit, 1);
}

TestSuite *select_statement_suite() {
	TestSuite *suite = create_test_suite();	
	add_test(suite, initialize_should_have_limit_member);
	return suite;
}
