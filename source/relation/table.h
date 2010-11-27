#ifndef TABLE_H
#define TABLE_H

RelationTable *new_relation_table();

RelationTable *table_instance_name(RelationTable *relation_table, char *table_name);

SelectManager *relation_table_from(RelationTable *table);

SelectManager *relation_table_select_manager(RelationTable *table);

SelectManager *relation_table_project(RelationTable *table, SqlLiteral sql_literal);

SelectManager *relation_table_limit(RelationTable *table, int limit_number);

SelectManager *relation_table_where(RelationTable *table, char *expression);

SelectManager *relation_table_order(RelationTable *table, char *expression);

#endif