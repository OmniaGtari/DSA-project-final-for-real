#ifndef STACKMETHODE_H
#define STACKMETHODE_H
#include <iostream>
#include "stack.h"
#include "transaction.h"


using namespace std;
stack* createstack();
void destroystack(stack* s);
bool isFull(const stack& s);
bool isEmpty(const stack& s);
bool push(stack* s, transaction t);
transaction pop(stack* s);
int stackSize(const stack* s);
void displayStack(const stack* s);

#endif
