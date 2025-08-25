#include <iostream>
using namespace std;

class BankAccount {
private:
    int balance;

public:
    
    BankAccount() {
        balance = 0;
    }

   
    BankAccount(int bal) {
        balance = bal;
    }

    
    BankAccount(const BankAccount &acc) {
        balance = acc.balance;
    }

    
    int getBal() {
        return balance;
    }

    
    void withdraw(int amount) {
        if (amount <= balance) {
            balance -= amount;
        } else {
            cout << "Amount is Greater than total balance" << endl;
        }
    }
};

int main() {
    
    BankAccount acc1;  
    cout << "Account 1 Balance:" << acc1.getBal() <<" $"<< endl;

    
    BankAccount acc2(1000);  
    cout << "Account 2 Balance:" << acc2.getBal() <<" $"<< endl;

    
    BankAccount acc3(acc2);  
     cout << "Account 3 Balance:" << acc3.getBal() <<" $"<< endl;
    acc3.withdraw(200);  
     cout << "Updatd Account 3 Balance:" << acc3.getBal() <<" $"<< endl;
    
    cout << "Account 2 Balance:" << acc2.getBal() <<" $"<< endl;

    return 0;
}
