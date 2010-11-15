#include <string.h>
#include <stdlib.h>
#include "relation.h"
#include "visitor.h"
#include "to_sql.h"

/*

 I NEED STUDY HOW I IMPLEMENT THE VISITORS PATTERN IN C!!!! I DON'T KNOW!

*/

char *visitor_accept(SelectStatement abstract_syntax_tree) {
	return visitor_visit(abstract_syntax_tree);
}

char *visitor_visit(SelectStatement abstract_syntax_tree) {
	char *query;
	char *table;
	char *select;
	char *from;
	// table = visit_relation_nodes_select_statement(abstract_syntax_tree);
	table = visit_relation_table(abstract_syntax_tree.froms);
	select = "SELECT ";
	from = "* FROM ";
	// query = (char *) malloc(strlen());
	strcat(query, select);
	strcat(query, from);
	strcat(query, table);
	return query;
}
