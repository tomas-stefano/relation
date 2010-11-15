#include <stdlib.h>
#include "relation.h"
#include "relation/select_manager.h"

SelectManager new_select_manager(RelationTable table) {
	SelectManager select_manager;
	select_manager.abstract_syntax_tree.froms = table;
	select_manager.abstract_syntax_tree.limit = 0;
	select_manager.abstract_syntax_tree.projections = NULL;
	return select_manager;
}

SelectManager select_manager_from(SelectManager select_manager, RelationTable table) {
	return select_manager;
}

SelectManager select_manager_project(SelectManager select_manager, SqlLiteral sql_literal) {
	select_manager.abstract_syntax_tree.projections = (SqlLiteral *) malloc(sizeof(sql_literal));
	select_manager.abstract_syntax_tree.projections[0] = sql_literal;
	return select_manager;
}