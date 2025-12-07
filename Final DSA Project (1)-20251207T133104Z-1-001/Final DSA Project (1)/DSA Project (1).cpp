#include<iostream>
#include <string>
#include "doublylinkedlistmethode.h"
#include "singlylinkedlistmethode.h"
#include "stackmethode.h"
#include "employeedata.h"
#include "datacustomer.h"
#include "accountMeth.h"
#include "employeeMeth.h"
#include "statistics.h"
using namespace std;
int idtransaction = 91020;
Account accounts[MAX];
int accountCount = 0;
Account archivedAccounts[10000];
int archivedCount = 0;
doublylist* loan_request = createdoublylist();
stack* daily_transaction_log = createstack();
// the customer interface 
int login(Account Accounts[], int acc_number, int size) {
    int test = -1;
    int i = 0;
    while (test == -1 && i < size) {
        if (Accounts[i].accountNumber == acc_number)
            test = i;
        i++;
    };
    return test;
};
int loginemployee(Employee employees[], int emp_id, int size1) {
    int test = -1;
    int i = 0;
    while (test == -1 && i < size1) {
        if (employees[i].id == emp_id)
            test = i;
        i++;
    };
    return test;
};

void customer_interface(Account Accounts[], int maxaccount, int c, doublylist* loan_request) {
    char operation;
    do {
        cout << "______________________________________________" << endl;
        cout << "        welcome to customer intefrace !" << endl;
        cout << "______________________________________________" << endl;
        cout << "______________________________________________" << endl;
        cout << "______________what do you want________________" << endl;
        cout << "______________________________________________" << endl;
        cout << "______________________________________________" << endl;
        cout << "         1- view the list of loans            " << endl;
        cout << "         2- submit a new loan                 " << endl;
        cout << "         3- Withdrow money                    " << endl;
        cout << "         4- Deposit money                     " << endl;
        cout << "         5- view transaction history          " << endl;
        cout << "         6- undo last transaction             " << endl;
        cout << "         0- Exit                              " << endl;
        cout << "______________________________________________" << endl;
        cout << "______________________________________________" << endl;
        cin >> operation;
        if (operation == '1') {
            doublylist* l = Accounts[c].loan;
            //displayList(&L);//list of id  loans of the customer ;
            displayList(*l);
        }
        else if (operation == '3') {
            cout << "________________________________________" << endl;
            cout << "________________________________________" << endl;
            cout << " enter the amount of money to withdraw :" << endl;
            cout << "________________________________________" << endl;
            cout << "________________________________________" << endl;
            cout << "            choice 1: 10                " << endl;
            cout << "            choice 2: 20                " << endl;
            cout << "            choice 3: 50                " << endl;
            cout << "________________________________________" << endl;
            cout << "________________________________________" << endl;
            char choice;
            cin >> choice;
            cin.ignore(); // Clear the newline character from buffer

            string date;
            cout << "enter the date (DD/MM/YYYY): " << endl;
            getline(cin, date);

            cout << "your current balance is:  " << Accounts[c].balance << endl;
            if (choice == '1') {
                //withdraw 10
                Accounts[c].balance -= 10;
                cout << "your  new current balance is:  " << Accounts[c].balance << endl;
                transaction t = { idtransaction, Accounts[c].accountNumber, "Withdrawal", 10, date };
                idtransaction++;
                push(Accounts[c].Transaction, t);
            }
            else if (choice == '2') {
                //withdraw 20
                Accounts[c].balance -= 20;
                cout << "your new current balance is:  " << Accounts[c].balance << endl;
                transaction t = { idtransaction, Accounts[c].accountNumber, "Withdrawal", 20, date };
                idtransaction++;
                push(Accounts[c].Transaction, t);
            }
            else if (choice == '3') {
                //withdraw 50
                Accounts[c].balance -= 50;
                cout << "your new current balance is:  " << Accounts[c].balance << endl;
                transaction t = { idtransaction, Accounts[c].accountNumber, "Withdrawal", 50, date };
                idtransaction++;
                push(Accounts[c].Transaction, t);
            }
        }
        else if (operation == '4') {
            cout << "your current balance is:  " << Accounts[c].balance << endl;
            cout << "_______________________________________" << endl;
            cout << "_______________________________________" << endl;
            cout << " enter the amount of money to deposit :" << endl;
            cout << "_______________________________________" << endl;
            cout << "_______________________________________" << endl;
            int amount;
            cin >> amount;
            cin.ignore(); // Clear the newline character from buffer

            string date;
            cout << "enter the date (DD/MM/YYYY): " << endl;
            getline(cin, date);

            //deposit amount
            Accounts[c].balance += amount;
            cout << "your  new current balance is:  " << Accounts[c].balance << endl;
            transaction t = { idtransaction, Accounts[c].accountNumber, "Deposit", amount, date };
            idtransaction++;
            push(Accounts[c].Transaction, t);
        }
        else if (operation == '2') {
            cout << "loan submission :" << endl;
            loan loan_req = {};
            cin.ignore();
            cout << "enter the type of loan :" << endl;
            getline(cin, loan_req.Type);
            cout << "enter the principal amount :" << endl;
            cin >> loan_req.Principal_amount;
            cout << "enter the amount paid : " << endl;
            cin >> loan_req.Amount_paid;
            insertdoublylist(loan_request, loan_req, loan_request->size + 1);
        }
        else if (operation == '5') {
            cout << "transaction history :" << endl;
            stack* s = Accounts[c].Transaction;
            displayStack(s);
        }
        else if (operation == '6') {
            cout << "undo last transaction :" << endl;
            stack* s = Accounts[c].Transaction;
            transaction t = {};

            t = pop(s);
            if (t.Type == "Deposit") {
                Accounts[c].balance -= t.Amount;
            }
            else if (t.Type == "Withdrawal") {
                Accounts[c].balance += t.Amount;
            }

            displayStack(s);
        }
        else if (operation == '0') {
            cout << "exit customer interface !" << endl;
        }
        else {
            cout << "verify your choice !" << endl;
        }
    } while (operation != '0');
}

void employee_interface(Employee employees[], int& size1, int e, Account Accounts[], int& maxaccount, doublylist* loan_request) {
    string operation;
    singlylist* completed_loans = createsinglylist();
    do {
        cout << "        welcome to employee interface !       " << endl;
        cout << "_____________________________________________________________" << endl;
        cout << "______________what do you want_______________________________" << endl;
        cout << "_____________________________________________________________" << endl;
        cout << "        01- Manage employees (Manager only)                  " << endl;
        cout << "        02- Add a customer account                           " << endl;
        cout << "        03- Display the list of accounts                     " << endl;
        cout << "        04- Change the status of an account                  " << endl;
        cout << "        05- Archive closed accounts                          " << endl;
        cout << "        06- Display loans for a specific customer            " << endl;
        cout << "        07- Change the status of a loan                      " << endl;
        cout << "        08- Delete completed loans                           " << endl;
        cout << "        09- Manage loan requests (approve/reject)            " << endl;
        cout << "        10- Manage daily transaction log                     " << endl;
        cout << "        11- Statistics                                       " << endl;
        cout << "        00- Exit                                             " << endl;
        cout << "_____________________________________________________________" << endl;
        cout << "               Enter your choice:                            " << endl;
        cin >> operation;
        if (operation == "01") {
            // MANAGER ONLY - Manage employees
            cout << "_______________Manager Authentication Required_______________" << endl;
            int manager_id;
            cout << "Enter your manager ID: ";
            cin >> manager_id;
            int m = loginemployee(manager, manager_id, ManagerNb);

            if (m >= 0) {
                cout << "________________________________________________________________________" << endl;
                cout << "Access granted! You are authorized to manage employee accounts." << endl;
                cout << "________________________________________________________________________" << endl;
                cout << " 1- Add employee                                    " << endl;
                cout << " 2- Delete employee                                 " << endl;
                cout << " 3- Modify employee                                 " << endl;
                cout << " 4- Display employees by last name (alphabetical)   " << endl;
                cout << " 5- Display employees grouped by bank branch        " << endl;
                cout << " 6- Display earliest recruited employee             " << endl;
                cout << " 7- Exit                                            " << endl;
                cout << "__________________________________________________________________________" << endl;

                char op;
                cin >> op;

                if (op == '1') {
                    // Add employee
                    addEmployee(employees, size1, 100);
                }
                else if (op == '2') {
                    // Delete employee
                    int emp_id;
                    cout << "Enter employee ID to delete: ";
                    cin >> emp_id;
                    deleteEmployee(employees, size1, emp_id);
                }
                else if (op == '3') {
                    // Modify employee
                    int emp_id;
                    cout << "Enter employee ID to modify: ";
                    cin >> emp_id;
                    modifyEmployee(employees, size1, emp_id);
                }
                else if (op == '4') {
                    // Display employees by last name
                    cout << "_______________Employees sorted by last name_______________" << endl;
                    DisplayemployeesSortedByLastName(employees, size1);
                }
                else if (op == '5') {
                    // Display employees grouped by branch
                    cout << "_______________Employees grouped by branch_______________" << endl;
                    DisplayEmployeesByBranch(employees, size1);
                }
                else if (op == '6') {
                    // Display earliest recruited employee
                    cout << "_______________Earliest recruited employee_______________" << endl;
                    displayEarliestRecruitedEmployee(employees, size1);
                }
                else if (op == '7') {
                    cout << "Exiting manager menu!" << endl;
                }
                else {
                    cout << "Invalid choice!" << endl;
                }
            }
            else {
                cout << "________________________________________________________________________" << endl;
                cout << "Access denied! You are not authorized to manage employee accounts." << endl;
                cout << "________________________________________________________________________" << endl;
            }
        }
        else if (operation == "02") {
            // Add customer account
            cout << "_______________Add Customer Account_______________" << endl;
            Account newAcc;
            cin.ignore();

            cout << "Enter account number: ";
            cin >> newAcc.accountNumber;
            cin.ignore();

            cout << "Enter account type (Current/Savings/Business/Student): ";
            getline(cin, newAcc.accountType);

            cout << "Enter IBAN: ";
            getline(cin, newAcc.IBAN);

            cout << "Enter branch code: ";
            cin >> newAcc.branchCode;
            cin.ignore();

            cout << "Enter holder name: ";
            getline(cin, newAcc.holderName);

            cout << "Enter opening date (DD/MM/YYYY): ";
            getline(cin, newAcc.openingDate);

            cout << "Enter status (Active/Inactive/Closed): ";
            getline(cin, newAcc.status);

            cout << "Enter initial balance: ";
            cin >> newAcc.balance;

            // Initialize loan and transaction lists
            newAcc.loan = createdoublylist();
            newAcc.Transaction = createstack();

            if (addAccount(Accounts, maxaccount, newAcc)) {
                cout << "Account added successfully!" << endl;
            }
        }
        else if (operation == "03") {
            // Display the list of accounts
            cout << "_______________Customer Accounts_______________" << endl;
            displayAccounts(Accounts, maxaccount);
        }
        else if (operation == "04") {
            // Change the status of an account
            cout << "_______________Change Account Status_______________" << endl;
            int accNum;
            string newStatus;

            cout << "Enter account number: ";
            cin >> accNum;
            cin.ignore();

            cout << "Enter new status (Active/Inactive/Closed): ";
            getline(cin, newStatus);

            if (changeAccountStatus(Accounts, maxaccount, accNum, newStatus)) {
                cout << "Status updated successfully!" << endl;
            }
            else {
                cout << "Account not found!" << endl;
            }
        }
        else if (operation == "05") {
            // Archive closed accounts
            cout << "_______________Archive Closed Accounts_______________" << endl;
            archiveClosedAccounts(Accounts, maxaccount, archivedAccounts, archivedCount);
            cout << "Closed accounts archived successfully!" << endl;
        }
        // Replace these sections in your employee_interface function:


        else if (operation == "06") {
            // Display loans for a specific customer
            cout << "_______________Display Customer Loans_______________" << endl;
            int customerID;
            cout << "Enter Customer Account Number: ";
            cin >> customerID;

            Account* acc = findAccount(Accounts, maxaccount, customerID);
            if (acc) {
                displayCustomerLoan(*acc);
            }
            else {
                cout << "Customer not found.\n";
            }
        }
        else if (operation == "07") {
            // Change the status of a loan
            cout << "_______________Change Loan Status_______________" << endl;
            int customerID;
            cout << "Enter Customer Account Number: ";
            cin >> customerID;

            Account* acc = findAccount(Accounts, maxaccount, customerID);
            if (acc) {
                ChangeLoanStatus(*acc);
            }
            else {
                cout << "Customer not found.\n";
            }
        }

            
        else if (operation == "08") {
                // Delete completed loans
                cout << "_______________Delete Completed Loans_______________" << endl;

                char confirm;
                cout << "Are you sure you want to extract ALL completed loans? (y/n): ";
                cin >> confirm;

                if (confirm == 'y' || confirm == 'Y') {
                    int customerID;
                    cout << "Enter Customer Account Number: ";
                    cin >> customerID;  

                    Account* acc = findAccount(Accounts, maxaccount, customerID);
                    if (acc) {
                        extractCompletedLoans(acc->loan, completed_loans);  
                        cout << "Completed loans extracted successfully!\n";
                    }
                    else {
                        cout << "Customer not found.\n";
                    }
                }
                else {
                    cout << "Operation cancelled.\n";
                }
                }

                
        else if (operation == "09") {
            // Manage loan requests (approve/reject)
            cout << "_______________Loan Request Management_______________" << endl;

            manageLoanRequests(loan_request, maxaccount);
        }
        else if (operation == "10") {
            // Manage daily transaction log
            cout << "_______________Daily Transaction Log Management_______________" << endl;
            cout << "1- View all daily transactions (from stacks)" << endl;
            cout << "2- Finalize the day (copy to permanent log)" << endl;
            cout << "3- View finalized transaction history" << endl;
            cout << "4- Clear finalized transaction log" << endl;
            cout << "_______________________________________________" << endl;
            cout << "Enter your choice: ";
            char logChoice;
            cin >> logChoice;

            if (logChoice == '1') {
                // View all current transactions from all accounts
                cout << "\n_______________Current Daily Transactions_______________" << endl;
                bool hasTransactions = false;

                for (int i = 0; i < maxaccount; i++) {
                    if (!isEmpty(*Accounts[i].Transaction)) {
                        cout << "\n--- Account #" << Accounts[i].accountNumber
                            << " (" << Accounts[i].holderName << ") ---" << endl;
                        displayStack(Accounts[i].Transaction);
                        hasTransactions = true;
                    }
                }

                if (!hasTransactions) {
                    cout << "No transactions found for today." << endl;
                }
            }
            else if (logChoice == '2') {
                // Finalize the day - copy all transactions to permanent log
                cout << "\n_______________Finalizing Day_______________" << endl;
                cout << "This will copy all transactions to permanent log." << endl;
                cout << "Customers will no longer be able to undo these transactions." << endl;
                cout << "Are you sure? (Y/N): ";

                char confirm;
                cin >> confirm;

                if (confirm == 'Y' || confirm == 'y') {
                    int transactionCount = 0;

                    // Create a temporary stack to preserve order
                    stack* tempStack = createstack();

                    // Loop through all accounts and copy transactions to permanent log
                    for (int i = 0; i < maxaccount; i++) {
                        stack* currentStack = Accounts[i].Transaction;

                        // First, reverse into temp stack to maintain order
                        while (!isEmpty(*currentStack)) {
                            transaction t = pop(currentStack);
                            push(tempStack, t);
                        }

                        // Now copy from temp to permanent log
                        while (!isEmpty(*tempStack)) {
                            transaction t = pop(tempStack);
                            push(daily_transaction_log, t);
                            transactionCount++;
                        }
                    }

                    destroystack(tempStack);

                    cout << "\nFinalization complete!" << endl;
                    cout << "Total transactions finalized: " << transactionCount << endl;
                    cout << "All customer transaction stacks have been cleared." << endl;
                }
                else {
                    cout << "Finalization cancelled." << endl;
                }
            }
            else if (logChoice == '3') {
                // View finalized transaction history
                cout << "\n_______________Finalized Transaction History_______________" << endl;

                if (isEmpty(*daily_transaction_log)) {
                    cout << "No finalized transactions in the log." << endl;
                }
                else {
                    cout << "Total finalized transactions: " << stackSize(daily_transaction_log) << endl;
                    displayStack(daily_transaction_log);
                }
            }
            else if (logChoice == '4') {
                // Clear finalized log (admin function)
                cout << "\n_______________Clear Finalized Log_______________" << endl;
                cout << "WARNING: This will permanently delete all finalized transactions!" << endl;
                cout << "Are you sure? (Y/N): ";

                char confirm;
                cin >> confirm;

                if (confirm == 'Y' || confirm == 'y') {
                    // Clear the stack by popping all elements
                    while (!isEmpty(*daily_transaction_log)) {
                        pop(daily_transaction_log);
                    }

                    cout << "Finalized transaction log cleared successfully!" << endl;
                }
                else {
                    cout << "Clear operation cancelled." << endl;
                }
            }
            else {
                cout << "Invalid choice!" << endl;
            }
        }
        else if (operation == "11") {
            // Statistics
            cout << "---------------------------------------------------" << endl;
            cout << "            statistics:        " << endl;
            cout << "      1. Total number of loans." << endl;
            cout << "      2. Number of loans by type." << endl;
            cout << "      3. Number of loans by status" << endl;
            cout << "      4. Active loans within a specified date range" << endl;
            cout << "      5. Customer with the highest number of loans" << endl;
            cout << "      6. Customer with the highest account balance" << endl;
            cout << "      7. Customer with the lowest account balance" << endl;
            cout << "      8. Total number of employees" << endl;
            cout << "      9. Number of employees per bank branch" << endl;
            cout << "_________________________________________________" << endl;
            char statChoice;
            cin >> statChoice;

            if (statChoice == '1') {
                // Total number of loans
                cout << "\n================================================" << endl;
                cout << "           TOTAL NUMBER OF LOANS                " << endl;
                cout << "================================================" << endl;
                int totalLoans = Total_Loans(accounts, accountCount);
                cout << "Total Loans in System: " << totalLoans << endl;
                cout << "================================================" << endl;
            }
            else if (statChoice == '2') {
                // Number of loans by type
                cout << "\n";
                display_Loans_type(accounts, accountCount);
            }
            else if (statChoice == '3') {
                // Number of loans by status
                cout << "\n";
                display_by_status(accounts, accountCount);
            }
            else if (statChoice == '4') {
                // Active loans within a specified date range
                cout << "\n================================================" << endl;
                cout << "      ACTIVE LOANS IN DATE RANGE                " << endl;
                cout << "================================================" << endl;

                string startdate, enddate;
                cin.ignore(); // Clear buffer

                cout << "Enter start date (DD/MM/YYYY): ";
                getline(cin, startdate);

                cout << "Enter end date (DD/MM/YYYY): ";
                getline(cin, enddate);

                displayActiveLoan(startdate, enddate, accounts, accountCount);
            }
            else if (statChoice == '5') {
                // Customer with the highest number of loans
                cout << "\n";
                CustomerHighestLoan(accounts, accountCount);
            }
            else if (statChoice == '6') {
                // Customer with the highest account balance
                cout << "\n";
                CustomerHighestBalance(accounts, accountCount);
            }
            else if (statChoice == '7') {
                // Customer with the lowest account balance
                cout << "\n";
                CustomerLowestBalance(accounts, accountCount);
            }
            else if (statChoice == '8') {
                // Total number of employees
                cout << "\n================================================" << endl;
                cout << "          TOTAL NUMBER OF EMPLOYEES             " << endl;
                cout << "================================================" << endl;
                cout << "Total Employees: " << Total_Employees(EmpNb) << endl;
                cout << "================================================" << endl;
            }
            else if (statChoice == '9') {
                // Number of employees per bank branch
                cout << "\n";
                displayEmployeeperBranch(employees, EmpNb);
            }

        
        }
        else if (operation == "00") cout << "exit employee interface !";
        else {
            cout << "Invalid choice! Please verify your selection." << endl;
        }
    } while (operation != "00");
}

int main() {
    initialize_account(loans1, loans2, loans3, loans4, loans5);
    for (int i = 0; i < 5; i++) {
        accounts[i] = Accounts[i];
    }
    accountCount = 5;
    char r;
    do {
        cout << "|____________________________________________________________| " << endl;
        cout << "|____________________________________________________________| " << endl;
        cout << "|__________welcome to the Banking Management System__________| " << endl;
        cout << "|____________________________________________________________| " << endl;
        cout << "|____________________________________________________________|" << endl;
        cout << "|                  1-Cutomer intefrace                       | " << endl;
        cout << "|                  2-Employee intefrace                      |" << endl;
        cout << "|____________________________________________________________|" << endl;
        cout << "|____________________________________________________________| " << endl;
        cout << "|                  3-Exit                                    |" << endl;
        cout << "|____________________________________________________________|" << endl;
        cout << "|____________________________________________________________|" << endl;
        cout << "               where do you want to enter ?                   " << endl;
        cin >> r;

        if (r == '1') {
            cout << "enter your account number :";
            int acc_number;
            cin >> acc_number;
            int c = login(accounts, acc_number, accountCount);
            if (c >= 0) {
                cout << "-------------------login successful!-----------------" << endl;
                customer_interface(accounts, accountCount, c, loan_request);
            }
            else {
                cout << "invalid account number !" << endl;
            }

        }
        else if (r == '2') {
            cout << "---------------employee interface--------------- " << endl;
            cout << "------------------------------------------------" << endl;
            cout << "             enter your employee ID :           " << endl;
            int emp_id;
            cin >> emp_id;
            int e = loginemployee(employees, emp_id, EmpNb);
            if (e >= 0) {
                cout << "login successful!" << endl;
                employee_interface(employees, EmpNb, e, accounts, accountCount, loan_request);

            }
            else {
                cout << "invalid employee ID !" << endl;
            }
        }
        else if (r == '3') {
            cout << "exist the system !" << endl;
        }
        else {
            cout << "verify your choice !" << endl;


        }
    } while (r != '3');

}

