#ifndef DATACUSTOMER_H
#define DATACUSTOMER_H
#include "customer.h"

extern doublylist* loans1;
extern doublylist* loans2;
extern doublylist* loans3;
extern doublylist* loans4;
extern doublylist* loans5;

extern stack* transaction1;
extern stack* transaction2;
extern stack* transaction3;
extern stack* transaction4;
extern stack* transaction5;


void initialize_account(doublylist* loans1, doublylist* loans2, doublylist* loans3, doublylist* loans4, doublylist* loans5);

const int MAX = 10000;
extern Account Accounts[MAX];
extern int accountCount;

extern Account archivedAccounts[MAX];
extern int archivedCount;


#endif
