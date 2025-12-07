#include <iostream>
using namespace std;
#include "customer.h"
#include "doublylinkedlist.h"
#include "loan.h"
#include "employeedata.h"
#include <string>
#include "statisticsMeth.h"
int Total_Loans(Account Accounts[], int accountCount) {
	int sum = 0;
	for (int i = 0; i < accountCount; i++) {
		sum += Accounts[i].loan->size;
	}
	return sum;
}

void display_Loans_type(Account Accounts[], int accountCount) {
	int carloans = 0;
	int homeloans = 0;
	int studentloans = 0;
	int businessloans = 0;
	for (int i = 0; i < accountCount; i++) {
		doublylist* loanList = Accounts[i].loan;
		node_loan* current = loanList->head;
		while (current != nullptr) {
			if (current->l.Type == "Car") {
				carloans++;
			}
			else if (current->l.Type == "Home") {
				homeloans++;
			}
			else if (current->l.Type == "student") {
				studentloans++;
			}
			else if (current->l.Type == "Business") {
				businessloans++;
			}
			current = current->next;
		}
	}
	cout << "------------------------------------------------" << endl;
	cout << "----------------- Loans By Type-----------------" << endl;
	cout << "------------------------------------------------" << endl;
	cout << "Car Loans: " << carloans << endl;
	cout << "Home Loans: " << homeloans << endl;
	cout << "Student Loans: " << studentloans << endl;
	cout << "Business Loans: " << businessloans << endl;
	cout << "------------------------------------------------" << endl;
}
void display_by_status(Account Accounts[], int accountCount) {
	int activeLoans = 0;
	int completedLoans = 0;
	int overdueLoans = 0;
	for (int i = 0; i < accountCount; i++) {
		doublylist* loanList = Accounts[i].loan;
		node_loan* current = loanList->head;
		while (current != nullptr) {
			if (current->l.Status == "Active") {
				activeLoans++;
			}
			else if (current->l.Status == "Complete") {
				completedLoans++;
			}
			else if (current->l.Status == "Overdue") {
				overdueLoans++;
			}
			current = current->next;
		}
	}
	cout << "------------------------------------------------" << endl;
	cout << "--------------- Loans By Status-----------------" << endl;
	cout << "------------------------------------------------" << endl;
	cout << "Active Loans: " << activeLoans << endl;
	cout << "Completed Loans: " << completedLoans << endl;
	cout << "Overdue Loans: " << overdueLoans << endl;
	cout << "------------------------------------------------" << endl;

}
bool isDateInRange(string date, string startdate, string enddate) {
	string startyear = startdate.substr(6, 4);
	string startmonth = startdate.substr(3, 2);
	string startday = startdate.substr(0, 2);
	string endyear = enddate.substr(6, 4);
	string endmonth = enddate.substr(3, 2);
	string endday = enddate.substr(0, 2);
	string year = date.substr(6, 4);
	string month = date.substr(3, 2);
	string day = date.substr(0, 2);
	if (startyear < year && year < endyear) {
		return true;
	}
	else if (year == startyear) {
		if (month == startmonth) {
			if (day >= startday) {
				return true;
			}
			else return false;
		}
		else if (month > startmonth) {
			return true;
		}
		else return false;
	}
	else if (year == endyear) {
		if (month == endmonth) {
			if (day <= endday) {
				return true;
			}
			else return false;
		}
		else if (month < endmonth) {
			return true;
		}
		else return false;
	}
	else {
		return false;
	}
};
void displayActiveLoan(string startdate, string enddate, Account accounts[], int accountCount) {
	bool test = true;
	for (int i = 0; i < accountCount; i++) {
		doublylist* currlist = accounts[i].loan;
		node_loan* currentloan = currlist->head;
		while (currentloan != nullptr) {
			if (isDateInRange(currentloan->l.Start_date, startdate, enddate) && isDateInRange(currentloan->l.End_date, startdate, enddate) && currentloan->l.Status == "Active") {
				test = false;
				cout << "ID of the loan: " << currentloan->l.loan_ID << "type of the loan: " << currentloan->l.Type << " principle amount of the loan: " << currentloan->l.Principal_amount << endl;
			}
			currentloan = currentloan->next;
		};
	};
	if (test) {
		cout << "None of the loans is within  these dates " << endl;
	}
}

void CustomerHighestLoan(Account accounts[], int accountCount) {
	int maxLoanAmount = 0;
	int customerIndex = -1;
	for (int i = 0; i < accountCount; i++) {
		int totalLoanAmount = 0;
		node_loan* current = accounts[i].loan->head;
		while (current != nullptr) {
			totalLoanAmount++;
			current = current->next;
		}
		if (totalLoanAmount > maxLoanAmount) {
			maxLoanAmount = totalLoanAmount;
			customerIndex = i;
		}
	}
	cout << "================================================" << endl;
	cout << "====== Customer With Highest Number of Loans ===" << endl;
	cout << "================================================" << endl;

	if (maxLoanAmount > 0 && customerIndex != -1) {
		cout << "Account Number: " << accounts[customerIndex].accountNumber << endl;
		cout << "Number of Loans: " << maxLoanAmount << endl;
	}
	else {
		cout << "No loans found." << endl;
	}
	cout << "------------------------------------------------" << endl;
};
void CustomerHighestBalance(Account accounts[], int accountCount) {
	double maxBalance = accounts[0].balance;
	int customerIndex = 0;
	for (int i = 1; i < accountCount; i++) {
		if (accounts[i].balance > maxBalance) {
			maxBalance = accounts[i].balance;
			customerIndex = i;
		}
	}
	cout << "------------------------------------------------" << endl;
	cout << "------------Customer With Highest Balance-------" << endl;
	cout << "------------------------------------------------" << endl;
	cout << "Customer Name: " << accounts[customerIndex].accountNumber << endl;
	cout << "Account Number: " << accounts[customerIndex].accountNumber << endl;
	cout << "Balance: " << maxBalance << " TND" << endl;
	cout << "------------------------------------------------" << endl;

}
void CustomerLowestBalance(Account accounts[], int accountCount) {
	double lowestBalance = accounts[0].balance;
	int customerIndex = 0;
	for (int i = 1; i < accountCount; i++) {
		if (accounts[i].balance < lowestBalance) {
			lowestBalance = accounts[i].balance;
			customerIndex = i;
		}
	}
	cout << "------------------------------------------------" << endl;
	cout << "------------Customer With Lowest Balance-------" << endl;
	cout << "------------------------------------------------" << endl;
	cout << "Customer Name: " << accounts[customerIndex].holderName << endl;
	cout << "Account Number: " << accounts[customerIndex].accountNumber << endl;
	cout << "Balance: " << lowestBalance << " TND" << endl;
	cout << "------------------------------------------------" << endl;
}
int Total_Employees(int count) {
	return count;
}
int countBranch(Employee employees[], int count, int bc) {
	int sum = 0;
	for (int i = 0; i < count; i++) {
		if (employees[i].branchCode == bc) {
			sum += 1;
		}
	}
	return sum;
}
void displayEmployeeperBranch(Employee employees[], int count) {
	string ch = "";
	cout << "================================================" << endl;
	cout << "========= Employees Per Branch =================" << endl;
	cout << "================================================" << endl;
	for (int i = 0; i < count; i++) {
		int b = employees[i].branchCode;
		string bs = to_string(b);
		if (ch.find(bs) == -1) {
			int num = countBranch(employees, count, b);
			cout << "The number of employees of bank branch " << bs << " is: " << num << endl;
			ch += bs + ",";
		}
	}
}