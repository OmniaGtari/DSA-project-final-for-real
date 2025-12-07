#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H
#include "loan.h"
#include <iostream>
using  namespace std;

struct node_loan {
	loan l;
	node_loan* next;
	node_loan* prv;
};

struct doublylist {
	node_loan* head;
	node_loan* tail;
	int size;
};
#endif
