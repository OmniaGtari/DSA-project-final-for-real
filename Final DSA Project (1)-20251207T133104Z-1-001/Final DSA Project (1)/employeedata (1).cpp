#include "employeedata.h"
#include <string>
Employee employees[1000] = {
    {101, "Aicha", "Masmoudi", "2023-01-15", "12 Rue des Pins", 5000.0, 1},
    {102, "Bassem", "Sassi", "2022-06-10", "45 Rue Jasmins", 6000.0, 2},
    {103, "Karima", "Majdoub", "2021-09-20", "78 Rue Ettahrir", 5500.0, 1},
    {104, "Dina", "Benelhedi", "2020-11-05", "32 Rue des Glycines", 6200.0, 3},
    {105, "Emna", "Darej", "2023-03-01", "65 Rue de Palestine", 5800.0, 2}
};
int EmpNb = 5;

Employee manager[2] = {
    {102, "Bassem", "Sassi", "2022-06-10", "45 Rue Jasmins", 6000.0, 2},
    {103, "Karima", "Majdoub", "2021-09-20", "78 Rue Ettahrir", 5500.0, 1}
};
int ManagerNb = 2;