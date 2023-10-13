    #pragma once

    #include <fstream>
    #include "PersonalFinanceManager.h"
    #include <vector>
    #include <limits>
    #include <cstdlib>
    #include "RecordsRatings.h"

struct CategoryExpenses {
    int category;
    double totalAmount;
};
    class Menu {
    private:
        double topWeekTotal = 0.0;
        double topMonthTotal = 0.0;
        int currentDay = 0;  
        int currentMonth = 0;  

        vector<CategoryExpenses> topWeekCategories;
        vector<CategoryExpenses> topMonthCategories;
        PersonalFinanceManager manager;

        struct ExpenseRecord {
            string name = "";
            double amount = 0.0;
            int category = 0;
            int day = 0;
            int month = 0;
        };

        vector<ExpenseRecord> expenseRecords; 
    public:
        Menu(); 
        void Run();

    private:
        void DisplayMenu() const;
        void ClearConsole() const;
        void SetCurrentDate();
        void HandleChoice(int choice);
        void openBalance();
        void Transactions();
        void checkBalanceMenu();
        void printRecordsMenu();
        void AddWallet();
        void AddCard();
        void MakeWithdrawal();
        void MakeDeposit();
        void CheckBalance();
        void ShowAll();
        void PrintRecords();
        void SaveRecordsToFile(const string& filename);
        void LoadRecordsFromFile(const string& filename);
        void recordsByDay();
        void recordsByMonth();
        void recordsByWeek();
        void switchRecCat(ExpenseRecord record);
        void CalculateTopCategories(double& topWeekTotal, double& topMonthTotal, vector<CategoryExpenses>& topWeekCategories, vector<CategoryExpenses>& topMonthCategories);
        void DisplayTopCostForWeek();
        void DisplayTopCostForMonth();
        void WaitForEnter();
        string GetCategoryName(int category);

    };