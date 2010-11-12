#include <cgreen/cgreen.h>
#include "relation.h"

static void sql_relation_should_have_a_version() {
	assert_string_equal(RelationVersion, "0.1.0");
}

TestSuite *sql_version_test() {
	TestSuite *suite = create_test_suite();
	add_test(suite, sql_relation_should_have_a_version);
	return suite;
}