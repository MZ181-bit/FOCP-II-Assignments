#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

class Bank {
    unordered_map<int, int> accounts; // userID -> balance

public:
    bool create(int userID, int amount) {
        if (accounts.find(userID) == accounts.end()) {
            accounts[userID] = amount;
            return true; // new account created
        } else {
            accounts[userID] += amount; // add to existing account
            return false;
        }
    }

    bool debit(int userID, int amount) {
        if (accounts.find(userID) == accounts.end()) return false;
        if (accounts[userID] < amount) return false;
        accounts[userID] -= amount;
        return true;
    }

    bool credit(int userID, int amount) {
        if (accounts.find(userID) == accounts.end()) return false;
        accounts[userID] += amount;
        return true;
    }

    int balance(int userID) {
        if (accounts.find(userID) == accounts.end()) return -1;
        return accounts[userID];
    }
};

int main() {
    int Q;
    cin >> Q;
    Bank bank;

    while (Q--) {
        string query;
        cin >> query;

        if (query == "CREATE") {
            int X, Y;
            cin >> X >> Y;
            cout << (bank.create(X, Y) ? "true" : "false") << "\n";
        } else if (query == "DEBIT") {
            int X, Y;
            cin >> X >> Y;
            cout << (bank.debit(X, Y) ? "true" : "false") << "\n";
        } else if (query == "CREDIT") {
            int X, Y;
            cin >> X >> Y;
            cout << (bank.credit(X, Y) ? "true" : "false") << "\n";
        } else if (query == "BALANCE") {
            int X;
            cin >> X;
            cout << bank.balance(X) << "\n";
        }
    }
    return 0;
}
