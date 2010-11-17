#include <cgreen/cgreen.h>
#include "test_helper.h"
#include "relation.h"
#include "relation/sql_literal.h"
#include "relation/table.h"
#include "relation/select_manager.h"
#include "relation/tree_manager.h"

RelationTable *users;
RelationTable *posts;
RelationTable *developers;

static void before_all() {
	users = new_relation_table();
	table_instance_name(users, "users");
	posts = new_relation_table();
	table_instance_name(posts, "posts");
	developers = new_relation_table();
	table_instance_name(developers, "developers");
}

static void should_have_the_name_of_the_table() {
	assert_string_equal(posts->name, "posts");
}

static void should_set_the_name_of_the_sql_table() {
	assert_string_equal(users->name, "users");
}

static void should_set_and_get_the_table_name() {
	assert_string_equal(developers->name, "developers");
}

static void select_manager_should_return_a_empty_select() {
	SelectManager manager = relation_table_select_manager(users);
	assert_string_equal(relation_to_sql(manager), "SELECT FROM users");
}

static void project_can_pass_all_the_fields_in_the_table() {
	SelectManager manager = relation_table_project(users, new_sql_literal("*"));
	assert_string_equal(relation_to_sql(manager), "SELECT * FROM users");
}

static void project_should_be_possible_to_have_many_literals() {
	SelectManager manager = relation_table_project(users, new_sql_literal("name"));
	manager = select_manager_project(manager, new_sql_literal("email"));
	assert_string_equal(relation_to_sql(manager), "SELECT email,name FROM users");
}

static void project_should_be_possible_to_have_many_literals_including_count() {
	SelectManager manager = relation_table_project(users, new_sql_literal("name"));
	manager = select_manager_project(manager, new_sql_literal("email"));
	manager = select_manager_project(manager, new_sql_literal("count(*) as all_users"));
	assert_string_equal(relation_to_sql(manager), "SELECT count(*) as all_users,email,name FROM users");
}

static void limit_should_add_a_limit_number() {
	SelectManager manager = relation_table_limit(developers, 1);
	manager = select_manager_project(manager, new_sql_literal("*"));
	assert_string_equal(relation_to_sql(manager), "SELECT * FROM developers LIMIT 1");
}

static void limit_should_pass_a_high_number() {
	SelectManager manager = relation_table_limit(users, 100000000);
	manager = select_manager_project(manager, new_sql_literal("*"));
	assert_string_equal(relation_to_sql(manager), "SELECT * FROM users LIMIT 100000000");
}

TestSuite *relation_table_suite() {
	TestSuite *suite = create_test_suite();
	
	/* before(:all) */
	setup(suite, before_all);
	
	/* describe #name */
	add_test(suite, should_have_the_name_of_the_table);
	add_test(suite, should_set_the_name_of_the_sql_table);
	add_test(suite, should_set_and_get_the_table_name);
	
	/* describe #select_manager */
	add_test(suite, select_manager_should_return_a_empty_select);

	/* describe #project */	
	add_test(suite, project_can_pass_all_the_fields_in_the_table);
	add_test(suite, project_should_be_possible_to_have_many_literals);
	add_test(suite, project_should_be_possible_to_have_many_literals_including_count);
	
	/* describe #limit */
	add_test(suite, limit_should_add_a_limit_number);
	add_test(suite, limit_should_pass_a_high_number);
	
	return suite;
}
