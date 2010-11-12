#ifndef TABLE_H
#define TABLE_H

typedef struct relation_table {
	char *name;
} RelationTable;

RelationTable new_relation_table(char *table_name);

char *relation_table_primary_key(RelationTable relation);

SelectManager relation_table_project(RelationTable relation, SqlLiteral *literals);

SelectManager relation_table_select_manager(RelationTable relation);

#endif