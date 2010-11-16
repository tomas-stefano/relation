#include <stdlib.h>
#include <string.h>

#include "relation.h"
#include "relation/sql_literal.h"
#include "relation/table.h"
#include "relation/select_manager.h"
#include "relation/tree_manager.h"
#include "relation/visitors/to_sql.h"

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
	query = (char *) malloc(sizeof(9)); /* Allocate space to store SELECT string */
	memcpy(query, "SELECT ", 8);
	if(ast.projections != NULL) {
		int index;
		for(index = 0; ast.projections != NULL; index++) {
			if(index > 0) strcat(query, ",");
			query = (char *) realloc(query, sizeof(query) + 10);
			strcat(query, ast.projections->sql_literal);
			ast.projections = ast.projections->next;
		}
		query = (char *) realloc(query, sizeof(query) + 1);
		strcat(query, " ");
	}
	strcat(query, "FROM ");
	strcat(query, visit_relation_table(ast.froms));
	
	if(ast.limit > 0) {
		char *limit;
		limit = (char *) malloc(sizeof(ast.limit));
		integer_to_char(ast.limit, limit, 10); // base 10
		query = (char *) realloc(query, sizeof(query) + strlen(limit));
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
// 	RelationTable users = new_relation_table("users");
// 	
// 	SelectManager manager = relation_table_limit(users, 1);
// 	to_sql_visit(manager.abstract_syntax_tree);
// 	
// 	SelectManager other_manager = relation_table_limit(users, 10000000);
// 	to_sql_visit(other_manager.abstract_syntax_tree);	
// 	
// 	return 0;
// }