#include "relations.h"

VALUE module_Relation;
VALUE class_TreeManager;
VALUE class_SelectManager;
VALUE class_Table;

void Init_relations() {
	module_Relation = rb_define_module("Relation");
	Init_relation_tree_manager();
	Init_relation_select_manager();
	Init_relation_table();
}