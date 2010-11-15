#ifndef VISITOR_H
#define VISITOR_H

char *visitor_accept(SelectStatement abstract_syntax_tree);

char *visitor_visit(SelectStatement abstract_syntax_tree);

#endif