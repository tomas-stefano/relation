#include "nodes.h"

VALUE module_Relation;
VALUE module_Nodes;
VALUE class_SqlLiteral;

void Init_nodes() {
	module_Relation = rb_define_module("Relation");
	module_Nodes = rb_define_module_under(module_Relation, "Nodes");
	Init_sql_literal();
}