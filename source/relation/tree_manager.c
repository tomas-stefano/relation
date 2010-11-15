#include <string.h>
#include "relation.h"
#include "relation/visitors/visitor.h"

/* 
*
*  I don't know how to implement the Visitors Pattern in C 
*
*/
char *relation_to_sql(SelectManager manager) {
	return visitor_accept(manager.abstract_syntax_tree);
}