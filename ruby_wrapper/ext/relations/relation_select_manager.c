#include "relation_select_manager.h"

static void free_select_manager(void *pointer) {
	free(pointer);
}

static VALUE allocate_select_manager(VALUE klass) {
	SelectManager *select_manager = new_select_manager();
	VALUE object;
	object = Data_Wrap_Struct(klass, 0, free_select_manager, select_manager);
	return object;
}

VALUE relation_select_manager_initialize(VALUE self, VALUE table) {
	return self;
}

VALUE relation_select_manager_select(VALUE self, VALUE projections) {
	// SelectManager *select_manager;
	// Data_Get_Struct(self, SelectManager, select_manager);
	// long i;
	// 
	// for(i = 0; i < RARRAY_LEN(projections); i++) {
	// 	RARRAY_PTR(projections)[i]
	// }
	return self;
}

void Init_relation_select_manager() {
	class_SelectManager = rb_define_class_under(module_Relation, "SelectManager", class_TreeManager);
	
	/* Allocate funtion to handle with C structs */
	rb_define_alloc_func(class_SelectManager, allocate_select_manager);
	
	/* Instance methods*/
	rb_define_method(class_SelectManager, "initialize", relation_select_manager_initialize, 1);
	rb_define_method(class_SelectManager, "select", relation_select_manager_select, -2);
}