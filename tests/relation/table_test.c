#include <cgreen/cgreen.h>
#include "select_manager.h"
#include "sql_literal.h"
#include "table.h"
#include "tree_manager.h"

static void primary_key_should_return_an_attribute() {
	RelationTable relation = new_relation_table("users");
	assert_string_equal(relation_table_primary_key(relation), "id");
}

static void should_have_the_name_of_the_table() {
	RelationTable relation = new_relation_table("posts");
	assert_string_equal(relation.name, "posts");
}

static void should_set_the_name_of_the_sql_table() {
	RelationTable relation = new_relation_table("users");
	assert_string_equal(relation.name, "users");
}

static void select_manager_should_return_a_empty_select() {
	RelationTable relation = new_relation_table("users");
	SelectManager manager = relation_table_select_manager(relation);
	assert_string_equal(relation_to_sql(manager), "SELECT ");
}

static void project_can_pass_all_the_fields_in_the_table() {
	// RelationTable relation = new_relation_table("users");
	// SqlLiteral sql_literal = new_sql_literal("*");
	// SelectManager manager = relation_table_project(relation, sql_literal);
	// assert_string_equal(relation_to_sql(manager), "SELECT * from users");
}

TestSuite *relation_table_suite() {
	TestSuite *suite = create_test_suite();
	add_test(suite, primary_key_should_return_an_attribute);
	add_test(suite, should_have_the_name_of_the_table);
	add_test(suite, should_set_the_name_of_the_sql_table);
	add_test(suite, select_manager_should_return_a_empty_select);
	add_test(suite, project_can_pass_all_the_fields_in_the_table);
	// add_test(suite, project_can_project_many_literals);
	return suite;
}
