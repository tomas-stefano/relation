#include <stdlib.h>
#include <string.h>
#include "relation.h"
#include "relation/select_manager.h"

SelectManager *new_select_manager() {
	// TODO: Verify Malloc
	SelectManager *select_manager = (SelectManager *) malloc(sizeof(SelectManager));
	return select_manager;
}

SelectManager *select_manager_instance_table(SelectManager *select_manager, RelationTable *table) {
	select_manager->abstract_syntax_tree.froms = table;
	select_manager->abstract_syntax_tree.limit = 0;
	select_manager->abstract_syntax_tree.offset = 0;
	select_manager->abstract_syntax_tree.projections = NULL;
	select_manager->abstract_syntax_tree.projections_tail = NULL;
	select_manager->abstract_syntax_tree.wheres = NULL;	
	select_manager->abstract_syntax_tree.wheres_tail = NULL;	
	select_manager->abstract_syntax_tree.orders = NULL;
	select_manager->abstract_syntax_tree.groups = NULL;
	select_manager->abstract_syntax_tree.groups_tail = NULL;	
	return select_manager;
}

/*
*
*/
SelectManager *select_manager_project(SelectManager *select_manager, SqlLiteral sql_literal) {
	ArraySqlLiterals *projection;
	
	// TODO: Verify malloc	
	projection = (ArraySqlLiterals *) malloc(sizeof(ArraySqlLiterals)); // +1 because the '\0' (I think =\ )	
	projection->sql_literal = sql_literal;
	projection->next = NULL;
	
	if(select_manager->abstract_syntax_tree.projections == NULL)
		select_manager->abstract_syntax_tree.projections = projection;
	else 
		select_manager->abstract_syntax_tree.projections_tail->next = projection;
		
	select_manager->abstract_syntax_tree.projections_tail = projection;
	
	return select_manager;
}

SelectManager *select_manager_limit(SelectManager *select_manager, int limit_number) {
	select_manager->abstract_syntax_tree.limit = limit_number;
	return select_manager;
}

SelectManager *select_manager_where(SelectManager *select_manager, SqlLiteral expression) {
	ArraySqlLiterals *literal;
	literal = (ArraySqlLiterals *) malloc(sizeof(ArraySqlLiterals)); // TODO: Verify malloc
	
	literal->sql_literal = expression;
	literal->next = NULL;
	
	if(select_manager->abstract_syntax_tree.wheres == NULL)
		select_manager->abstract_syntax_tree.wheres = literal;
	else 
		select_manager->abstract_syntax_tree.wheres_tail->next = literal;
		
	select_manager->abstract_syntax_tree.wheres_tail = literal;

	return select_manager;
}

SelectManager *select_manager_order(SelectManager *select_manager, char *expression) {
	select_manager->abstract_syntax_tree.orders = expression;
	return select_manager;
}

SelectManager *select_manager_offset(SelectManager *select_manager, int offset_number) {
	select_manager->abstract_syntax_tree.offset = offset_number;
	return select_manager;
}

SelectManager *select_manager_group(SelectManager *select_manager, SqlLiteral expression) {
	ArraySqlLiterals *literal;
	literal = (ArraySqlLiterals *) malloc(sizeof(ArraySqlLiterals)); // TODO: Verify malloc
	
	literal->sql_literal = expression;
	literal->next = NULL;
	
	if(select_manager->abstract_syntax_tree.groups == NULL)
		select_manager->abstract_syntax_tree.groups = literal;
	else 
		select_manager->abstract_syntax_tree.groups_tail->next = literal;
		
	select_manager->abstract_syntax_tree.groups_tail = literal;

	return select_manager;
}