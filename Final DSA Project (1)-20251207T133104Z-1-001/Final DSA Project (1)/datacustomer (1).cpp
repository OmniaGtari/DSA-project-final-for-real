#include <iostream>
using namespace std;
#include "doublylinkedlistmethode.h"
#include "stackmethode.h"
#include "datacustomer.h"

doublylist* loans1 = createdoublylist();
doublylist* loans2 = createdoublylist();
doublylist* loans3 = createdoublylist();
doublylist* loans4 = createdoublylist();
doublylist* loans5 = createdoublylist();

stack* transaction1 = createstack();
stack* transaction2 = createstack();
stack* transaction3 = createstack();
stack* transaction4 = createstack();
stack* transaction5 = createstack();

void initialize_account(doublylist* loans1, doublylist* loans2, doublylist* loans3, doublylist* loans4, doublylist* loans5) {
    loan l11 = { 0, "Car", 10000, 5, 2000, 8000, "2025-01-01", "2028-01-01", "Active" };
    loan l12 = { 1, "Home", 200000, 5, 50000, 150000, "2020-01-15", "2040-01-15", "Active" };
    loan l21 = { 2, "Car", 30000, 7, 10000, 20000, "2021-05-10", "2026-05-10", "Active" };
    loan l22 = { 3, "Business", 15000, 12, 5000, 10000, "2022-03-01", "2025-03-01", "Active" };
    loan l31 = { 4, "Home", 40000, 6, 15000, 25000, "2019-09-01", "2029-09-01", "Active" };
    loan l32 = { 5, "Student", 100000, 8, 60000, 40000, "2018-07-20", "2028-07-20", "Active" };
    loan l41 = { 6, "Student", 250000, 4, 250000, 0, "2000-02-01", "2020-02-01", "Closed" };
    loan l42 = { 7, "Home", 10000, 10, 2000, 8000, "2023-06-15", "2026-06-15", "Active" };
    loan l51 = { 8, "Business", 5000, 9, 5000, 0, "2021-01-01", "2023-01-01", "Closed" };
    loan l52 = { 9, "Car", 60000, 7, 30000, 30000, "2020-11-11", "2030-11-11", "Active" };
    loan l53 = { 10, "Car", 2000, 15, 500, 1500, "2024-02-01", "2025-02-01", "Active" };
    insertdoublylist(loans1, l11, 1);
    insertdoublylist(loans1, l12, 2);
    insertdoublylist(loans2, l21, 1);
    insertdoublylist(loans2, l22, 2);
    insertdoublylist(loans3, l31, 1);
    insertdoublylist(loans3, l32, 2);
    insertdoublylist(loans4, l41, 1);
    insertdoublylist(loans4, l42, 2);
    insertdoublylist(loans5, l51, 1);
    insertdoublylist(loans5, l52, 2);
    insertdoublylist(loans5, l53, 3);
    transaction t11 = { 91000, 1001, "Deposit",    500,  "01/11/2025" };
    transaction t12 = { 91001, 1001, "Withdrawal", 200,  "01/11/2025" };
    transaction t13 = { 91002, 1001, "Deposit",    1000, "02/11/2025" };
    transaction t14 = { 91003, 1001, "Withdrawal", 50,   "02/07/2025" };
    transaction t21 = { 91004, 1002, "Deposit",    750,  "03/11/2025" };
    transaction t22 = { 91005, 1002, "Withdrawal", 300,  "03/09/2025" };
    transaction t23 = { 91006, 1002, "Deposit",    2000, "04/11/2025" };
    transaction t24 = { 91007, 1002, "Withdrawal", 100,  "04/11/2025" };
    transaction t31 = { 91008, 1003, "Deposit",    400,  "05/04/2025" };
    transaction t32 = { 91009, 1003, "Withdrawal", 150,  "05/11/2025" };
    transaction t33 = { 91010, 1003, "Deposit",    600,  "06/11/2025" };
    transaction t34 = { 91011, 1003, "Withdrawal", 250,  "06/11/2025" };
    transaction t41 = { 91012, 1004, "Deposit",    1500, "07/03/2025" };
    transaction t42 = { 91013, 1004, "Withdrawal", 80,   "07/11/2025" };
    transaction t43 = { 91014, 1004, "Deposit",    900,  "08/11/2025" };
    transaction t44 = { 91015, 1004, "Withdrawal", 120,  "08/01/2025" };
    transaction t51 = { 91016, 1005, "Deposit",    2500, "09/11/2025" };
    transaction t52 = { 91017, 1005, "Withdrawal", 400,  "09/11/2025" };
    transaction t53 = { 91019, 1005, "Deposit",    300,  "10/12/2025" };
    transaction t54 = { 91020, 1005, "Withdrawal", 200,  "10/11/2025" };
    push(transaction1, t11);
    push(transaction1, t12);
    push(transaction1, t13);
    push(transaction1, t14);
    push(transaction2, t21);
    push(transaction2, t22);
    push(transaction2, t23);
    push(transaction2, t24);
    push(transaction3, t31);
    push(transaction3, t32);
    push(transaction3, t33);
    push(transaction3, t34);
    push(transaction4, t41);
    push(transaction4, t42);
    push(transaction4, t43);
    push(transaction4, t44);
    push(transaction5, t51);
    push(transaction5, t52);
    push(transaction5, t53);
    push(transaction5, t54);

}

const int maxaccount = 10000;
Account Accounts[maxaccount] = {
        { 1001, "Current", "TN59 1000 0000 0001 2345 6789", 1, "Ahmed Ben Salah", "01/01/2024", "Active", 2500,loans1,transaction1},
        { 1002, "Savings", "TN59 1000 0000 0002 9876 5432", 2, "Leila Trabelsi", "15/03/2024", "Active", 12000,loans2 ,transaction2},
        { 1003, "Business", "TN59 1000 0000 0003 4567 8910", 3, "karim kallel", "20/05/2024", "Active", 50000,loans3,transaction3},
        { 1004, "Student", "TN59 1000 0000 0004 1111 2222", 1, "Mariem Jlassi", "10/09/2024", "Inactive", 300 ,loans4,transaction4},
        { 1005, "Current", "TN59 1000 0000 0005 3333 4444", 2, "Hichem Kacem", "05/11/2024", "Closed", 100, loans5,transaction5},
};