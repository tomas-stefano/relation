#ifndef SELECT_MANAGER_H
#define SELECT_MANAGER_H

SelectManager new_select_manager(RelationTable table);

SelectManager select_manager_project(SelectManager select_manager, char *literal);

SelectManager select_manager_from(SelectManager select_manager, RelationTable table);


#endif