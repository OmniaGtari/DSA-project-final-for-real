#include "singlylinkedlistmethode.h"
#include <iostream>
using namespace std;
node_loan_completed* createnodeloan_complete(loan l) {
	node_loan_completed* p = new (nothrow) node_loan_completed{ l , nullptr };
	if (!p) {
		cerr << "\nMemoryallocation failed for node\n";
	};
	return p;
};
void destroynode_loan_completed(node_loan_completed* p) {
	delete p;
};
singlylist* createsinglylist() {
	singlylist* l = new (nothrow) singlylist;
	if (!l) {
		std::cerr << "\nMemory allocation failed for list\n";
		return nullptr;
	}
	l->head = nullptr;
	l->size = 0;
	return l;
}
bool isEmptys(const singlylist& L) {
	return L.size == 0;
}
int listSize(const singlylist& L) {
	return L.size;
}
//displaylist of loan it display id of loan
void displayList(const singlylist& L) {
	if (isEmptys(L)) {
		cout << "List is empty\n";
		return;
	}
	node_loan_completed* current = L.head;
	while (current) {
		cout << current->completed_loan.loan_ID << " -> ";
		current = current->next;
	}
	cout << "NULL\n";
}
int removeAtsinglylist(singlylist* L, int pos) {

	if (!L || isEmptys(*L)) {
		cerr << "\nListis empty";
		return 0;
	}
	if (pos < 1 || pos > L->size) {
		cerr << "\nInvalidposition";
		return 0;
	}
	node_loan_completed* prev = nullptr;
	node_loan_completed* current = L->head;

	if (pos == 1) {
		L->head = current->next;
	}
	else {
		for (int i = 1; i < pos; i++) {
			prev = current;
			current = current->next;
		}
		prev->next = current->next;
	}
	destroynode_loan_completed(current);
	L->size--;
	return 1;
};
void  insertsinglylist(singlylist* L, loan l, int pos) {
	if (!L) {
		cout << "list invalide ";
		return;
	};
	if (pos < 1 || pos > L->size + 1) {
		cout << "\nInvalidposition";
	}
	node_loan_completed* n = createnodeloan_complete(l);
	if (!n) {
		cout << "insertion invalide" << endl;
		return;
	};
	if (pos == 1) {
		n->next = L->head;
		L->head = n;
	}

	else {
		node_loan_completed* prv = nullptr;
		node_loan_completed* current = L->head;
		for (int i = 1; i < pos; i++) {
			prv = current;
			current = current->next;
		}
		prv->next = n;
		n->next = current;
	}
	L->size++;
}
loan getElementsinglylist(const singlylist& L, int pos) {
	if (isEmptys(L)) {
		cerr << "\nList is empty\n";
		return loan{};
	}
	if (pos < 1 || pos > L.size) {
		cerr << "\nInvalid position\n";
		return loan{};
	}
	node_loan_completed* current = L.head;
	for (int i = 1; i < pos; i++) {
		current = current->next;
	}
	return current->completed_loan;

};