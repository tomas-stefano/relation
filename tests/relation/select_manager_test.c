#include <cgreen/cgreen.h>
#include "relation.h"
#include "relation/sql_literal.h"
#include "relation/tree_manager.h"
#include "relation/select_manager.h"
#include "relation/table.h"
#include "test_helper.h"

RelationTable *users;
RelationTable *batman;

static void before_all() {
	users = new_relation_table();
	table_instance_name(users, "users");
	batman = new_relation_table();
	table_instance_name(batman, "batman");	
}

static void initialize_should_create_a_select_manager_with_relation_table_in_syntax_tree() {
	SelectManager *select_manager = new_select_manager();
	select_manager_instance_table(select_manager, users);
	assert_string_equal(select_manager->abstract_syntax_tree.froms->name, users->name);
}

static void project_should_accept_strings() {
	SelectManager *select_manager = new_select_manager();
	select_manager_instance_table(select_manager, batman);
	select_manager_project(select_manager, new_sql_literal("id"));
	assert_string_equal(relation_to_sql(select_manager), "SELECT id FROM batman");
}

static void where_should_return_a_where_clause() {
	SelectManager *select_manager = new_select_manager();
	select_manager_instance_table(select_manager, batman);
	select_manager_where(select_manager, "age > 18 AND vilain = 'Coringa'");
	assert_string_equal(relation_to_sql(select_manager), "SELECT FROM batman WHERE age > 18 AND vilain = 'Coringa'");
}

TestSuite *select_manager_suite() {
	TestSuite *suite = create_test_suite();
	setup(suite, before_all);
	
	add_test(suite, initialize_should_create_a_select_manager_with_relation_table_in_syntax_tree);	
	add_test(suite, project_should_accept_strings);
	add_test(suite, where_should_return_a_where_clause);
	return suite;
}