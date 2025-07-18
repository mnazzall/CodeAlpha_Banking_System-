#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

class Transaction {
public:
    string type;
    float amount;
    Transaction(string t, float a) : type(t), amount(a) {}
};

class Account {
public:
    int accNo;
    float balance;
    vector<Transaction> history;

    Account(int accNo, float balance = 0.0f) : accNo(accNo), balance(balance) {
        
        ifstream fin("balance_" + to_string(accNo) + ".txt");
        if (fin.is_open()) fin >> balance;
    }

    void deposit(float amount) {
        balance += amount;
        history.push_back(Transaction("Deposit", amount));
        saveBalance();
        saveTransaction("Deposit", amount);
        cout << "Deposited successfully.\n";
    }

    void withdraw(float amount) {
        if (amount > balance) {
            cout << "No balance enough\n";
        } else {
            balance -= amount;
            history.push_back(Transaction("Withdraw", amount));
            saveBalance();
            saveTransaction("Withdraw", amount);
            cout << "Withdrawn successfully.\n";
        }
    }

    void showHistory() {
        cout << "\n--- Transaction History for Account " << accNo << " ---\n";
        ifstream fin("history_" + to_string(accNo) + ".txt");
        string line;
        while (getline(fin, line)) cout << line << endl;
    }

    void saveBalance() {
        ofstream fout("balance_" + to_string(accNo) + ".txt");
        fout << balance;
    }

    void saveTransaction(string type, float amount) {
        ofstream fout("history_" + to_string(accNo) + ".txt", ios::app);
        fout << type << ": $" << amount << endl;
    }
};

class Customer {
public:
    string name;
    string password;
    Account account;

    Customer(string name, int accNo, string password = "") : name(name), password(password), account(accNo) {}

    void showInfo() {
        cout << "\n--- Account Info ---\n";
        cout << "Name: " << name << endl;
        cout << "Account number: " << account.accNo << endl;
        cout << "Balance: " << account.balance << endl;
    }

    void registration() {
        ifstream check("user.txt");
        string line;
        while (getline(check, line)) {
            if (line.find(name + ":" + to_string(account.accNo)) == 0) {
                cout << "Account already exists.\n";
                return;
            }
        }
        ofstream file("user.txt", ios::app);
        if (file.is_open()) {
            file << name << ":" << account.accNo << ":" << password << endl;
            cout << "Registration successful!\n";
        } else {
            cout << "Error: Could not open file.\n";
        }
    }

    bool login() {
        ifstream file("user.txt");
        string line;
        string expected = name + ":" + to_string(account.accNo) + ":" + password;
        while (getline(file, line)) {
            if (line == expected) return true;
        }
        return false;
    }
};

int main() {
    int choice;
    
    
    while(true)
    {
        
    cout << "1. Register\n2. Login\n3. Exit\nEnter choice: ";
    cin >> choice;
    cin.ignore();
    
    
    if (choice == 1) {
        string name, password;
        int accNo;
        cout << "Enter your name: ";
        getline(cin, name);
        cout << "Enter an account number: ";
        cin >> accNo;
        cin.ignore();
        cout << "Create a password: ";
        getline(cin, password);
        Customer cust(name, accNo, password);
        cust.registration();
    } 
    
    else if (choice == 2) {
        string name, password;
        int accNo;
        cout << "Enter your name: ";
        getline(cin, name);
        cout << "Enter your account number: ";
        cin >> accNo;
        cin.ignore();
        cout << "Enter your password: ";
        getline(cin, password);
        Customer cust(name, accNo, password);

        if (cust.login()) {
            cout << "\nLogin successful!\n";
            int choiceOfBank;
            while (true) {
                cout << "\n1. Deposit\n2. Withdraw\n3. Show Info\n4. Show History\n5. Exit\nEnter choice: ";
                cin >> choiceOfBank;
                if (choiceOfBank == 1) {
                    float amount;
                    cout << "Enter the amount you want to deposit: ";
                    cin >> amount;
                    cust.account.deposit(amount);
                } else if (choiceOfBank == 2) {
                    float amount;
                    cout << "Enter the amount you want to withdraw: ";
                    cin >> amount;
                    cust.account.withdraw(amount);
                } else if (choiceOfBank == 3) {
                    cust.showInfo();
                } else if (choiceOfBank == 4) {
                    cust.account.showHistory();
                } else if (choiceOfBank == 5) {
                    cout << "\nThank you for using our banking system.\n";
                    break;
                } else {
                    cout << "Invalid choice.\n";
                }
            }
        } else 
        {
            cout << "\nInvalid username or account number or password.\n";
        }
    } 
    
    else if (choice == 3) 
    {
        break;
    }
    else 
    {
        cout << "\nInvalid choice.\n";
    }
    
    }
    return 0;
}
