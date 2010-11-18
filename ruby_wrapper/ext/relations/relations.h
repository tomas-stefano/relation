#ifndef RELATION_WRAPPER_H
#define RELATION_WRAPPER_H

#include <ruby.h>
#include <stdlib.h>

/* 
* Relation C Library 
*/
#include "relation.h"
#include "relation/select_manager.h"
#include "relation/table.h"
#include "relation/tree_manager.h"
#include "relation/visitors/to_sql.h"
#include "relation/visitors/visitor.h"

extern VALUE module_Relation;
extern VALUE class_Table;
extern VALUE class_TreeManager;
extern VALUE class_SelectManager;
	
/* 
* Relation Wrapper Library
*/
#include <relation_table.h>
#include <relation_tree_manager.h>
#include <relation_select_manager.h>

#endif