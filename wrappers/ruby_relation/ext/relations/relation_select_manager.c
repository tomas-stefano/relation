#include "relation_select_manager.h"

// void allocate_select_manager() {
// 	SelectManager *select_manager = new_select_manager();
// }

VALUE relation_select_manager_select(VALUE self, VALUE literal) {
	return self;
}

void Init_relation_select_manager() {
	class_SelectManager = rb_define_class_under(module_Relation, "SelectManager", class_TreeManager);
	
	/* Allocate funtion to handle with C structs */
	// rb_define_alloc_func(class_SelectManager, allocate_select_manager);
	
	/* Instance methods*/
	rb_define_method(class_SelectManager, "select", relation_select_manager_select, 1);
}