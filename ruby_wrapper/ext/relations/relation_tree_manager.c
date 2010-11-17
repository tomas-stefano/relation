#include "relation_tree_manager.h"

VALUE tree_manager_to_sql(VALUE self) {
	return self;
}

void Init_relation_tree_manager() {
	class_TreeManager = rb_define_class_under(module_Relation, "TreeManager", rb_cObject);
	
	/* Instance Methods */
	rb_define_method(class_TreeManager, "to_sql", tree_manager_to_sql, 0);
}