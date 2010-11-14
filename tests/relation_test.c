#include <cgreen/cgreen.h>
#include "relation.h"

static void relation_should_have_a_version() {
	assert_string_equal(RelationVersion, "0.1.0");
}

TestSuite *relation_suite() {
	TestSuite *suite = create_test_suite();
	add_test(suite, relation_should_have_a_version);
	return suite;
}