#ifndef SINGLYLINKEDLIST_H
#define SINGLYLINKEDLIST_H
#include "loan.h"

struct node_loan_completed {
	loan completed_loan;
	node_loan_completed* next;
};

struct singlylist {
	node_loan_completed* head;
	int size;
};

#endif