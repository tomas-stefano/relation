#include <cgreen/cgreen.h>
#include "relation.h"

TestSuite *visitor_to_sql_suite() {
	TestSuite *suite = create_test_suite();
	return suite;
}