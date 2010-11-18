#include "sql_literal.h"

void Init_sql_literal() {
	class_SqlLiteral = rb_define_class_under(module_Nodes, "SqlLiteral", rb_cString);
}