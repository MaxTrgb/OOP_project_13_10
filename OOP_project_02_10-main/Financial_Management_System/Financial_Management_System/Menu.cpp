#include "Menu.h"
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;
Menu::Menu() {
    LoadRecordsFromFile("expense_records.txt");
}
void Menu::ClearConsole() const {
    cout << "\033[2J\033[H";  
}
void Menu::Run() {

    SetCurrentDate();

    while (true) {
        DisplayMenu();
        int choice;
        cin >> choice;
        HandleChoice(choice);
    }
}
void Menu::DisplayMenu() const {
    ClearConsole();
    cout << "\n\t\t\tPersonal Finance Manager Menu:" << endl;
    cout << "\t\t\t1. Open balance" << endl;
    cout << "\t\t\t2. Transactions" << endl;
    cout << "\t\t\t3. Check Balance" << endl;
    cout << "\t\t\t4. Print Records" << endl; 
    cout << "\t\t\t5. Display TOP-Week" << endl;
    cout << "\t\t\t6. Display TOP-Month" << endl;
    cout << "\t\t\t7. Exit" << endl;
    cout << "Enter your choice: ";
}
void Menu::SetCurrentDate() {
    cout << "Enter current day: ";
    cin >> currentDay;
    cout << "Enter current month: ";
    cin >> currentMonth;
}
void Menu::openBalance() {

    cout << "\t\t\t1. Add wallet" << endl;
    cout << "\t\t\t2. Add card" << endl;
    cout << "\t\t\t3. Return to main menu" << endl;

    int choiceOpen = 0;
    cout << "Enter your choice: ";
    cin >> choiceOpen;

    switch (choiceOpen)
    {
    case 1:
        ClearConsole();
        AddWallet();
        break;
    case 2:
        ClearConsole();
        AddCard();
        break;
    case 3:
        break;
    default:
        ClearConsole();
        cout << "\n\t\t\tInvalid choice. Please try again." << endl;
        WaitForEnter();
        return;
    }
}
void Menu::Transactions() {

    cout << "\t\t\t1. Deposit" << endl;
    cout << "\t\t\t2. Withdraw" << endl;
    cout << "\t\t\t3. Return to main menu" << endl;

    int choiceTransactions = 0;
    cout << "Enter your choice: ";
    cin >> choiceTransactions;

    switch (choiceTransactions)
    {
    case 1:
        ClearConsole();
        MakeDeposit();
        break;
    case 2:
        ClearConsole();
        MakeWithdrawal();
        break;
    case 3:
        break;
    default:
        ClearConsole();
        cout << "\n\t\t\tInvalid choice. Please try again." << endl;
        WaitForEnter();
        return;
    }
}
void Menu::checkBalanceMenu() {
    cout << "\t\t\t1. Check specific balance " << endl;
    cout << "\t\t\t2. Check all balances" << endl;
    cout << "\t\t\t3. Return to main menu" << endl;
    int choiceBalance = 0;
    cout << "Enter your choice: ";
    cin >> choiceBalance;

    switch (choiceBalance)
    {
    case 1:
        ClearConsole();
        CheckBalance();
        break;
    case 2:
        ClearConsole();
        ShowAll();
        break;
    case 3:
        break;
    default:
        ClearConsole();
        cout << "\n\t\t\tInvalid choice. Please try again." << endl;
        WaitForEnter();
        return;
    }
}
void Menu::printRecordsMenu() {
    cout << "\t\t\t1. Print Records by day" << endl;
    cout << "\t\t\t2. Print Records by month" << endl;
    cout << "\t\t\t3. Print Records by week" << endl;
    cout << "\t\t\t4. Return to main menu" << endl;
    int choicePrint = 0;
    cout << "Enter your choice: ";
    cin >> choicePrint;

    switch (choicePrint)
    {
    case 1:
        ClearConsole();
        recordsByDay();
        break;
    case 2:
        ClearConsole();
        recordsByMonth();
        break;
    case 3:
        ClearConsole();
        recordsByWeek();
        break;
    case 4:
        break;
    default:
        ClearConsole();
        cout << "\n\t\t\tInvalid choice. Please try again." << endl;
        WaitForEnter();
        return;
    }

}
void Menu::HandleChoice(int choice) {
    switch (choice) {
    case 1:
        ClearConsole();
        openBalance();
        break;
    case 2:
        ClearConsole();
        Transactions();
        break;
    case 3:
        ClearConsole();
        checkBalanceMenu();
        break;
    case 4:
        ClearConsole();
        printRecordsMenu();
        break;
    case 5:
        DisplayTopCostForWeek();
        break;
    case 6:
        DisplayTopCostForMonth();
        break;
    case 7:
        SaveRecordsToFile("expense_records.txt");
        exit(0);
    default:
        ClearConsole();
        cout << "\n\t\t\tInvalid choice. Please try again." << endl;
        WaitForEnter();
        return;
    }
}
void Menu::switchRecCat(ExpenseRecord record) {
    switch (record.category) {
    case 1:
        cout << "Food\t";
        break;
    case 2:
        cout << "Rent\t";
        break;
    case 3:
        cout << "Online\t";
        break;
    case 4:
        cout << "Other\t";
        break;
    default:
        cout << "Unknown\t";
        break;
    }
 }
string Menu::GetCategoryName(int category) {
    switch (category) {
    case 1:
        return "Food";
    case 2:
        return "Rent";
    case 3:
        return "Online";
    case 4:
        return "Other";
    default:
        return "Unknown";
    }
}
void Menu::AddWallet() {

    string walletName;
    cout << "\nEnter wallet name: ";
    cin >> walletName;

    manager.AddWallet(walletName);

}
void Menu::AddCard() {

    string cardName;
    double creditLimit;

    cout << "\nEnter card name: ";
    cin >> cardName;
    cout << "Enter credit limit: ";
    cin >> creditLimit;

    manager.AddCard(cardName, creditLimit);
}
void Menu::MakeWithdrawal() {
    string name;
    double amount;
    int category;
    int day = currentDay;     
    int month = currentMonth;

    cout << "\nEnter wallet/card name: ";
    cin >> name;

    Wallet* wallet = manager.GetWallet(name);
    Card* card = manager.GetCard(name);

    if (wallet || card) {

        cout << "Enter withdrawal amount: ";
        cin >> amount;

        do {
            cout << "Choose category:\n1. Food\n2. Rent" << endl;
            cout << "3. Online\n4. Other" << endl;
            cin >> category;

        } while (category != 1 && category != 2 && category != 3 && category != 4);

        if (wallet) {
            wallet->Withdraw(amount);
        }
        else {
            card->MakePurchase(amount);
        }

        ExpenseRecord record = { name, amount, category, day, month };
        expenseRecords.push_back(record);
    }
    else {
        cout << "\\t\t\tWallet/Card not found." << endl;
        WaitForEnter();
        return;
    }
}
void Menu::MakeDeposit() {
    string name;
    double amount;

    cout << "\nEnter wallet/card name: ";
    cin >> name;

    Wallet* wallet = manager.GetWallet(name);
    Card* card = manager.GetCard(name);

    if (wallet || card) {

        cout << "Enter deposit amount: ";
        cin >> amount;

        if (wallet) {
            wallet->Deposit(amount);
        }
        else {
            card->Deposit(amount);
        }
    }
    else {
        cout << "\n\t\t\tWallet/Card not found." << endl;
        WaitForEnter();
        return;
    }
}
void Menu::CheckBalance() {
    string name;
    cout << "\nEnter wallet/card name: ";
    cin >> name;

    Wallet* wallet = manager.GetWallet(name);
    Card* card = manager.GetCard(name);

    if (wallet || card) {

        double balance = wallet ? wallet->GetBalance() : card->CheckBalance();
        cout << "\n\t\t\tBalance for " << name << ": " << balance << endl;
        WaitForEnter();
        return;

    }
    else {
        cout << "\n\t\t\tWallet/Card not found." << endl;
        WaitForEnter();
        return;

    }
}
void Menu::ShowAll() {
    manager.ShowAllBalances();
    WaitForEnter();
    return;

}
void Menu::PrintRecords() {
    cout << "\nExpense Records:" << endl;
    cout << "--------------------------------------------------------------" << endl;
    cout << "Name\tAmount\tCategory\tDay\tMonth" << endl;
    cout << "--------------------------------------------------------------" << endl;

    for (const ExpenseRecord& record : expenseRecords) {
        cout << record.name << "\t" << record.amount << "\t";

        switchRecCat(record);

        cout <<"\t" << record.day << "\t" << record.month << endl;
    }

    cout << "--------------------------------------------------------------" << endl;
    WaitForEnter();
    return;

}
void Menu::SaveRecordsToFile(const string& filename) {
    ofstream file(filename);

    if (!file.is_open()) {
        cerr << "Error: Unable to open file for writing." << endl;
        return;
    }

    for (const ExpenseRecord& record : expenseRecords) {
        file << record.name << "\t" << record.amount << "\t" << record.category << "\t" << record.day << "\t" << record.month << endl;
    }

    if (file.fail()) {
        cerr << "Error: Failed to write data to the file." << endl;
    }
    else {
        cout << "Expense records saved to " << filename << endl;
    }

    file.close();
}

void Menu::LoadRecordsFromFile(const string& filename) {
    ifstream file(filename);

    if (!file.is_open()) {
        cout << "File does not exist. No expense records loaded." << endl;
        return;
    }

    expenseRecords.clear(); 

    ExpenseRecord record;

    while (file >> record.name >> record.amount >> record.category >> record.day >> record.month) {
        expenseRecords.push_back(record);
    }

    file.close();
    cout << "Expense records loaded from " << filename << endl;
}

void Menu::recordsByDay()
{
    int searchDay = 0;
    int searchMonth = 0;
    cout << "Enter day to search: "; cin >> searchDay;
    cout << "Enter month to search: "; cin >> searchMonth;

    cout << "\nExpense Records by day " << searchDay << ":" << endl;
    cout << "--------------------------------------------------------------" << endl;
    cout << "Name\tAmount\tCategory\tMonth" << endl;
    cout << "--------------------------------------------------------------" << endl;

    for (const ExpenseRecord& record : expenseRecords) {
        if ((record.day == searchDay)&& record.month == searchMonth)
        {

            cout << record.name << "\t" << record.amount << "\t";

            switchRecCat(record);

            cout << "\t" << record.month << endl;
        }
    }

    cout << "--------------------------------------------------------------" << endl;
    WaitForEnter();
    return;

}
void Menu::recordsByMonth()
{
    int searchMonth = 0;
    cout << "Enter month to search: "; cin >> searchMonth;

    cout << "\nExpense Records by month " << searchMonth << ":" << endl;
    cout << "--------------------------------------------------------------" << endl;
    cout << "Name\tAmount\tCategory\tDay" << endl;
    cout << "--------------------------------------------------------------" << endl;

    for (const ExpenseRecord& record : expenseRecords) {
        if (record.month == searchMonth)
        {

            cout << record.name << "\t" << record.amount << "\t";

            switchRecCat(record);

            cout << "\t" << record.day << endl;
        }
    }

    cout << "--------------------------------------------------------------" << endl;
    WaitForEnter();
    return;

}
void Menu::recordsByWeek()
{    
    int searchWeek = 0;
    int searchMonth = 0;
    cout << "Enter week to search: "; cin >> searchWeek;
    cout << "Enter month to search: "; cin >> searchMonth;

    cout << "\nExpense Records by week " << searchWeek <<" of the "<< searchMonth <<" month" << ":" << endl;
    cout << "--------------------------------------------------------------" << endl;
    cout << "Name\tAmount\tCategory\tDay" << endl;
    cout << "--------------------------------------------------------------" << endl;

    for (const ExpenseRecord& record : expenseRecords) {
        if (searchWeek == 1)
        {
            if ((record.day >= 1 && record.day <=7) && record.month == searchMonth)
            {
                cout << record.name << "\t" << record.amount << "\t";

                switchRecCat(record);

                cout << "\t" << record.day << endl;
            }
        }
        if (searchWeek == 2)
        {
            if ((record.day >= 8 && record.day <= 14) && record.month == searchMonth)
            {
                cout << record.name << "\t" << record.amount << "\t";

                switchRecCat(record);

                cout << "\t" << record.day << endl;
            }
        }
        if (searchWeek == 3)
        {
            if ((record.day >= 15 && record.day <= 21) && record.month == searchMonth)
            {
                cout << record.name << "\t" << record.amount << "\t";

                switchRecCat(record);

                cout << "\t" << record.day << endl;
            }
        }
        if (searchWeek == 4)
        {
            if ((record.day >= 22 && record.day <= 31) && record.month == searchMonth)
            {
                cout << record.name << "\t" << record.amount << "\t";

                switchRecCat(record);

                cout << "\t" << record.day << endl;
            }
        }
    }
    cout << "--------------------------------------------------------------" << endl;
    WaitForEnter();
    return;

}
void Menu::CalculateTopCategories(double& topWeekTotal, double& topMonthTotal, vector<CategoryExpenses>& topWeekCategories, vector<CategoryExpenses>& topMonthCategories) {

    int weekStartDay = currentDay - 6;  

    for (const ExpenseRecord& record : expenseRecords) {

        if (record.day >= weekStartDay && record.day <= currentDay && record.month == currentMonth) {
            topWeekTotal += record.amount;
            topWeekCategories[record.category - 1].totalAmount += record.amount;
        }
    }

    for (const ExpenseRecord& record : expenseRecords) {
        if (record.month == currentMonth) {
            topMonthTotal += record.amount;
            topMonthCategories[record.category - 1].totalAmount += record.amount;
        }
    }

    sort(topWeekCategories.begin(), topWeekCategories.end(), [](const CategoryExpenses& a, const CategoryExpenses& b) {

        return a.totalAmount > b.totalAmount;
    });
    sort(topMonthCategories.begin(), topMonthCategories.end(), [](const CategoryExpenses& a, const CategoryExpenses& b) {

        return a.totalAmount > b.totalAmount;
    });
}
void Menu::DisplayTopCostForWeek() {
    int weekToDisplay;
    cout << "Enter the month: ";
    cin >> currentMonth;
    cout << "Enter the week of the month: ";
    cin >> weekToDisplay;

    double topWeekTotal = 0.0;
    unordered_map<int, double> topWeekCategories; 

    int startDay = (weekToDisplay - 1) * 7 + 1;
    int endDay = min(startDay + 6, 31); 

    for (const ExpenseRecord& record : expenseRecords) {
        if (record.day >= startDay && record.day <= endDay && record.month == currentMonth) {

            topWeekTotal += record.amount;
            topWeekCategories[record.category] += record.amount;
        }
    }

    vector<pair<int, double>> sortedWeekCategories(topWeekCategories.begin(), topWeekCategories.end());

    sort(sortedWeekCategories.begin(), sortedWeekCategories.end(),
        [](const pair<int, double>& a, const pair<int, double>& b) {
            return a.second > b.second;
        });

    cout << "\nTop Categories for Week " << weekToDisplay << " of Month " << currentMonth << ":" << endl;
    cout << "--------------------------------------------------------------" << endl;
    cout << "\tCategory\tTotal Amount" << endl;
    cout << "--------------------------------------------------------------" << endl;

    for (int i = 0; i < min(3, static_cast<int>(sortedWeekCategories.size())); i++) {
        int category = sortedWeekCategories[i].first;
        string categoryName = GetCategoryName(category);

        cout << "\t" << categoryName << ":\t\t$" << sortedWeekCategories[i].second << endl;
    }
    cout << "--------------------------------------------------------------" << endl;
    cout << "Total Expenses for the Week: $" << topWeekTotal << endl;
    cout << "--------------------------------------------------------------" << endl;

    WaitForEnter();
    return;

}
void Menu::DisplayTopCostForMonth() {
    cout << "Enter the month you want to display: ";
    cin >> currentMonth;

    topMonthTotal = 0.0;  
    topMonthCategories.clear();  

    for (int category = 1; category <= 4; ++category) {
        topMonthCategories.push_back({ category, 0.0 });
    }

    for (const ExpenseRecord& record : expenseRecords) {

        if (record.month == currentMonth) {

            topMonthTotal += record.amount;

            for (CategoryExpenses& categoryExpenses : topMonthCategories) {

                if (categoryExpenses.category == record.category) {
                    categoryExpenses.totalAmount += record.amount;
                    break; 
                }
            }
        }
    }

    vector<pair<int, double>> sortedMonthCategories(topMonthCategories.size());

    for (size_t i = 0; i < topMonthCategories.size(); ++i) {

        sortedMonthCategories[i] = { topMonthCategories[i].category, topMonthCategories[i].totalAmount };
    }

    sort(sortedMonthCategories.begin(), sortedMonthCategories.end(),
        [](const pair<int, double>& a, const pair<int, double>& b) {
            return a.second > b.second;
        });

    cout << "\nTop Categories for the Month of " << currentMonth << ":" << endl;
    cout << "--------------------------------------------------------------" << endl;
    cout << "\tCategory\tTotal Amount" << endl;
    cout << "--------------------------------------------------------------" << endl;

    for (int i = 0; i < min(3, static_cast<int>(sortedMonthCategories.size())); i++) {
        int category = sortedMonthCategories[i].first;
        string categoryName = GetCategoryName(category);

        cout << "\t" << categoryName << ":\t\t$" << sortedMonthCategories[i].second << endl;
    }
    cout << "--------------------------------------------------------------" << endl;
    cout << "Total Expenses for the Month: $" << topMonthTotal << endl;
    cout << "--------------------------------------------------------------" << endl;
    WaitForEnter();
    return;

}
void Menu::WaitForEnter() {

    cout << "\nPress Enter to continue...";
    cin.ignore();
    cin.get();
}
