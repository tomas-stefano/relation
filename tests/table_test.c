#include <cgreen/cgreen.h>
#include "test_helper.h"
#include "relation.h"
#include "relation/sql_literal.h"
#include "relation/table.h"
#include "relation/select_manager.h"
#include "relation/tree_manager.h"

#include "integer_to_char.h"
#include "append_to_string.h"

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

static void should_set_the_table_name_string_size() {
	assert_equal(developers->name_size, 10);
}

static void select_manager_should_return_a_empty_select() {
	SelectManager *manager = relation_table_select_manager(users);
	assert_string_equal(relation_to_sql(manager), "SELECT FROM users");
}

static void project_can_pass_all_the_fields_in_the_table() {
	SelectManager *manager = relation_table_project(users, new_sql_literal("*"));
	assert_string_equal(relation_to_sql(manager), "SELECT * FROM users");
}

static void project_should_be_possible_to_have_many_literals() {
	SelectManager *manager = relation_table_project(users, new_sql_literal("name"));
	select_manager_project(manager, new_sql_literal("email"));
	assert_string_equal(relation_to_sql(manager), "SELECT name,email FROM users");
}

static void project_should_be_possible_to_have_many_literals_including_count() {
	SelectManager *manager = relation_table_project(users, new_sql_literal("name"));
	select_manager_project(manager, new_sql_literal("email"));
	select_manager_project(manager, new_sql_literal("count(*) as all_users"));
	assert_string_equal(relation_to_sql(manager), "SELECT name,email,count(*) as all_users FROM users");
}

static void limit_should_add_a_limit_number() {
	SelectManager *manager = relation_table_limit(developers, 1);
	select_manager_project(manager, new_sql_literal("*"));
	assert_string_equal(relation_to_sql(manager), "SELECT * FROM developers LIMIT 1");
}

static void limit_should_pass_a_high_number() {
	SelectManager *manager = relation_table_limit(users, 100000000);
	select_manager_project(manager, new_sql_literal("*"));
	assert_string_equal(relation_to_sql(manager), "SELECT * FROM users LIMIT 100000000");
}

static void where_should_return_a_tree_manager() {
	SelectManager *manager = relation_table_where(users, "id > 1");
	select_manager_project(manager, new_sql_literal("id"));
	assert_string_equal(relation_to_sql(manager), "SELECT id FROM users WHERE id > 1");
}

static void where_should_construct_the_where_clauses() {
	SelectManager *manager = relation_table_where(users, "login = 'tomas'");
	select_manager_where(manager, "password = 'secret'");
	select_manager_project(manager, new_sql_literal("login"));
assert_string_equal(relation_to_sql(manager),"SELECT login FROM users WHERE login = 'tomas' AND password = 'secret'");
}

static void order_should_add_the_order_clause() {
	SelectManager *manager = relation_table_order(developers, "name");
	assert_string_equal(relation_to_sql(manager), "SELECT FROM developers ORDER BY name");
}

static void offset_should_add_the_offset_clause() {
	SelectManager *manager = relation_table_offset(developers, 100);
	assert_string_equal(relation_to_sql(manager), "SELECT FROM developers OFFSET 100");
}

static void group_should_create_a_group() {
	SelectManager *manager = relation_table_group(developers, "id");
	assert_string_equal(relation_to_sql(manager), "SELECT FROM developers GROUP BY id");
}

static void group_should_add_many_fields_to_group() {
	SelectManager *manager = relation_table_group(developers, "name");
	select_manager_group(manager, "language");
	assert_string_equal(relation_to_sql(manager), "SELECT FROM developers GROUP BY name,language");
}

static void having_should_create_a_hvaing_clause() {
	SelectManager *manager = relation_table_having(developers, "id = 20");
	assert_string_equal(relation_to_sql(manager), "SELECT FROM developers HAVING id = 20");
}

TestSuite *relation_table_suite() {
	TestSuite *suite = create_test_suite();
	
	/* before(:all) */
	setup(suite, before_all);
	
	/* describe #name */
	add_test(suite, should_have_the_name_of_the_table);
	add_test(suite, should_set_the_name_of_the_sql_table);
	add_test(suite, should_set_and_get_the_table_name);
	add_test(suite, should_set_the_table_name_string_size);
	
	/* describe #select_manager */
	add_test(suite, select_manager_should_return_a_empty_select);

	/* describe #project */	
	add_test(suite, project_can_pass_all_the_fields_in_the_table);
	add_test(suite, project_should_be_possible_to_have_many_literals);
	add_test(suite, project_should_be_possible_to_have_many_literals_including_count);
	
	/* describe #limit */
	add_test(suite, limit_should_add_a_limit_number);
	add_test(suite, limit_should_pass_a_high_number);
	
	/* describe #where */
	add_test(suite, where_should_return_a_tree_manager);
	add_test(suite, where_should_construct_the_where_clauses);
	
	/* describe #order */
	add_test(suite, order_should_add_the_order_clause);

	/* describe #offset */
	add_test(suite, offset_should_add_the_offset_clause);
	
	/* describe #group */
	add_test(suite, group_should_create_a_group);
	add_test(suite, group_should_add_many_fields_to_group);
	
	/* describe #having */
	add_test(suite, having_should_create_a_hvaing_clause);
	
	return suite;
}
