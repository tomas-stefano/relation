#include <stdlib.h>
#include <string.h>
#include "relation.h"
#include "relation/select_manager.h"

SelectManager *new_select_manager() {
	SelectManager *select_manager = (SelectManager *) malloc(sizeof(SelectManager));
	return select_manager;
}

SelectManager *select_manager_instance_table(SelectManager *select_manager, RelationTable *table) {
	select_manager->abstract_syntax_tree.froms = table;
	select_manager->abstract_syntax_tree.limit = 0;
	select_manager->abstract_syntax_tree.projections = NULL;
	select_manager->abstract_syntax_tree.wheres = NULL;	
	return select_manager;
}

/*
   Append to the first element in the projections linked list

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
SelectManager *select_manager_project(SelectManager *select_manager, SqlLiteral sql_literal) {
	ArraySqlLiterals *projection;
	projection = (ArraySqlLiterals *) malloc(sizeof(ArraySqlLiterals)); // +1 because the '\0' (I think =\ )	
	projection->sql_literal = sql_literal;
	projection->next = NULL;
	if(select_manager->abstract_syntax_tree.projections == NULL) {
		select_manager->abstract_syntax_tree.projections = projection;
	}
	else {
		projection->next = select_manager->abstract_syntax_tree.projections;
		select_manager->abstract_syntax_tree.projections = projection;
	}
	// TODO
	// free(projection);
	return select_manager;
}

SelectManager *select_manager_limit(SelectManager *select_manager, int limit_number) {
	select_manager->abstract_syntax_tree.limit = limit_number;
	return select_manager;
}

SelectManager *select_manager_where(SelectManager *select_manager, char *expression) {
	ArraySqlLiterals *literal;
	literal = (ArraySqlLiterals *) malloc(sizeof(ArraySqlLiterals));
	
	literal->sql_literal = expression;
	literal->next = NULL;
	
	if(select_manager->abstract_syntax_tree.wheres == NULL)
		select_manager->abstract_syntax_tree.wheres = literal;
	else {
		literal->next = select_manager->abstract_syntax_tree.wheres;
		select_manager->abstract_syntax_tree.wheres = literal;
	}
		
	return select_manager;
}
