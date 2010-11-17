#include "relation_select_manager.h"

VALUE relation_select_manager_select(VALUE self, VALUE literal) {
	return self;
}

void Init_relation_select_manager() {
	class_SelectManager = rb_define_class_under(module_Relation, "SelectManager", class_TreeManager);

	/* Instance methods*/
	rb_define_method(class_SelectManager, "select", relation_select_manager_select, 1);
}