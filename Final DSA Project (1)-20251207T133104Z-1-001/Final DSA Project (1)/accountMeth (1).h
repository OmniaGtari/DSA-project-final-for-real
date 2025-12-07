#ifndef ACCOUNTMETH_H
#define ACCOUNTMETH_H

#include "customer.h"
#include <string>
using namespace std;

bool addAccount(Account Accounts[], int& maxaccount, const Account& newAcc);
void displayAccounts(const Account Accounts[], int maxaccount);
bool changeAccountStatus(Account Accounts[], int maxaccount, int accNum, const string& newStatus);
void archiveClosedAccounts(Account Accounts[], int& maxaccount, Account archivedAccounts[], int& archivedCount);
Account* findAccount(Account Accounts[], int maxaccount, int accNum);

#endif
