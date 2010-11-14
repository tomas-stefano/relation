#include "relation.h"
#include "relation/select_manager.h"

SelectManager select_manager_from(SelectManager select_manager, RelationTable table) {
	// In Ruby
	// ctx.froms  = table
	// self
	
	// In C
	// manager.context.froms = table;
	return select_manager;
}

SelectManager select_manager_project(SelectManager select_manager, char *literal) {
	return select_manager;
}