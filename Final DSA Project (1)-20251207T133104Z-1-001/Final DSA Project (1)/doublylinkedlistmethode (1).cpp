#include "doublylinkedlistmethode.h"
#include <iostream>
using namespace std;
node_loan* createnode(loan l) {
	node_loan* p = new (nothrow) node_loan{ l , nullptr , nullptr };
	if (!p) {
		cerr << "\nMemoryallocation failed for node\n";
	};
	return p;
};
void destroynode_loan(node_loan* p) {
	delete p;
};
doublylist* createdoublylist() {
	doublylist* list = new (nothrow) doublylist;
	if (!list) {
		cerr << "\nMemory allocation failed for list\n";
		return nullptr;
	}
	list->head = nullptr;
	list->size = 0;
	list->tail = nullptr;
	return list;
};
bool isEmpty(const doublylist& L) {
	return L.size == 0;
}
bool isFull(const doublylist& L) {
	node_loan* p = new (nothrow) node_loan;
	if (!p) {
		return true;
	}
	else {
		destroynode_loan(p);
		return false;
	}
}
int listSize(const doublylist& L) {
	return L.size;
}
//displaylist of loan it display id of loan
void displayList(const doublylist& L) {
	if (isEmpty(L)) {
		cout << "List is empty\n";
		return;
	}
	node_loan* current = L.head;
	while (current) {
		cout << "the ID of the loan is: " << current->l.loan_ID << endl;
		cout << "the type of the loan is: " << current->l.Type << endl;
		cout << "the principle amount of the loan is: " << current->l.Principal_amount << endl;
		cout << "the interest rate of the loan is: " << current->l.Interest_rate << endl;
		cout << "the amount paid of the loan is: " << current->l.Amount_paid << endl;
		cout << "the remaining balance of the loan is: " << current->l.Remaining_balance << endl;
		cout << "the start date of the loan is: " << current->l.Start_date << endl;
		cout << "the end date of the loan is: " << current->l.End_date << endl;
		cout << "the status of the loan is: " << current->l.Status << endl;
		current = current->next;
	}
};
int removeAtdoublylist(doublylist* L, int pos) {
	if (!L || isEmpty(*L)) {
		cout << "\nListis empty";
		return 0;
	}
	if (pos < 1 || pos > L->size) {
		cout << "\nInvalidposition";
		return 0;
	}
	node_loan* current;
	if (L->size == 1) {
		current = L->head;
		L->head = nullptr;
		L->tail = nullptr;
	}
	else if (pos == 1) {
		current = L->head;
		L->head = L->head->next;
		L->head->prv = nullptr;
	}
	else if (pos == L->size) {
		current = L->tail;
		L->tail = L->tail->prv;
		L->tail->next = nullptr;
	}
	else {
		node_loan* prevNode = nullptr;
		current = L->head;
		for (int i = 1; i < pos; i++) {
			prevNode = current;
			current = current->next;
		}
		current->next->prv = prevNode;
		prevNode->next = current->next;
	}
	destroynode_loan(current);
	L->size--;
	return 1;
};
void insertdoublylist(doublylist* L, loan loan, int pos) {
	if (!L) {
		cout << "list invalide ";
	};
	if (pos < 1 || pos > L->size + 1) {
		cout << "Invalide position";
	}
	node_loan* n = createnode(loan);
	if (!n) {
		cout << " Invalide insertion ";
	}
	if (isEmpty(*L)) {
		L->head = n;
		L->tail = n;

	}
	else if (pos == 1) {
		n->next = L->head;
		L->head->prv = n;
		L->head = n;

	}
	else if (pos == L->size + 1) {
		n->prv = L->tail;
		L->tail->next = n;
		L->tail = n;
	}
	else {
		node_loan* current = L->head;
		for (int i = 1; i < pos; i++) {
			current = current->next;
		}
		n->next = current;
		n->prv = current->prv;
		current->prv->next = n;
		current->prv = n;
	}
	L->size++;
};
loan getElementdoublylist(const doublylist& L, int pos) {
	if (isEmpty(L)) {
		cerr << "\nList is empty\n";
		return loan{};
	}
	if (pos < 1 || pos > L.size) {
		cerr << "\nInvalid position\n";
		return loan{};
	}
	node_loan* current = L.head;
	for (int i = 1; i < pos; i++) {
		current = current->next;
	}
	return current->l;

};