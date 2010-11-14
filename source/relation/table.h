#ifndef TABLE_H
#define TABLE_H

RelationTable new_relation_table(char *table_name);

char *relation_table_primary_key(RelationTable relation);

SelectManager relation_table_select_manager(RelationTable relation);

SelectManager relation_table_project(RelationTable relation, char *literal);

SelectManager relation_table_limit(RelationTable relation, int limit_number);

#endif