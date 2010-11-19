#include <cgreen/cgreen.h>
#include "relation.h"
#include "relation/table.h"
#include "relation/visitors/to_sql.h"

TestSuite *visitor_to_sql_suite() {
	TestSuite *suite = create_test_suite();
	return suite;
}