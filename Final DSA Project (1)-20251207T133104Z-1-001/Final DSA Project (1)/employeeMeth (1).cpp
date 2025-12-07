#include <iostream>
#include "employeeMeth.h"
#include "customer.h"
#include <string>
#include "doublylinkedlistmethode.h"
#include "singlylinkedlistmethode.h"
#include "datacustomer.h"
#include "accountMeth.h"

using namespace std;

void printEmployee(const Employee& e) {
    cout << "Employee ID: " << e.id << endl;
    cout << "Name: " << e.name << " " << e.lastName << endl;
    cout << "Address: " << e.address << endl;
    cout << "Salary: " << e.salary << endl;
    cout << "Hire Date: " << e.hireDate << endl;
    cout << "Branch Code: " << e.branchCode << endl;
}

void addEmployee(Employee employees[], int& count, int MAX) {
    // Check if we can add more employees
    if (count >= MAX) {
        cout << "Error: employee array is full." << endl;
        return;
    }

    Employee e; // Declare a new Employee object
    cin.ignore(); // Clear input buffer ONCE at the start

    do {
        cout << "Enter ID: ";
        cin >> e.id;
        if (!isIdUnique(employees, count, e.id)) {
            cout << "Error: ID already exists. Please enter a unique ID." << endl;
        }
        if (e.id <= 0) {
            cout << "Error: ID must be positive." << endl;
        }
    } while (!isIdUnique(employees, count, e.id) || e.id <= 0);

    cin.ignore(); // Clear buffer after reading ID

    do {
        cout << "Enter first name: ";
        getline(cin, e.name);
        if (!isValidName(e.name)) {
            cout << "Error: Invalid name. Use only letters, spaces, and hyphens." << endl;
        }
    } while (!isValidName(e.name));

    do {
        cout << "Enter last name: ";
        getline(cin, e.lastName);
        if (!isValidName(e.lastName)) {
            cout << "Error: Invalid last name. Use only letters, spaces, and hyphens." << endl;
        }
    } while (!isValidName(e.lastName));

    do {
        cout << "Enter address: ";
        getline(cin, e.address);
        if (e.address.empty()) {
            cout << "Error: Address cannot be empty." << endl;
        }
    } while (e.address.empty());

    do {
        cout << "Enter salary: ";
        cin >> e.salary;
        if (e.salary < 0) {
            cout << "Error: Salary must be positive." << endl;
        }
    } while (e.salary < 0);

    cin.ignore(); // Clear buffer after reading salary

    do {
        cout << "Enter hire date (YYYY-MM-DD): ";
        getline(cin, e.hireDate);
        if (!isValidHireDate(e.hireDate)) {
            cout << "Error: Invalid date format. Use YYYY-MM-DD." << endl;
        }
    } while (e.hireDate.empty() || !isValidHireDate(e.hireDate));

    do {
        cout << "Enter branch code: ";
        cin >> e.branchCode;
        if (e.branchCode <= 0) {
            cout << "Error: Branch code must be positive." << endl;
        }
    } while (e.branchCode <= 0);

    employees[count++] = e;

    cout << "Employee added successfully." << endl;
}

int findEmployeeIndex(Employee employees[], int count, int id) {
    for (int i = 0; i < count; i++) {
        if (employees[i].id == id)
            return i;
    }
    return -1;
}

bool deleteEmployee(Employee employees[], int& count, int id) {
    int pos = findEmployeeIndex(employees, count, id);

    if (pos == -1) {
        cout << "Employee not found.\n";
        return false;
    }

    for (int i = pos; i < count - 1; i++)
        employees[i] = employees[i + 1];

    count--;
    cout << "Employee deleted.\n";
    return true;
}

bool modifyEmployee(Employee employees[], int count, int id) { // modify an employee by ID
    int pos = findEmployeeIndex(employees, count, id);

    if (pos == -1) {
        cout << "Employee not found.\n";
        return false;
    }

    Employee& e = employees[pos];  // Using a reference 'e' to modify the original employee directly

    do {
        cout << "Modify first name (" << e.name << "): ";
        cin.ignore();
        getline(cin, e.name);
    } while (!isValidName(e.name));

    do {
        cout << "Modify last name (" << e.lastName << "): ";
        getline(cin, e.lastName);
    } while (!isValidName(e.lastName));

    do {
        cout << "Modify address (" << e.address << "): ";
        getline(cin, e.address);
    } while (e.address.empty());

    do {
        cout << "Modify salary (" << e.salary << "): ";
        cin >> e.salary;
    } while (e.salary < 0);

    do {
        cout << "Modify hire date (" << e.hireDate << "): ";
        cin >> e.hireDate;
    } while (e.hireDate.empty() || !isValidHireDate(e.hireDate));

    do {
        cout << "Modify branch code (" << e.branchCode << "): ";
        cin >> e.branchCode;
    } while (e.branchCode <= 0);

    cout << "Employee modified.\n";
    return true;
}

void displayEarliestRecruitedEmployee(Employee employees[], int count) {
    if (count == 0) {
        cerr << "No employees available.\n";
        return;
    }

    int earliestIndex = 0;

    for (int i = 1; i < count; ++i) {
        if (employees[i].hireDate < employees[earliestIndex].hireDate) {
            earliestIndex = i;
        }
    }

    cout << "Earliest recruited employee details:\n";
    printEmployee(employees[earliestIndex]);
}

void DisplayemployeesSortedByLastName(Employee employees[], int count) {
    Employee temp[100]; //copy of the original array
    for (int i = 0; i < count; i++) {
        temp[i] = employees[i];
    }
    for (int i = 0; i < count - 1; i++) { //sort alphabetically by last name
        for (int j = i + 1; j < count; j++) {
            if (temp[i].lastName > temp[j].lastName) {
                Employee exchange = temp[i];
                temp[i] = temp[j];
                temp[j] = exchange;
            }
        }
    }
    for (int i = 0; i < count; i++) { //Display the Sorted List
        cout << "ID : " << temp[i].id << endl;
        cout << "Name : " << temp[i].name << endl;
        cout << "Last Name : " << temp[i].lastName << endl;
        cout << " Salary : " << temp[i].salary << endl;

    }
}
void DisplayEmployeesByBranch(Employee employees[], int count) {
    for (int branch = 1; branch <= 3; branch++) {
        cout << "==========branch" << branch << "===========\n"; // fixed newline escape

        bool found = false;
        for (int i = 0; i < count; i++) {
            if (employees[i].branchCode == branch) {
                found = true;
                cout << "ID: " << employees[i].id << endl;
                cout << "Name: " << employees[i].name << endl;
                cout << "Last Name: " << employees[i].lastName << endl;
                cout << "Salary: " << employees[i].salary << endl;
                cout << "-----------------------" << endl;
            }
        }
        // if no employee belongs to this branch
        if (!found) {
            cout << "No employees in this branch.\n";
        }
    }
}


bool isIdUnique(Employee employees[], int count, int id) {
    for (int i = 0; i < count; ++i) {
        if (employees[i].id == id) {
            return false;
        }
    }
    return true;
}

bool isValidName(const string& name) {
    if (name.empty()) return false;

    for (char c : name) {
        if (!isalpha(c) && c != ' ' && c != '-')  // Allow letters, spaces, and hyphens
            return false;
    }
    return true;
}

bool isValidHireDate(const string& hiredate) {
    if (hiredate.length() != 10 || hiredate[4] != '-' || hiredate[7] != '-') return false;
    for (int i = 0; i < 10; i++) {
        if (i == 4 || i == 7) continue; // Skip dashes
        if (!isdigit(hiredate[i])) return false;
    }

    return true;
}



void displayCustomerLoan(const Account& acc) {
    cout << "Account number : " << acc.accountNumber << " | Name : " << acc.holderName << endl;

    if (acc.loan == nullptr) {
        cout << "No loan list found for this account" << endl;
        return;
    }

    node_loan* node = acc.loan->head;

    if (node == nullptr) {
        cout << "This account has no loans." << endl;
        return;
    }

    cout << "-------------------- Loans for this customer --------------------" << endl;
    while (node != nullptr) {
        const loan& L = node->l;

        cout << "Loan ID : " << L.loan_ID << endl;
        cout << "Loan Type : " << L.Type << endl;
        cout << "Principal: " << L.Principal_amount << " TND" << endl;
        cout << "Interest rate: " << L.Interest_rate << "%" << endl;
        cout << "Amount paid: " << L.Amount_paid << " TND" << endl;
        cout << "Remaining balance: " << L.Remaining_balance << " TND" << endl;
        cout << "Start date: " << L.Start_date << endl;
        cout << "End date: " << L.End_date << endl;
        cout << "Status: " << L.Status << endl;
        cout << "-------------------------------------------------------------" << endl;

        node = node->next;
    }
    cout << "End of loan list." << endl;
}
void ChangeLoanStatus(Account& acc) {
    cout << "Account number: " << acc.accountNumber << " | Name: " << acc.holderName << endl;

    if (acc.loan == nullptr) {
        cout << "No loan list found for this account." << endl;
        return;
    }

    node_loan* node = acc.loan->head;

    if (node == nullptr) {
        cout << "This account has no loans." << endl;
        return;
    }

    int Loan_ID;
    cout << "Enter the Loan ID you want to modify: ";
    cin >> Loan_ID;

    string NewStatus;
    do {
        cout << "Enter new status (active / completed / overdue): ";
        cin >> NewStatus;

        for (char& c : NewStatus) c = tolower(c);

        if (NewStatus != "active" && NewStatus != "completed" && NewStatus != "overdue") {
            cout << "Invalid status, please try again!" << endl;
        }
    } while (NewStatus != "active" && NewStatus != "completed" && NewStatus != "overdue");

    while (node != nullptr) {
        if (node->l.loan_ID == Loan_ID) {
            cout << "Current status: " << node->l.Status << endl;
            node->l.Status = NewStatus;
            cout << "Status updated successfully!" << endl;
            return;
        }
        node = node->next;
    }

    cout << "Loan with ID " << Loan_ID << " not found." << endl;
}
void extractCompletedLoans(doublylist* source, singlylist* completed_loans) {
    if (source == nullptr || isEmpty(*source)) return;
    if (completed_loans == nullptr) return;

    int i = 1;

    while (i <= source->size) {
        loan currentLoan = getElementdoublylist(*source, i);
        string status = currentLoan.Status;


        for (char& c : status) c = tolower(c);

        if (status == "completed") {
            insertsinglylist(completed_loans, currentLoan, completed_loans->size + 1);
            removeAtdoublylist(source, i);
        }
        else {
            i++;
        }
    }
}
#include <iostream>
#include <limits>  // For numeric_limits
using namespace std;

void manageLoanRequests(doublylist* loan_request,Account Accounts[], int maxaccount) {
    cout << "_______________Loan Request Management_______________" << endl;

    // Check if the loan request list is empty
    if (!loan_request || loan_request->size == 0) {
        cout << "No pending loan requests." << endl;
        return;
    }

    cout << "Pending loan requests (" << loan_request->size << "):" << endl;
    displayList(*loan_request);

    char decision;
    cout << "Approve all requests? (y/n): ";
    cin >> decision;
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear input buffer

    if (decision != 'y' && decision != 'Y') {
        cout << "Loan requests were not approved.\n";
        return;
    }

    // Process loan requests FIFO
    while (loan_request->size > 0) {
        node_loan* node = loan_request->head;
        if (!node) break;

        loan req = node->l;

        int targetAccountNumber;
        cout << "Enter the Account Number to assign this loan (Loan ID "
            << req.loan_ID << "): ";
        while (!(cin >> targetAccountNumber)) {
            cout << "Invalid input. Enter a valid Account Number: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear buffer

        Account* acc = findAccount(Accounts, maxaccount, targetAccountNumber);

        if (acc) {
            if (!acc->loan) {
                acc->loan = createdoublylist();
            }
            insertdoublylist(acc->loan, req, acc->loan->size + 1);

            cout << "Approved loan (" << req.Type
                << ", " << req.Principal_amount
                << " TND) for customer " << targetAccountNumber << endl;
        }
        else {
            cout << "Customer " << targetAccountNumber
                << " not found. Loan skipped.\n";
        }
        removeAtdoublylist(loan_request, 1);
        cout << "Remaining pending requests: " << loan_request->size << endl;
    }

    cout << "All loan requests processed (FIFO)." << endl;
}
