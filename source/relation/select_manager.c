#include <stdlib.h>
#include <string.h>
#include "relation.h"
#include "relation/select_manager.h"

SelectManager new_select_manager(RelationTable *table) {
	SelectManager select_manager;
	select_manager.abstract_syntax_tree.froms = table;
	select_manager.abstract_syntax_tree.limit = 0;
	select_manager.abstract_syntax_tree.projections = NULL;
	return select_manager;
}

/*

*/
SelectManager select_manager_from(SelectManager select_manager, RelationTable *table) {
	return select_manager;
}

/*
   Append to the first element in the Projections linked list

	Example 1 - When not have projections:
	
   		projection    ->  [ sql_literal, next ~> NULL ]

   		projection   -> [ "name", next ~> NULL ]
		
		select_manager_project.abstract_syntax_tree.projection ->  ["name", next ~> NULL ]
		
	Example 2 - When have elements in the list:
	
	select_manager_project.abstract_syntax_tree.projection -> ["name", next ~> NULL]
	
	projection  ->  ["email", next ~> NULL]
	
	// In else:
	
	projection ->  ["email", next ~>  select_manager_project.abstract_syntax_tree.projections ]
	
	select_manager_project.abstract_syntax_tree.projections -> ["email", next ~> ["name", next ~> NULL]]

*/
SelectManager select_manager_project(SelectManager select_manager, SqlLiteral sql_literal) {
	Projections *projection;
	projection = (Projections *) malloc(sizeof(Projections) + 1); // +1 because the '\0' (I think =\ )
	projection->sql_literal = sql_literal;
	projection->next = NULL;
	if(select_manager.abstract_syntax_tree.projections == NULL) {
		select_manager.abstract_syntax_tree.projections = projection;
	}
	else {
		projection->next = select_manager.abstract_syntax_tree.projections;
		select_manager.abstract_syntax_tree.projections = projection;
	}
	return select_manager;
}

SelectManager select_manager_limit(SelectManager select_manager, int limit_number) {
	select_manager.abstract_syntax_tree.limit = limit_number;
	return select_manager;
}