#include <cgreen/cgreen.h>
#include "relation.h"
#include "relation/table.h"
#include "relation/visitors/to_sql.h"

static void should_return_the_name_of_the_table() {
	RelationTable users = new_relation_table("users");
	assert_string_equal(visit_relation_table(users), "users");
}

TestSuite *visitor_to_sql_suite() {
	TestSuite *suite = create_test_suite();
	add_test(suite, should_return_the_name_of_the_table);
	return suite;
}