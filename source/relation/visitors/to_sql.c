#include <stdlib.h>
#include <string.h>

#include "relation.h"
#include "relation/sql_literal.h"
#include "relation/table.h"
#include "relation/select_manager.h"
#include "relation/tree_manager.h"

char *visit_relation_table(RelationTable table) {
	return table.name;
}
/*
* char *query;

query = realloc(NULL, strlen("SELECT ") + 1);
strcpy(query, "SELECT ");

if(abstract_syntax_tree.projections[0] != '\0') {
	char *fields = realloc(NULL, 1);
	strcpy(fields, abstract_syntax_tree.projections[0]);
	strcat(fields, " ");
	query = realloc(query, strlen(query) + strlen(fields));
	strcat(query, fields);
}

*
*
* 
*/
char *visit_select_statements(SelectStatement ast) {
	char *query;
	query = (char *) malloc(sizeof(strlen("SELECT "))); /* Allocate space to store SELECT string */
	memcpy(query, "SELECT ", 8);
	if(ast.projections) {
		strcat(query, ast.projections[0]);
		strcat(query, " ");
	}
	strcat(query, "FROM ");
	strcat(query, visit_relation_table(ast.froms));
	return query;
}

char *to_sql_visit(SelectStatement syntax_tree) {
	return visit_select_statements(syntax_tree);
}
// 
// int main (int argc, char const *argv[]) {
// 	RelationTable users;
// 	users = new_relation_table("users");
// 	SqlLiteral literal = "*";
// 	SelectManager manager = relation_table_project(users, literal);
// 	visit_select_statements(manager.abstract_syntax_tree);
// 	return 0;
// }