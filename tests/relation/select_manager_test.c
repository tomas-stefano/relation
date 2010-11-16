#include <cgreen/cgreen.h>
#include "relation.h"
#include "relation/sql_literal.h"
#include "relation/tree_manager.h"
#include "relation/select_manager.h"
#include "relation/table.h"
#include "test_helper.h"

RelationTable users;
static void before_all() {
	users = new_relation_table("users");
}

static void initialize_should_create_a_select_manager_with_relation_table_in_syntax_tree() {
	SelectManager select_manager = new_select_manager(users);
	assert_string_equal(select_manager.abstract_syntax_tree.froms.name, users.name);
}

static void project_should_accept_strings() {
	SelectManager select_manager = new_select_manager(users);
	select_manager = select_manager_project(select_manager, new_sql_literal("id"));
	assert_string_equal(relation_to_sql(select_manager), "SELECT id FROM users");
}

TestSuite *select_manager_suite() {
	TestSuite *suite = create_test_suite();
	setup(suite, before_all);
	
	add_test(suite, initialize_should_create_a_select_manager_with_relation_table_in_syntax_tree);
	
	add_test(suite, project_should_accept_strings);
	return suite;
}