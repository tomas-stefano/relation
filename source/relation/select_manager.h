#ifndef SELECT_MANAGER_H
#define SELECT_MANAGER_H

SelectManager *new_select_manager();

SelectManager *select_manager_instance_table(SelectManager *select_manager, RelationTable *table);

ArraySqlLiterals *new_array_of_sql_literals(SqlLiteral expression);

SelectManager *select_manager_project(SelectManager *select_manager, SqlLiteral literal);

SelectManager *select_manager_limit(SelectManager *select_manager, long long limit_number);

SelectManager *select_manager_where(SelectManager *select_manager, char *expression);

SelectManager *select_manager_order(SelectManager *select_manager, char *expression);

SelectManager *select_manager_offset(SelectManager *select_manager, int offset_number);

SelectManager *select_manager_group(SelectManager *select_manager, SqlLiteral expression);

SelectManager *select_manager_having(SelectManager *select_manager, SqlLiteral expression);

#endif