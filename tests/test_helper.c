#include <cgreen/cgreen.h>

TestSuite *sql_version_test();

TestSuite *relation_table_suite();

TestSuite *select_manager_suite();

TestSuite *sql_literal_suite();

int main() {
	TestSuite *suite = create_test_suite();
	add_suite(suite, sql_version_test());
	add_suite(suite, relation_table_suite());
	add_suite(suite, select_manager_suite());
	add_suite(suite, sql_literal_suite());
	return run_test_suite(suite, create_text_reporter());
}