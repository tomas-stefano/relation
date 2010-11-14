
#ifndef RELATION_H /* if not defined Sql Relation header */
#define RELATION_H
	#define RelationVersion "0.1.0"

typedef struct relation_table {
	char *name;
} RelationTable;
	
typedef struct manager_select {

} SelectManager;

typedef struct sql_literal_name {
	char *literal;
} SqlLiteral;

#endif
 /* end if */