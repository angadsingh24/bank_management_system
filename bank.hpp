#include <string> 
#include <vector>

//MODIFIES: cout 
//EFFECTS: Prints the main menu of the bank management system to standard output
void displaySystem();

//Class to hold each bank account
class account
{
    private:
        int accountNumber;
        std::string name;
        int deposit;
        std::string type;
    public:

        //Constructor
        account(int num, std::string n, int dep, std::string t){
            accountNumber = num; 
            name = n; 
            deposit = dep; 
            type = t;
        }

        //MODIFIES: cout 
        //EFFECTS: prints the contents of the desired account to standard output
        void show_account();
        //MODIFIES: account, cout
        //EFFECT: allows a user to change an account's name and type
        void modify_account();
        //MODIFIES: account.deposit, cout
        //EFFECT: adds a certain amount of money to the current balance (saved in deposit variable)
        void deposit_money(int amount);
        //MODIFIES: account.deposit, cout
        //EFFECT: subtracts a certain amount of money to the current balance (saved in deposit variable)
        void withdraw_money(int amount);
        //EFFECTS: returns the account number
        int get_account_num();
        //EFFECTS: returns the account balance
        int get_deposit();
        //EFFECTS: returns the account type (checking or saving)
        std::string get_type();
};

//Class to hold all the accounts, stored in the vector accounts
class bankManagement{
    private:
        std::vector<account> accounts;
    public:
        //MODIFIES: cout, accounts
        //EFFECTS: Adds an account to accounts
        void add_account(); 
        //MODIFIES: cout
        //Prints all the accounts (number, name, type, balance) to standard output
        void show_all_accounts();
        //EFFECTS: returns a pointer to an account in accounts based on its accountNumber
        account* find_account(int accountNumber);
        //MODIFIES: accounts
        //EFFECTS: removes an account from accounts based on its accountNumber
        void remove_account(int accountNumber);
    
};

