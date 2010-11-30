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
		if(ast.projections->next != NULL) query = append_to_string_with_size(query, ",", 1);
	}
	query = append_to_string_with_size(query, " ", 1);
	// free(ast.projections);
	return query;
}

char *visit_relation_table(RelationTable *table, char *query) {
	query = append_to_string_with_size(query, FROM, 5);
	query = append_to_string(query, table->name);	
	return query;
}

char *visit_relation_where(SelectStatement ast, char *query) {
	query = append_to_string_with_size(query, " ", 1);
	query = append_to_string_with_size(query, WHERE, 6);
	for(; ast.wheres != NULL; ast.wheres = ast.wheres->next) {		
		query = append_to_string(query, ast.wheres->sql_literal);		
		if(ast.wheres->next != NULL) query = append_to_string_with_size(query, " AND ", 5);
	}
	// free(ast.wheres);
	return query;
}

char *visit_relation_limit(int limit_size, char *query) {
	char *limit;
	limit = (char *) malloc(sizeof(char *));
	integer_to_char(limit_size, limit, 10); // TODO Verify malloc
	query = append_to_string_with_size(query, " LIMIT ", 7);
	query = append_to_string(query, limit);
	// free(limit);
	return query;
}

char *visit_relation_order(SelectStatement ast, char *query) {
	query = append_to_string_with_size(query, " ", 1);
	query = append_to_string_with_size(query, ORDER, 9);
	query = append_to_string(query, ast.orders);
	// free(ast.orders);
	return query;
}

char *visit_relation_offset(int offset_number, char *query) {
	query = append_to_string_with_size(query, " OFFSET ", 8);
	char *offset;
	offset = (char *) malloc(sizeof(char *)); // TODO Verify malloc
	integer_to_char(offset_number, offset, 10);
	query = append_to_string(query, offset);
	// free(offset);
	return query;
}

char *visit_relation_group(SelectStatement ast, char *query) {
	query = append_to_string_with_size(query, " GROUP BY ", 10);
	for(; ast.groups != NULL; ast.groups = ast.groups->next) {		
		query = append_to_string(query, ast.groups->sql_literal);		
		if(ast.groups->next != NULL) query = append_to_string(query, ",");
	}	
	// free(groups);
	return query;
}

char *visit_relation_having(SelectStatement ast, char *query) {
	query = append_to_string_with_size(query, " HAVING ", 8);
	query = append_to_string(query, ast.having);
	// free(ast.having);
	return query;
}

char *visit_nodes_select_core(SelectStatement ast) {
	char *query = _assign_select_string();
	if(ast.projections != NULL)	query = visit_syntax_tree_projections(ast, query);
	query = visit_relation_table(ast.froms, query);
	if(ast.wheres != NULL) query = visit_relation_where(ast, query);
	if(ast.groups != NULL) query = visit_relation_group(ast, query);
	if(ast.having != NULL) query = visit_relation_having(ast, query);
	if(ast.orders != NULL) query = visit_relation_order(ast, query);
	if(ast.limit > 0) query = visit_relation_limit(ast.limit, query);
	if(ast.offset > 0) query = visit_relation_offset(ast.offset, query);
	return query;
}

char *to_sql_visit(SelectStatement syntax_tree) {
	return visit_nodes_select_core(syntax_tree);
}

char *_assign_select_string() {
	char *query;
	query = (char *) malloc(SELECT_SIZE);
	memcpy(query, SELECT, SELECT_SIZE);	
	return query;
}
