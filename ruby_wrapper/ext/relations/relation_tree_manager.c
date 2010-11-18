#include "relation_tree_manager.h"

VALUE tree_manager_to_sql(VALUE self) {
	SelectManager *select_manager;
	Data_Get_Struct(self, SelectManager, select_manager);
	return rb_str_new2(to_sql_visit(select_manager->abstract_syntax_tree));
}

void Init_relation_tree_manager() {
	class_TreeManager = rb_define_class_under(module_Relation, "TreeManager", rb_cObject);
	
	/* Instance Methods */
	rb_define_method(class_TreeManager, "to_sql", tree_manager_to_sql, 0);
}