#include "select_manager.h"
#include "sql_literal.h"
#include "table.h"
#include "tree_manager.h"

char *relation_to_sql(SelectManager manager) {
	return "SELECT ";
}