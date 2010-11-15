#ifndef TO_SQL_H
#define TO_SQL_H

char *visit_relation_table(RelationTable table);

char *visit_select_statements(SelectStatement abstract_syntax_tree);

char *to_sql_visit(SelectStatement abstract_syntax_tree);

#endif