#ifndef TO_SQL_H
#define TO_SQL_H

char *visit_relation_table(RelationTable *table, char *query);

char *visit_select_statements(SelectStatement abstract_syntax_tree);

char *visit_syntax_tree_projections(SelectStatement ast, char *query);

char *visit_relation_where(SelectStatement ast, char *query);

char *to_sql_visit(SelectStatement abstract_syntax_tree);

char *_assign_select_string();

#define SELECT "SELECT "
#define SELECT_SIZE 7
#define FROM "FROM "
#define FROM_SIZE 5
#define WHERE "WHERE "

#endif