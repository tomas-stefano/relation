
#ifndef RELATION_H /* if not defined Sql Relation header */
#define RELATION_H
#define RelationVersion "0.1.0"

typedef struct relation_table {
	char *name; /* Table name */
	long long name_size;
} RelationTable;

typedef char *SqlLiteral; /* Alias for pointer to char */

typedef struct sql_literals {
	SqlLiteral sql_literal;
	struct sql_literals *next;
} ArraySqlLiterals;

typedef struct statement {
	ArraySqlLiterals *projections;      /* Nodes(Linked Lists) of SqlLiterals */
	ArraySqlLiterals *projections_tail; /* Pointer to tail of projections */
	RelationTable *froms;               /* Table */
	ArraySqlLiterals *wheres;           /* Nodes(Linked Lists) of SqlLiterals */
	ArraySqlLiterals *wheres_tail;      /* Pointer to tail of wheres */
	SqlLiteral orders;					/* ORDER BY */
	int offset;							/* OFFSET */
	long long limit;                          /* LIMIT */
	ArraySqlLiterals *groups;           /* GROUP BY */
	ArraySqlLiterals *groups_tail;      /* GROUP BY */	
	SqlLiteral having;
} SelectStatement;
	
typedef struct manager_select {
	SelectStatement abstract_syntax_tree;
} SelectManager;

#endif
 /* end if */