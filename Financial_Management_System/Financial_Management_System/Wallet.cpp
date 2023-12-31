#include "Wallet.h"
#include <iostream>

Wallet::Wallet()
{
    walletName = "";
    balance = 0.0;
}

Wallet::Wallet(const string& walletName, double balance) {
    this->walletName = walletName;
    this->balance = balance;
}

void Wallet::Deposit(double amount) {
    if (amount > 0) {
        balance += amount;
        cout << "Deposited " << amount << " into " << walletName << " wallet." << endl;
        WaitForEnter();
        return;

    }
}

void Wallet::Withdraw(double amount) {
    if (amount > 0 && amount <= balance) {
        balance -= amount;
        cout << "Withdrawn " << amount << " from " << walletName << " wallet." << endl;
        WaitForEnter();
        return;

    }
    else {
        cout << "Insufficient balance in " << walletName << " wallet." << endl;
        WaitForEnter();
        return;

    }
}

double Wallet::GetBalance() const {
    return balance;
}

string Wallet::GetName() const {
    return walletName;
}
void Wallet::WaitForEnter() {

    cout << "\nPress Enter to continue...";
    cin.ignore();
    cin.get();
}
