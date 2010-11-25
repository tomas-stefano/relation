#include <stdlib.h>
#include <stdio.h>

#include "relation.h"
#include "relation/sql_literal.h"
#include "relation/table.h"
#include "relation/select_manager.h"
#include "relation/tree_manager.h"
#include "relation/visitors/to_sql.h"

void create_simple_query(RelationTable *developers) {
	SelectManager *manager = relation_table_limit(developers, 1);
	select_manager_project(manager, new_sql_literal("*"));
	relation_to_sql(manager);	
}

int main() {
	int i = 0;

	RelationTable *developers;
	developers = new_relation_table();
	table_instance_name(developers, "developers");
	
	printf("Generating query: SELECT * from developers LIMIT 1\n");
	
	for(; i < 10000; i++) {
		create_simple_query(developers);
	}
	
	return 0;
}