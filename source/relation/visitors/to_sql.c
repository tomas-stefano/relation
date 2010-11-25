#include <stdlib.h>
#include <string.h>

#include "relation.h"
#include "relation/sql_literal.h"
#include "relation/table.h"
#include "relation/select_manager.h"
#include "relation/tree_manager.h"
#include "relation/visitors/to_sql.h"

#include "integer_to_char.h"
#include "append_to_string.h"

char *visit_syntax_tree_projections(SelectStatement ast, char *query) {
	for(; ast.projections != NULL; ast.projections = ast.projections->next) {
		query = append_to_string(query, ast.projections->sql_literal);
		if(ast.projections->next != NULL) query = append_to_string(query, ",");
	}
	query = append_to_string(query, " ");
	return query;
}

char *visit_relation_table(RelationTable *table, char *query) {
	query = append_to_string(query, FROM);
	query = append_to_string(query, table->name);	
	return query;
}

char *visit_relation_where(ArraySqlLiterals *literals, char *query) {
	append_to_string(query, " ");
	append_to_string(query, WHERE);
	for(; literals != NULL; literals = literals->next) {
		append_to_string(query, literals->sql_literal);
		if(literals->next != NULL) query = append_to_string(query, " AND ");
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

char *visit_select_statements(SelectStatement ast) {
	char *query = _assign_select_string();
	if(ast.projections != NULL)	query = visit_syntax_tree_projections(ast, query);
	query = visit_relation_table(ast.froms, query);
	if(ast.wheres != NULL) query = visit_relation_where(ast.wheres, query);
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
