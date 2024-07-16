#include <iostream>
#include "bank.hpp"
#include <cstdlib>


using namespace std;

void displaySystem(){
    cout << endl;
    cout << "======================" << endl;
    cout << "BANK MANAGEMENT SYSTEM" << endl;
    cout << "======================" << endl;
    cout << "         MENU         \n" << endl;
    cout << " 1. NEW ACCOUNT \n 2. DEPOSIT AMOUNT \n 3. WITHDRAW AMOUNT \n 4. VIEW BALANCE \n 5. DISPLAY ACCOUNT HOLDERS \n 6. CLOSE AN ACCOUNT \n 7. UPDATE ACCOUNT \n 8. EXIT \n Select Your Option (1-8) " << endl;
    cout << "----------------------" << endl;
    cout << endl;
}   


void account::show_account(){
    cout << "Account No. : " << accountNumber << endl;
    cout << "Account Holder Name : " << name << endl;
    cout << "Type of Account : " << type << endl;
    cout << "Balance amount : " << deposit << endl;
}

void account::modify_account(){
    cout << "What would you like to modify (n for account name, t for account type)" << endl;
    string option;
    getline(cin,option);

    if(option == "n"){
        cout << "Please enter your full name: " << endl;
        getline(cin, name);

    }
    else if(option == "t"){
        cout << "Which account type would you like: Checkings (c) or Savings (s)?" << endl;
        while(getline(cin, type)){
            if (type == "c" || type == "s") break;
            else cout << "Please enter c for checkings or s for savings." << endl;
        }   
    }
}

void account::deposit_money(int amount){
    deposit += amount;
    cout << "Successfully deposited $" << amount << endl;
}

void account::withdraw_money(int amount){
    if(deposit >= amount){
        deposit -= amount;
        cout << "Successfully withdrew $" << amount << endl;
    }
    else {
        cout << "ERROR: Balance is too low!";
    }
}

int account::get_account_num(){
    return accountNumber;
}

int account::get_deposit(){
    return deposit;
}

string account::get_type(){
    return type;
}

 void bankManagement::add_account(){
    cout << "Welcome to the C++ Bank!" << endl;

    cout << "Please enter your full name: " << endl;
    string name;
    getline(cin, name);

    string type;
    cout << "Which account type would you like: Checkings (c) or Savings (s)?" << endl;
    while(getline(cin, type)){
        if(type == "c" || type == "s") break;
        else cout << "Please enter c for checkings or s for savings." << endl;
    }
    
    cout << "Please enter an initial deposit: " << endl;
    string depositString;
    getline(cin, depositString);
    int deposit = stoi(depositString);

    string acno = " ";
    for(int i = 0; i < 8; ++i){
        acno += to_string((rand() % 9));
    }
    int accountNumber = stoi(acno);

    cout << "An account of type " << type << " for " << name << " has been created with the account number" << acno << ". It contains $" << deposit << '.' << endl;
    accounts.push_back(account(accountNumber, name, deposit, type));
 }

 void bankManagement::show_all_accounts(){
    cout << "ALL ACCOUNT HOLDERS: " << endl;
    cout << endl;
    for (size_t i = 0; i < accounts.size(); ++i){
        accounts[i].show_account();
        cout << "___________________________" << endl;
    }
 }

 account* bankManagement::find_account(int accountNumber){
    for(int i = 0; i < accounts.size(); i++){
        if(accounts[i].get_account_num() == accountNumber) return &accounts[i];
    }
    return NULL;
 }

 void bankManagement::remove_account(int accountNumber){
    int index; 
     for(int i = 0; i < accounts.size(); i++){
        if(accounts[i].get_account_num() == accountNumber) index = i;
    }
    accounts.erase(accounts.begin() + index);
 }