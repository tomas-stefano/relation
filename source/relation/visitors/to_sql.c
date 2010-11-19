#include <stdlib.h>
#include <string.h>

#include "relation.h"
#include "relation/sql_literal.h"
#include "relation/table.h"
#include "relation/select_manager.h"
#include "relation/tree_manager.h"
#include "relation/visitors/to_sql.h"

char *append_to_string(char *destination, char *append_string) {
	destination = realloc(destination, strlen(destination) + strlen(append_string));
	strcat(destination, append_string);
}

char *visit_relation_table(RelationTable *table, char *query) {
	query = append_to_string(query, FROM);
	query = append_to_string(query, table->name);	
	return query;
}

/*
*
*/
char *visit_syntax_tree_projections(SelectStatement ast, char *query) {
	if(ast.projections != NULL) {
		for(; ast.projections != NULL; ast.projections = ast.projections->next) {
			append_to_string(query, ast.projections->sql_literal);	
			if(ast.projections->next != NULL) append_to_string(query, ",");
		}
		append_to_string(query, " ");
	}
	return query;
}

char *visit_relation_limit(int limit_size, char *query) {
	char *limit;
	limit = (char *) malloc(sizeof(char *));
	integer_to_char(limit_size, limit, 10);
	query = append_to_string(query, " LIMIT ");
	query = append_to_string(query, limit);
	free(limit);
	return query;
}

/*
*
*
* 
*/

// 
// #define BUFFER sizeof(char) * 256
// query = (char *) malloc(BUFFER);
// 
// 
// strcat_tomas(query, ...)
// int strcat_tomas(s , s )
// verifique_o_buffer(query, BUFFER);

char *visit_select_statements(SelectStatement ast) {
	char *query = _assign_select_string();
	query = visit_syntax_tree_projections(ast, query);
	query = visit_relation_table(ast.froms, query);
	if(ast.limit > 0) query = visit_relation_limit(ast.limit, query);
	return query;
}

char *to_sql_visit(SelectStatement syntax_tree) {
	return visit_select_statements(syntax_tree);
}

char *_assign_select_string() {
	char *query;
	query = (char *) malloc(sizeof(SELECT_SIZE) + 1);
	memcpy(query, SELECT, SELECT_SIZE);
	query[7] = NULL;
	return query;
}

// int main (int argc, char const *argv[]) {
// 	RelationTable *batman;
// 	batman = new_relation_table();
// 	table_instance_name(batman, "batman");
// 	SelectManager *select_manager = new_select_manager();
// 	select_manager_instance_table(select_manager, batman);
// 	select_manager_project(select_manager, new_sql_literal("id"));
// 	select_manager_project(select_manager, new_sql_literal("*"));
// 	select_manager_project(select_manager, new_sql_literal("count(*) as all_users"));
// 	
// 	
// 	// 
// 	// 
// 	// SelectManager *manager = relation_table_project(users, new_sql_literal("name"));
// 	// 
// 	// select_manager_project(manager, new_sql_literal("email"));
// 	// 
// 	to_sql_visit(select_manager->abstract_syntax_tree);
// 	
// 	return 0;
// }