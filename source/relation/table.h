#ifndef TABLE_H
#define TABLE_H

RelationTable new_relation_table(char *table_name);

SelectManager relation_table_from(RelationTable table);

SelectManager relation_table_select_manager(RelationTable table);

SelectManager relation_table_project(RelationTable table, SqlLiteral sql_literal);

SelectManager relation_table_limit(RelationTable table, int limit_number);

#endif