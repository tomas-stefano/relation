#include "relation.h"
#include "to_sql.h"
#include "visitor.h"

/*

 I NEED STUDY HOW I IMPLEMENT THE VISITORS PATTERN IN C!!!! I DON'T KNOW!

*/

char *visitor_accept(SelectStatement abstract_syntax_tree) {
	return to_sql_visit(abstract_syntax_tree);
}
