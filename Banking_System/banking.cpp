#include <iostream>
#include <vector>
using namespace std;

class Transaction {
    public:
         int transactionId;
         string type;
         double amount;
    Transaction(int id, string t, double amt){
        transactionId = id;
        type = t;
        amount = amt; 
    }     
};

class Customer {
public:
     int customerId;
     string name;
     string phone;
Customer(int id, string n, string p){
    customerId = id;
    name = n;
    phone = p;
}     

};

class Account {
    public:
         int accountNumber;
         double balance;
         int customerId;
         vector<Transaction> transactions;
    Account (int accNo, int custId){
        accountNumber = accNo;
        customerId = custId;
        balance = 0.0;
    }     
     void addTransaction (Transaction t)
       {transactions.push_back(t);}
    void deposit(double amount, int&tId){
        if (amount <= 0){
            cout << "Invalid amount! \n";
            return;
        }
        balance += amount;
addTransaction(Transaction (tId++, "Deposit", amount));
        cout << "Deposit successful. Balance: " << balance << endl;
    }
    void withdraw (double amount, int&tId ){
        if (amount <= 0){
            cout << "Invalid amount! \n";
              return; }
           if(amount > balance){
            cout << "Insufficient funds! \n";
              return;
           } 
           balance -= amount;
addTransaction(Transaction(tId++, "Withdrawal", amount));
        cout << "Withdrawal successful. Balance: " << balance << endl;     
        }

        void showTransactions() {
            cout << "\n---Transaction History---\n";
            if(transactions.empty()){
                cout << "No transactions yet. \n";
                return;
            }
            for(auto &t : transactions){
                cout << "ID: " << t.transactionId
                << " | Type: " << t.type
                << " | Amount: " << t.amount << endl;
            }
        }
        void displayAccountInfor(){
            cout << "\n=== Account Infor ===\n";
            cout << "Account Number: " << accountNumber << endl;
            cout << "Balance: " << balance << endl;
                showTransactions();
        }
    };


class BankSystem{
    private:
       vector<Customer> customers;
       vector<Account> accounts;
       int transactionCounter = 1;

    public:
       void createCustomer(int id, string name, string phone){
        customers.push_back(Customer(id, name,phone));
           cout << "Customer created successfully. \n";
       }
       void createAccount(int accNo, int custId){
        accounts.push_back(Account(accNo,custId));
           cout << "Account created successfully. \n";
       }
    Account* findAccount(int accNo){
        for (auto &acc : accounts){
            if (acc.accountNumber == accNo)
              return &acc;
        }
        return nullptr;
    }  
    
       void deposit(int accNo, double amount){
        Account* acc = findAccount(accNo);
          if (acc) acc->deposit(amount, transactionCounter);
          else cout << "Account not found. \n";
       }

       void withdraw(int accNo, double amount){
        Account* acc = findAccount(accNo);
          if(acc) acc->withdraw(amount, transactionCounter);
          else cout << "Account not found. \n";
       }

       void transfer(int fromAcc, int toAcc, double amount) {
        Account*sender = findAccount(fromAcc);
        Account*receiver = findAccount(toAcc);
          if (!sender || !receiver){
            cout << "One or both accounts not found. \n";
               return;
          }
        if (amount <= 0){
            cout << "Invalid amount! \n";
              return;
        }

        if (sender->balance < amount){
            cout << "Insufficient funds. \n";
              return;
        }
        sender->balance -= amount;
        receiver->balance += amount;

sender->addTransaction(Transaction(transactionCounter++, "Transfer Out", amount));
receiver->addTransaction(Transaction(transactionCounter++, "Transfer In", amount));
          cout << "Transfer successful. \n";      
         }

         void showAccountDetails(int accNo){
            Account* acc = findAccount(accNo);
            if (acc) acc->displayAccountInfor();
            else cout << "Account not found. \n ";
         }
};

int main (){
    BankSystem bank;
    int choice;

    do{
        cout << "\n===== BANK SYSTEM =====\n";
        cout << "1. Create Customer Details\n";
        cout << "2. Create Account\n";
        cout << "3. Deposit\n";
        cout << "4. Withdraw\n";
        cout << "5. Transfer\n";
        cout << "6. View Account Details\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
    
    if (choice == 1){
        int id;
        string name;
        string phone;
        cout << "Enter customer ID: ";
        cin >> id;
        cout << "Enter name: ";
        cin >> name;
        cout << "Enter phone number: ";
        cin >> phone;
    bank.createCustomer(id, name, phone);    
    }
    else if(choice == 2){
        int accNo, custId;
        cout << "Enter Account Number: ";
        cin >> accNo;
        cout << "Enter Customer ID: ";
        cin >> custId;
    bank.createAccount(accNo, custId);    
    }
    else if(choice == 3){
        int accNo;
        double amount;
        cout << "Enter Account Number: ";
        cin >> accNo;
        cout << "Enter Amount: ";
        cin >> amount;
    bank.deposit(accNo, amount);    
    }
     else if(choice == 4){ 
        int accNo;
        double amount;
        cout << "Enter Account Number: ";
        cin >> accNo;
        cout << "Enter Amount: ";
        cin >> amount;
    bank.withdraw(accNo, amount);    
     }   

     else if(choice == 5){
        int fromAcc, toAcc;
        double amount;
        cout << "From Account: ";
        cin >> fromAcc;
        cout << "To Account: ";
        cin >> toAcc;
        cout << "Amount: ";
        cin >> amount;
    bank.transfer(fromAcc, toAcc, amount);    
     }

     else if(choice == 6){
        int accNo;
        cout << "Enter Account Number: ";
        cin >> accNo;
    bank.showAccountDetails(accNo);    
     }

    }while (choice != 0);
    cout << "Exiting System... \n";

    return 0;
}