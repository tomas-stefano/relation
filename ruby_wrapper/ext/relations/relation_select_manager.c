#include "relation_select_manager.h"

static void free_select_manager(SelectManager *pointer) {
	free(pointer);
}

static VALUE allocate_select_manager(VALUE klass) {
	SelectManager *select_manager = new_select_manager();
	VALUE object;
	object = Data_Wrap_Struct(klass, 0, free_select_manager, select_manager);
	return object;
}

VALUE relation_select_manager_initialize(VALUE self, VALUE table) {
	RelationTable *relation_table;
	Data_Get_Struct(table, RelationTable, relation_table);
	SelectManager *select_manager;
	Data_Get_Struct(self, SelectManager, select_manager);
	select_manager_instance_table(select_manager, relation_table);
	return self;
}

VALUE relation_select_manager_select_wrapper(VALUE self, VALUE projections) {
	SelectManager *select_manager;
	Data_Get_Struct(self, SelectManager, select_manager);
	long i;
	
	for(i = 0; i < RARRAY_LEN(projections); i++) {
		select_manager_project(select_manager, StringValuePtr(RARRAY_PTR(projections)[i]));
	}
	
	return self;
}

VALUE relation_select_manager_limit_wrapper(VALUE self, VALUE limit) {
	SelectManager *select_manager;
	Data_Get_Struct(self, SelectManager, select_manager);
	select_manager_limit(select_manager, FIX2INT(limit));
	return self;
}

VALUE relation_select_manager_where_wrapper(VALUE self, VALUE conditions) {
	SelectManager *select_manager;
	Data_Get_Struct(self, SelectManager, select_manager);
	select_manager_where(select_manager, StringValuePtr(conditions));
	return self;
}

VALUE relation_select_manager_order_wrapper(VALUE self, VALUE expression) {
	SelectManager *select_manager;
	Data_Get_Struct(self, SelectManager, select_manager);
	select_manager_order(select_manager, StringValuePtr(expression));
	return self;
}

VALUE relation_select_manager_offset_wrapper(VALUE self, VALUE offset_number) {
	SelectManager *select_manager;
	Data_Get_Struct(self, SelectManager, select_manager);
	select_manager_offset(select_manager, FIX2INT(offset_number));
	return self;
}

VALUE relation_select_manager_group_wrapper(VALUE self, VALUE group) {
	SelectManager *select_manager;
	Data_Get_Struct(self, SelectManager, select_manager);
	select_manager_group(select_manager, StringValuePtr(group));
	return self;
}

VALUE relation_select_manager_having_wrapper(VALUE self, VALUE expression) {
	SelectManager *select_manager;
	Data_Get_Struct(self, SelectManager, select_manager);
	select_manager_having(select_manager, StringValuePtr(expression));
	return self;
}

void Init_relation_select_manager() {
	class_SelectManager = rb_define_class_under(module_Relation, "SelectManager", class_TreeManager);
	
	/* Allocate funtion to handle with C structs */
	rb_define_alloc_func(class_SelectManager, allocate_select_manager);
	
	/* Instance methods*/
	rb_define_method(class_SelectManager, "initialize", relation_select_manager_initialize, 1);
	rb_define_method(class_SelectManager, "select", relation_select_manager_select_wrapper, -2);
	rb_define_method(class_SelectManager, "limit", relation_select_manager_limit_wrapper, 1);
	rb_define_method(class_SelectManager, "where", relation_select_manager_where_wrapper, 1);
	rb_define_method(class_SelectManager, "order", relation_select_manager_order_wrapper, 1);
	rb_define_method(class_SelectManager, "offset", relation_select_manager_offset_wrapper, 1);
	rb_define_method(class_SelectManager, "group", relation_select_manager_group_wrapper, 1);
	rb_define_method(class_SelectManager, "having", relation_select_manager_having_wrapper, 1);
}
