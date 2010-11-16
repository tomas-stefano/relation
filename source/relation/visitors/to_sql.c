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
*
*
* 
*/
char *visit_select_statements(SelectStatement ast) {
	char *query;
	query = (char *) malloc(sizeof(8)); /* Allocate space to store SELECT string */
	memcpy(query, "SELECT ", 8);
	if(ast.projections != NULL) {
		int index;
		for(index = 0; ast.projections != NULL; index++) {
			if(index > 0) strcat(query, ",");
			strcat(query, ast.projections->sql_literal);
			ast.projections = ast.projections->next;
		}
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
// 	RelationTable users = new_relation_table("users");
// 	SelectManager manager = relation_table_project(users, new_sql_literal("name"));
// 	manager = select_manager_project(manager, new_sql_literal("email"));	
// 	to_sql_visit(manager.abstract_syntax_tree);	
// 	
// 	SelectManager my_manager = relation_table_project(users, new_sql_literal("*"));
// 	to_sql_visit(my_manager.abstract_syntax_tree);
// 	
// 	SelectManager select_manager = new_select_manager(users);
// 	select_manager = select_manager_project(select_manager, new_sql_literal("id"));
// 	to_sql_visit(select_manager.abstract_syntax_tree);	
// 	
// 	return 0;
// }