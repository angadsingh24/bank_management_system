#include <iostream>
#include "bank.hpp"

using namespace std; 

int main(){
    bankManagement bank;
    string op;
    
    do {

        system("clear");
        displaySystem();

        string choice;
        getline(cin,choice);
        int selection = stoi(choice);

        switch(selection){
            case 1: {
                bank.add_account();
                break;
            }
            case 2: {
                cout << "Enter your account number: " << endl;
                string num;
                getline(cin, num);
                int number = stoi(num);

                if(bank.find_account(number)!= NULL){
                    cout << "Enter the desired amount to be deposited: " << endl;
                    string depnum; 
                    getline(cin, depnum);
                    int dep_num = stoi(depnum);
                    bank.find_account(number)->deposit_money(dep_num);
                }
                else cout << "Account not found!" << endl;
                break;


            }
            case 3: {
                cout << "Enter your account number: " << endl;
                string num;
                getline(cin, num);
                int number = stoi(num);

                if(bank.find_account(number) != NULL){
                    cout << "Enter the desired amount to be withdrawn: " << endl;
                    string withnum; 
                    getline(cin, withnum);
                    int with_num = stoi(withnum);
                    bank.find_account(number)->withdraw_money(with_num);
                }
                else cout << "Account not found!" << endl;
                break;
            }

            case 4: {
                cout << "Enter your account number: " << endl;
                string num;
                getline(cin, num);
                int number = stoi(num);

                if(bank.find_account(number) != NULL){
                    cout << "Your balance is: $" << bank.find_account(number)->get_deposit() << endl;
                }
                else cout << "Account not found!" << endl;
                break;
            }

            case 5: {
                bank.show_all_accounts();
                break;
            }

            case 6: {
                cout << "Enter your account number: " << endl;
                string num;
                getline(cin, num);
                int number = stoi(num);

                if(bank.find_account(number) != NULL){
                    bank.remove_account(number);
                    cout << "Your account has been removed" << endl;
                }
                else cout << "Account not found!" << endl;
                break;
            }

            case 7: {
                cout << "Enter your account number: " << endl;
                string num;
                getline(cin, num);
                int number = stoi(num);

                if(bank.find_account(number) != NULL){
                    bank.find_account(number)->modify_account();
                    cout << "Your account has been modified" << endl;
                }
                else cout << "Account not found!" << endl;
                break;
                
            }

            case 8: {
                exit(1);
                break;
            }
        }
        cout << "Would you like to continue (y/n)?" << endl;
        getline(cin, op);

    } while(op == "y");
    return 0;
}