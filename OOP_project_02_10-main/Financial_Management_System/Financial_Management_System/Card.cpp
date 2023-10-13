#include "Card.h"
#include <iostream>

Card::Card()
{
    cardName = "";
    cardBalance= 0.0;
    creditLimit = 0.0;
}

Card::Card(const string& cardName, double cardBalance, double creditLimit)  {
    this->cardName = cardName;
    this->cardBalance = cardBalance;
    this->creditLimit = creditLimit;
}

void Card::Deposit(double amount) {
    if (amount > 0) {
        cardBalance += amount;
        cout << "Deposited " << amount << " into " << cardName << " card." << endl;
        WaitForEnter();
        return;

    }
}

void Card::MakePurchase(double amount) {
    if (amount > 0 && amount <= cardBalance + creditLimit) {
        cardBalance -= amount;
        cout << "Made a purchase of " << amount << " using " << cardName << " card." << endl;
        WaitForEnter();
        return;

    }
    else {
        cout << "Purchase declined for " << cardName << " card due to insufficient balance/limit." << endl;
        WaitForEnter();
        return;

    }
}

double Card::CheckBalance() const {
    return cardBalance;
}

string Card::GetName() const {
    return cardName;
}
void Card::WaitForEnter() {

    cout << "\nPress Enter to continue...";
    cin.ignore();
    cin.get();
}
