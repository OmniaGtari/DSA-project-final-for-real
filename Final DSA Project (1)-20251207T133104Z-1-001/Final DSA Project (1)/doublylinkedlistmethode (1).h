#ifndef  DOUBLYLINKEDLISTMETHODE_H
#define  DOUBLYLINKEDLISTMETHODE_H
#include "doublylinkedlist.h"

node_loan* createnode(loan l);
void destroynode_loan(node_loan* p);
doublylist* createdoublylist();
bool isEmpty(const doublylist& L);
bool isFull(const doublylist& L);
int listSize(const doublylist& L);
void insertdoublylist(doublylist* L, loan l, int pos);
int removeAtdoublylist(doublylist* L, int pos);
loan getElementdoublylist(const doublylist& L, int pos);
void displayList(const doublylist& L);



#endif