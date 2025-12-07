#ifndef ACCOUNT_H
#define ACCOUNT_H
#include "loan.h"
#include "transaction.h"
#include "doublylinkedlist.h"
#include "stack.h"
#include <string>
using namespace std;

struct Account {
    int accountNumber;
    string accountType;
    string IBAN;
    int branchCode;
    string holderName;
    string openingDate;
    string status;           // active, inactive, closed
    double balance;
    doublylist* loan;
    stack* Transaction;
    doublylist* loans;
};

#endif
