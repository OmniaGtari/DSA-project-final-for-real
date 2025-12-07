#ifndef STATISTIC_H
#define STATISTIC_H
#include "customer.h"
#include "employee.h"
int Total_Loans(Account Accounts[], int accountCount);
void display_Loans_type(Account Accounts[], int accountCount);
void display_by_status(Account Accounts[], int accountCount);
bool isDateInRange(string date, string startdate, string enddate);
void displayActiveLoan(string startdate, string enddate, Account accounts[], int accountCount);
void CustomerHighestLoan(Account accounts[], int accountCount);
void CustomerHighestBalance(Account accounts[], int accountCount);
void CustomerLowestBalance(Account accounts[], int accountCount);
int Total_Employees(int count);
int countBranch(Employee employees[], int count, int bc);
void displayEmployeeperBranch(Employee employees[], int count);
#endif 
