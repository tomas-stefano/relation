#include "relation_table.h"

static void relation_table_free(void *pointer) {
	free(pointer);
}

static VALUE allocate_relation_table(VALUE klass) {
	RelationTable *table = new_relation_table();
	VALUE object;
	object = Data_Wrap_Struct(klass, 0, relation_table_free, table);
	return object;
}

VALUE relation_table_initialize(VALUE self, VALUE name) {
	RelationTable *table;
	Data_Get_Struct(self, RelationTable, table);
	table_instance_name(table, StringValuePtr(name));
	return self;
}

VALUE relation_table_get_name(VALUE self) {
	RelationTable *table;
	Data_Get_Struct(self, RelationTable, table);
	return rb_str_new2(table->name);
}

VALUE relation_table_limit_wrapper(VALUE self) {
	RelationTable *table;
	Data_Get_Struct(self, RelationTable, table);
	return self;
}

VALUE relation_table_select_wrapper(VALUE self) {
	RelationTable *table;
	Data_Get_Struct(self, RelationTable, table);
	return self;
}

void Init_relation_table() {
	VALUE module_relation = rb_define_module("Relation");
	VALUE class_table = rb_define_class_under(module_relation, "Table", rb_cObject);

	/* Allocate funtion to handle with C structs */
	rb_define_alloc_func(class_table, allocate_relation_table);
	
	/* Instance Methods */
	rb_define_method(class_table, "initialize", relation_table_initialize, 1);
	rb_define_method(class_table, "name", relation_table_get_name, 0);
	rb_define_method(class_table, "select", relation_table_select_wrapper, 1);
	rb_define_method(class_table, "limit", relation_table_limit_wrapper, 1);
}