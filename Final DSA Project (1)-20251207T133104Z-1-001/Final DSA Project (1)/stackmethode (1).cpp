#include "stackmethode.h"
#include <iostream>
using namespace std;

stack* createstack() {
	stack* s = new stack;
	s->top = 0;
	return s;
};
void destroystack(stack* s) {
	delete s;
};
bool isFull(const stack& s) {
	return s.top == Max;
};
bool isEmpty(const stack& s) {
	return s.top == 0;
};
bool push(stack* s, transaction t) {
	if (!s) {
		cerr << "stack is invalid " << endl;
		return false;
	}
	if (isFull(*s)) {
		cerr << "stack is full " << endl;
		return false;
	}
	s->element[s->top] = t;
	s->top++;
	return true;
};
transaction pop(stack* s) {
	transaction t = {};
	if (isEmpty(*s)) {
		cerr << "stack is empty " << endl;
	}
	else {
		t = s->element[s->top];
		s->top--;

	}
	return t;

};
int stackSize(const stack& s) {
	if (!s) {
		cerr << "stack is invalid " << endl;
		return -1;
	}
	return s->top;
};
void displayStack(const stack& s) {
	if (!s) {
		cerr << "stack is invalid " << endl;
		return;
	}
	if (isEmpty(*s)) {
		cerr << "stack is empty " << endl;
		return;
	}
	for (int i = s->top - 1; i >= 0; i--) {
		cout << "Transaction ID: " << s->element[i].Transaction_ID << ", Account Number: " << s->element[i].Account_Number
			<< ", Type: " << s->element[i].Type << ", Amount: " << s->element[i].Amount
			<< ", Date: " << s->element[i].Date << endl;
	}
};
