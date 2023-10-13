#include "PersonalFinanceManager.h"
#include <iostream>

void PersonalFinanceManager::AddWallet(const string& name) {

    for (const Wallet& wallet : wallets) {
        if (wallet.GetName() == name) {
            cout << "\n\t\t\tA wallet with the name " << name << " already exists." << endl;
            WaitForEnter();
            return;
        }
    }

    Wallet newWallet(name);
    wallets.push_back(newWallet);
    cout << "\n\t\t\tAdded a new " << name << " wallet." << endl;
    WaitForEnter();
    return;
}

void PersonalFinanceManager::AddCard(const string& name, double limit) {

    for (const Card& card : cards) {
        if (card.GetName() == name) {
            cout << "\n\t\t\tA card with the name " << name << " already exists." << endl;
            return;
        }
    }

    Card newCard(name, 0, limit); 
    cards.push_back(newCard);
    cout << "\n\t\t\tAdded a new " << name << " card with a credit limit of " << limit << "." << endl;
    WaitForEnter();
    return;

}

Wallet* PersonalFinanceManager::GetWallet(const string& name) {
    for (Wallet& wallet : wallets) {
        if (wallet.GetName() == name) {
            return &wallet;
        }
    }
    return nullptr; 
}

Card* PersonalFinanceManager::GetCard(const string& name) {
    for (Card& card : cards) {
        if (card.GetName() == name) {
            return &card;
        }
    }
    return nullptr; 
}

void PersonalFinanceManager::ShowWalletBalances() const {
    cout << "\t\t\tWallet Balances:" << endl;
    for (const Wallet& wallet : wallets) {
        cout << "\t\t\t" << wallet.GetName() << ": " << wallet.GetBalance() << endl;
    }
}
void PersonalFinanceManager::ShowAllBalances() const {

    cout << "\t\t\tWallet Balances:" << endl;
    for (const Wallet& wallet : wallets) {
        cout << "\t\t\t" << wallet.GetName() << ": " << wallet.GetBalance() << endl;
    }

    cout << "\t\t\tCard Balances:" << endl;
    for (const Card& card : cards) {
        cout <<"\t\t\t" << card.GetName() << ": " << card.CheckBalance() << endl;
    }

}
void PersonalFinanceManager::WaitForEnter() {

    cout << "\nPress Enter to continue...";
    cin.ignore(); 
    cin.get();
}
