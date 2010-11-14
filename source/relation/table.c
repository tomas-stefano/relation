#include "relation.h"
#include "select_manager.h"

RelationTable new_relation_table(char *table_name) {
	RelationTable relation;
	relation.name = table_name;
	return relation;
}

SelectManager relation_table_from(RelationTable table) {
	SelectManager manager;// = new_select_manager(table);
	return manager;
}

char *relation_table_primary_key(RelationTable table) {
	return "id";
}

SelectManager relation_table_select_manager(RelationTable table) {
	SelectManager manager;
	return manager;
}

SelectManager relation_table_project(RelationTable table, char *literal) {
	SelectManager manager;
	return manager;
}

SelectManager relation_table_limit(RelationTable table, int limit_number) {
	SelectManager manager;
	manager = relation_table_from(table);
	return manager;
}