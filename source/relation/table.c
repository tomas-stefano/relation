
#include <stdlib.h>

#include "relation.h"
#include "select_manager.h"
#include "table.h"

RelationTable *new_relation_table() {
	RelationTable *relation_table = (RelationTable *) malloc(sizeof(RelationTable));
	return relation_table;
}

RelationTable *table_instance_name(RelationTable *relation_table, char *table_name) {
	relation_table->name = table_name;
	return relation_table;
}

SelectManager *relation_table_from(RelationTable *table) {
	SelectManager *select_manager = new_select_manager();
	return select_manager_instance_table(select_manager, table);
}

SelectManager *relation_table_select_manager(RelationTable *table) {
	return relation_table_from(table);
}

SelectManager *relation_table_project(RelationTable *table, SqlLiteral sql_literal) {
	return select_manager_project(relation_table_from(table), sql_literal);
}

SelectManager *relation_table_limit(RelationTable *table, int limit_number) {
	return select_manager_limit(relation_table_from(table), limit_number);
}

SelectManager *relation_table_where(RelationTable *table, char *expression) {
	return select_manager_where(relation_table_from(table), expression);
}

SelectManager *relation_table_order(RelationTable *table, char *expression) {
	return select_manager_order(relation_table_from(table), expression);
}
