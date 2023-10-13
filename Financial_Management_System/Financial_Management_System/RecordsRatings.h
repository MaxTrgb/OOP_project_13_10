#pragma once
#include <iostream>
#include <vector>
#include "Menu.h"
using namespace std;

class RecordsRatings
{
private:
    struct ExpenseRecord {
        string name;
        double amount;
        int category;
        int day;
        int month;
    };
    vector<ExpenseRecord> expenseRecords;

public:
    void LoadRecordsFromFile(const string& filename);
    void PrintForDay(int searchDay);

};

