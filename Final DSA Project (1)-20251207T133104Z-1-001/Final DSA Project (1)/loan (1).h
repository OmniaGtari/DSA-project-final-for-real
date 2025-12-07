#ifndef LOAN_H
#define LOAN_H
#include <string>
using namespace std;

struct loan {
	int loan_ID;
	string Type;
	double Principal_amount;
	double Interest_rate;
	double Amount_paid;
	double Remaining_balance;
	string Start_date;
	string End_date;
	string Status;
};
#endif
