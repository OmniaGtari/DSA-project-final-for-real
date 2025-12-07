#ifndef STATISTICSMETH_H
#define STATISTICSMETH_H
#include "customer.h"
#include "employee.h"
void displayEmployeeperBranch(Employee employees[], int count);
int countBranch(Employee employees[], int count, int bc);
int Total_Employees(int count);
void CustomerLowestBalance(Account accounts[], int accountCount);
void CustomerHighestBalance(Account accounts[], int accountCount);
void CustomerHighestLoan(Account accounts[], int accountCount);
void displayActiveLoan(string startdate, string enddate, Account accounts[], int accountCount);
bool isDateInRange(string date, string startdate, string enddate);
void display_by_status(Account Accounts[], int accountCount);
void display_Loans_type(Account Accounts[], int accountCount);
int Total_Loans(Account Accounts[], int accountCount);
#endif
