#include <cgreen/cgreen.h>
#include "relation.h"
#include "relation/table.h"
#include "relation/visitors/to_sql.h"

RelationTable *jokers;
static void should_return_the_name_of_the_table() {
	jokers = new_relation_table();
	table_instance_name(jokers, "jokers");
	assert_string_equal(visit_relation_table(jokers), "jokers");
}

TestSuite *visitor_to_sql_suite() {
	TestSuite *suite = create_test_suite();
	add_test(suite, should_return_the_name_of_the_table);
	return suite;
}