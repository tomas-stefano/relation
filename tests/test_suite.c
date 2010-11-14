#include <cgreen/cgreen.h>

/*
*  Copyright (c) 2010 Tomás D'Stefano
*  
*  Permission is hereby granted, free of charge, to any person obtaining
*  a copy of this software and associated documentation files (the
*  "Software"), to deal in the Software without restriction, including
*  without limitation the rights to use, copy, modify, merge, publish,
*  distribute, sublicense, and/or sell copies of the Software, and to
*  permit persons to whom the Software is furnished to do so, subject to
*  the following conditions:
*  
*  The above copyright notice and this permission notice shall be
*  included in all copies or substantial portions of the Software.
*  
*  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
*  EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
*  MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
*  NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE
*  LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION
*  OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION
*  WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*  
*/

/*
*  To run tests just type in the terminal: 
*
*  rake test
*
*/

/* Relation suite */
TestSuite *relation_suite();

/* Nodes Suite */
TestSuite *select_statement_suite();
	
/* Visitors Suite */
TestSuite *visitor_to_sql_suite();

/* Managers Suite */
TestSuite *relation_table_suite();
TestSuite *select_manager_suite();
TestSuite *sql_literal_suite();

int main(int argc, char **argv) {
	TestSuite *suite = create_test_suite();
	/* Relation Suite */
	add_suite(suite, relation_suite());
	
	/* Nodes Suite */
	add_suite(suite, select_statement_suite());

	/* Visitors Suite */
	add_suite(suite, visitor_to_sql_suite());
	
	/* Managers Suite */
	add_suite(suite, relation_table_suite());
	add_suite(suite, select_manager_suite());
	add_suite(suite, sql_literal_suite());

	if (argc > 1)
	  return run_single_test(suite, argv[1], create_text_reporter());
	else	
	  return run_test_suite(suite, create_text_reporter());
}