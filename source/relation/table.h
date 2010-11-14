#ifndef TABLE_H
#define TABLE_H

RelationTable new_relation_table(char *table_name);

char *relation_table_primary_key(RelationTable relation);

#include "relation/select_manager.h"

SelectManager relation_table_project(RelationTable relation, char *literal);

SelectManager relation_table_select_manager(RelationTable relation);

#endif