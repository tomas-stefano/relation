
#include <ruby.h>

/* 
* Relation C Library 
*/
#include "relation.h"
#include "relation/table.h"

#include "relation_table.h"

static VALUE allocate_relation_table(VALUE klass) {
	RelationTable table;
	VALUE object;
	table = new_relation_table("users");
	// object = Data_Wrap_Struct(klass, 0, relation_table_free, table);
	return object;
}

VALUE relation_table_limit_wrapper(VALUE self) {
	return self;
}

VALUE relation_table_select_wrapper(VALUE self) {	
	return self;
}

void Init_relation_table() {
	VALUE module_relation = rb_define_module("Relation");
	VALUE class_table = rb_define_class_under(module_relation, "Table", rb_cObject);

	/* Allocate funtion to handle with C structs */
	rb_define_alloc_func(class_table, allocate_relation_table);
	
	/* Instance Methods */
	rb_define_method(class_table, "select", relation_table_select_wrapper, 1);
	rb_define_method(class_table, "limit", relation_table_limit_wrapper, 1);
}