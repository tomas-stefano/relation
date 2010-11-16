#include <ruby.h>
#include "relation_table.h"

void Init_relation_table() {
	VALUE module_relation = rb_define_module("Relation");
	VALUE class_table = rb_define_class_under(module_relation, "Table", rb_cObject);
}