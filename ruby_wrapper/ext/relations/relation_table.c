#include "relation_table.h"

static ID id_limit;
static ID id_select;
static ID id_where;

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

VALUE relation_table_from_wrapper(VALUE self) {
	VALUE argv[1];
	argv[0] = self;
	return rb_class_new_instance(1, argv, class_SelectManager);
}

VALUE relation_table_limit_wrapper(VALUE self, VALUE limit) {
	return rb_funcall(relation_table_from_wrapper(self), id_limit, 1, limit);
}

VALUE relation_table_select_wrapper(VALUE self, VALUE projections) {
	return rb_funcall(relation_table_from_wrapper(self), id_select, 1, projections);
}

VALUE relation_table_where_wrapper(VALUE self, VALUE conditions) {
	return rb_funcall(relation_table_from_wrapper(self), id_where, 1, conditions);
}

void Init_relation_table() {
	class_Table = rb_define_class_under(module_Relation, "Table", rb_cObject);

	/* Allocate funtion to handle with C structs */
	rb_define_alloc_func(class_Table, allocate_relation_table);
	
	/* Instance Methods */
	rb_define_method(class_Table, "initialize", relation_table_initialize, 1);
	rb_define_method(class_Table, "name", relation_table_get_name, 0);
	rb_define_method(class_Table, "select", relation_table_select_wrapper, 1);
	rb_define_method(class_Table, "limit", relation_table_limit_wrapper, 1);
	rb_define_method(class_Table, "where", relation_table_where_wrapper, 1);

	/* Name Methods to call */
	id_select = rb_intern("select");
	id_limit = rb_intern("limit");
	id_where = rb_intern("where");
}