#include "relation.h"
#include "select_manager.h"

RelationTable new_relation_table(char *table_name) {
	RelationTable relation;
	relation.name = table_name;
	return relation;
}

char *relation_table_primary_key(RelationTable relation) {
	return "id";
}

SelectManager relation_table_select_manager(RelationTable relation) {
	SelectManager manager;
	return manager;
}

SelectManager relation_table_project(RelationTable relation, char *literal) {
	SelectManager manager;
	return manager;
}

SelectManager relation_table_limit(RelationTable relation, int limit_number) {
	SelectManager manager;
	return manager;
}