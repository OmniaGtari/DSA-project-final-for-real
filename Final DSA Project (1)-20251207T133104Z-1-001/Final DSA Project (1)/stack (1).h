#ifndef STACK_H
#define STACK_H
#include "transaction.h"
const int Max = 1000;
struct stack {
	transaction  element[Max];
	int top;
};
#endif
