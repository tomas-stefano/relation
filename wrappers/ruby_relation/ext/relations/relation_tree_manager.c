#include "relation_tree_manager.h"

void Init_relation_tree_manager() {
	class_TreeManager = rb_define_class_under(module_Relation, "TreeManager", rb_cObject);
}