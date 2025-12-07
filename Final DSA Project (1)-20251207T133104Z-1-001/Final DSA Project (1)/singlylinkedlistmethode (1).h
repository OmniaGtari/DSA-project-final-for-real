#ifndef SINGLYLINKEDLISTMETHODE_H
#define SINGLYLINKEDLISTMETHODE_H
#include "singlylinkedlist.h"
#include <iostream>

node_loan_completed* createnodeloan_complete(loan l);
void destroynode_loan_completed(node_loan_completed* p);
singlylist* createsinglylist();
bool isEmptys(const singlylist& L);
int listSize(const singlylist& L);
void insertsinglylist(singlylist* L, loan l, int pos);
int removeAtsinglylist(singlylist* L, int pos);
loan getElementsinglylist(const singlylist& L, int pos);
void displayList(const singlylist& L);

#endif
