
#ifndef RELATION_H /* if not defined Sql Relation header */
#define RELATION_H
#define RelationVersion "0.1.0"

typedef struct relation_table {
	char *name; /* Table name */
} RelationTable;

typedef char *SqlLiteral; /* Alias for pointer to char */

/* TODO: Remove this and change to ArraySqlLiterals */
typedef struct projections_node {
   SqlLiteral sql_literal;
   struct projections_node *next;
} Projections;

typedef struct sql_literals {
	SqlLiteral sql_literal;
	struct sql_literals *next;
} ArraySqlLiterals;

typedef struct statement {
	Projections *projections;  /* Nodes(Linked Lists) of SqlLiterals */
	RelationTable *froms;      /* Table */
	ArraySqlLiterals *wheres;  /* Nodes(Linked Lists) of SqlLiterals */
	int limit;                 /* Limit */
} SelectStatement;
	
typedef struct manager_select {
	SelectStatement abstract_syntax_tree;
} SelectManager;

#endif
 /* end if */