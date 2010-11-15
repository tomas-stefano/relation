#include "relation.h"
#include "select_manager.h"

RelationTable new_relation_table(char *table_name) {
	RelationTable relation;
	relation.name = table_name;
	return relation;
}

SelectManager relation_table_from(RelationTable table) {
	return new_select_manager(table);
}

char *relation_table_primary_key(RelationTable table) {
	return "id";
}

SelectManager relation_table_select_manager(RelationTable table) {
	return relation_table_from(table);
}

SelectManager relation_table_project(RelationTable table, SqlLiteral sql_literal) {
	return select_manager_project(relation_table_from(table), sql_literal);
}

SelectManager relation_table_limit(RelationTable table, int limit_number) {
	return relation_table_from(table);
}