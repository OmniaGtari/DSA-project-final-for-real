#include "accountMeth.h"
#include "datacustomer.h"
#include <iostream>
using namespace std;

// Add a new account
bool addAccount(Account Accounts[], int& count, const Account& acc)
{
    if (count >= 10000) {
        cout << "Error: Maximum number of accounts reached.\n";
        return false;
    }

    // Prevent duplicate account number
    for (int i = 0; i < count; i++) {
        if (Accounts[i].accountNumber == acc.accountNumber) {
            cout << "Error: Account number already exists.\n";
            return false;
        }
    }

    // Safe copy
    Accounts[count] = acc;

    // Initialize pointers (if any)
    Accounts[count].loan = nullptr;
    Accounts[count].Transaction = nullptr;

    count++;
    return true;
}

// Display all accounts
void displayAccounts(const Account Accounts[], int maxaccount) {
    if (maxaccount == 0) {
        cout << "No accounts to display.\n";
        return;
    }

    for (int i = 0; i < maxaccount; i++) {
        cout << "-----------------------------\n";
        cout << "Account Number: " << Accounts[i].accountNumber << "\n";
        cout << "Holder Name:    " << Accounts[i].holderName << "\n";
        cout << "IBAN:           " << Accounts[i].IBAN << "\n";
        cout << "Account Type:   " << Accounts[i].accountType << "\n";
        cout << "Branch Code:    " << Accounts[i].branchCode << "\n";
        cout << "Opening Date:   " << Accounts[i].openingDate << "\n";
        cout << "Status:         " << Accounts[i].status << "\n";
        cout << "Balance:        " << Accounts[i].balance << " TND\n";
    }
}

// Change account status
bool changeAccountStatus(Account Accounts[], int maxaccount, int accNum, const string& newStatus) {
    for (int i = 0; i < maxaccount; i++) {
        if (Accounts[i].accountNumber == accNum) {
            Accounts[i].status = newStatus;
            return true;
        }
    }
    return false;
}

// Archive closed accounts
void archiveClosedAccounts(Account Accounts[], int& maxaccount, Account archivedAccounts[], int& archivedCount) {
    int i = 0;

    while (i < maxaccount) {
        if (Accounts[i].status == "Closed") {
            cout << "Archiving account " << Accounts[i].accountNumber << endl;

            archivedAccounts[archivedCount++] = Accounts[i];

            // Shift left to remove from active list
            for (int j = i; j < maxaccount - 1; j++) {
                Accounts[j] = Accounts[j + 1];
            }
            maxaccount--; // reduce active account count
        }
        else {
            i++;
        }
    }
}

// Find account by number
Account* findAccount(Account Accounts[], int maxaccount, int accNum) {
    for (int i = 0; i < maxaccount; i++) {
        if (Accounts[i].accountNumber == accNum) {
            return &Accounts[i];
        }
    }
    return nullptr;
}