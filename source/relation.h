
#ifndef RELATION_H /* if not defined Sql Relation header */
#define RELATION_H
	#define RelationVersion "0.1.0"

typedef struct relation_table {
	char *name;
} RelationTable;

typedef char *SqlLiteral;

typedef struct select_statement {
	int limit;
	SqlLiteral *projections;
	RelationTable froms;
} SelectStatement;
	
typedef struct manager_select {
	SelectStatement abstract_syntax_tree;
} SelectManager;


#endif
 /* end if */