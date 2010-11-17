#include "relations.h"

VALUE module_Relation;

void Init_relations() {
	module_Relation = rb_define_module("Relation");
	Init_relation_select_manager();
	Init_relation_table();
}