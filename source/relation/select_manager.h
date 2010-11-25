#ifndef SELECT_MANAGER_H
#define SELECT_MANAGER_H

SelectManager *new_select_manager();

SelectManager *select_manager_instance_table(SelectManager *select_manager, RelationTable *table);

SelectManager *select_manager_project(SelectManager *select_manager, SqlLiteral literal);

SelectManager *select_manager_limit(SelectManager *select_manager, int limit_number);

SelectManager *select_manager_where(SelectManager *select_manager, char *expression);

#endif