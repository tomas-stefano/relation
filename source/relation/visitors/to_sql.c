#include <stdlib.h>
#include <string.h>

#include "relation.h"
#include "relation/sql_literal.h"
#include "relation/table.h"
#include "relation/select_manager.h"
#include "relation/tree_manager.h"
#include "relation/visitors/to_sql.h"

char *visit_relation_table(RelationTable *table) {
	return table->name;
}

/*
*
*/
char *visit_syntax_tree_projections(SelectStatement ast, char *query) {
	if(ast.projections != NULL) {
		for(; ast.projections != NULL; ast.projections = ast.projections->next) {
			query = realloc(query, strlen(query) + strlen(ast.projections->sql_literal) + 1);
			strcat(query, ast.projections->sql_literal);
			if(ast.projections->next != NULL) {
				query = realloc(query, strlen(query) + 1);
				strcat(query, ",");
			}
		}
		query = realloc(query, strlen(query) + 1);
		strcat(query, " ");
	}
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
	char *query;
	query = (char *) malloc(sizeof(SELECT_SIZE) + 1);
	memcpy(query, SELECT, SELECT_SIZE);
	query[7] = NULL;
	
	query = visit_syntax_tree_projections(ast, query);
	
	query = realloc(query, strlen(query) + FROM_SIZE);
	strcat(query, FROM);
	
	query = realloc(query, strlen(query) + strlen(visit_relation_table(ast.froms)));
	strcat(query, visit_relation_table(ast.froms));
	
	if(ast.limit > 0) {
		char *limit;
		limit = (char *) malloc(sizeof(char *));
		integer_to_char(ast.limit, limit, 10); // base 10
		query = realloc(query, strlen(query) + 7 + strlen(limit));
		strcat(query, " LIMIT ");
		strcat(query, limit);
	}
	
	return query;
}

char *to_sql_visit(SelectStatement syntax_tree) {
	return visit_select_statements(syntax_tree);
}

void reverse_string(char* begin, char* end) {
	char aux;	
	while(end > begin) aux=*end, *end--=*begin, *begin++=aux;
}

/*
*
* Ansi C "itoa" based on Kernighan & Ritchie's "Ansi C"
* with slight modification to optimize for specific architecture.
*
*/	
void integer_to_char(int value, char* str, int base) {
	static char num[] = "0123456789abcdefghijklmnopqrstuvwxyz";
	char* wstr=str;
	int sign;
	div_t res;
	
	// Validate base
	if (base<2 || base>35){ *wstr='\0'; return; }
	
	// Take care of sign
	if ((sign=value) < 0) value = -value;

	// Conversion. Number is reversed.
	do {
		res = div(value,base);
		*wstr++ = num[res.rem];
	} while(value = res.quot);
	
	if(sign<0) *wstr++='-';
	
	*wstr='\0';	
	// Reverse string
	reverse_string(str,wstr-1);	
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