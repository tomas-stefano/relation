#include "relation.h"
#include "select_manager.h"
#include "table.h"

RelationTable new_relation_table(char *table_name) {
	RelationTable relation;
	relation.name = table_name;
	return relation;
}

SelectManager relation_table_from(RelationTable table) {
	return new_select_manager(table);
}

SelectManager relation_table_select_manager(RelationTable table) {
	return relation_table_from(table);
}

SelectManager relation_table_project(RelationTable table, SqlLiteral sql_literal) {
	SelectManager manager = new_select_manager(table);
	manager = select_manager_project(manager, sql_literal);
	return manager;
}

SelectManager relation_table_limit(RelationTable table, int limit_number) {
	return relation_table_from(table);
}