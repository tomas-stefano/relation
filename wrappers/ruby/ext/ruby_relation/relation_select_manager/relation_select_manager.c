#include <ruby.h>

VALUE relation_select_manager_select(VALUE self, VALUE literal) {
	return self;
}

void Init_relation_select_manager() {
	VALUE relation_module = rb_define_module("Relation");
	VALUE select_manager_class = rb_define_class_under(relation_module, "SelectManager", rb_cObject);
	
	/* Instance methods*/
	rb_define_method(select_manager_class, "select", relation_select_manager_select, 1);
}