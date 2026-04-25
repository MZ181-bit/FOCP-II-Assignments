#include <iostream>
#include <string>
using namespace std;

class MovieTicket {
    int booked[1001][101];   // movieID up to 1000, customerID check
    int available[1001];     // tickets left for each movie

public:
    MovieTicket() {
        for (int i = 0; i <= 1000; i++) {
            available[i] = 100; // each movie starts with 100 tickets
            for (int j = 0; j <= 100; j++) booked[i][j] = 0;
        }
    }

    bool book(int customerID, int movieID) {
        if (booked[movieID][customerID]) return false; // already booked
        if (available[movieID] == 0) return false;      // sold out
        booked[movieID][customerID] = 1;
        available[movieID]--;
        return true;
    }

    bool cancel(int customerID, int movieID) {
        if (!booked[movieID][customerID]) return false; // not booked
        booked[movieID][customerID] = 0;
        available[movieID]++;
        return true;
    }

    bool isBooked(int customerID, int movieID) {
        return booked[movieID][customerID];
    }

    int availableTickets(int movieID) {
        return available[movieID];
    }
};

int main() {
    int Q;
    cin >> Q;
    MovieTicket mt;

    while (Q--) {
        string query;
        cin >> query;

        if (query == "BOOK") {
            int X, Y;
            cin >> X >> Y;
            cout << (mt.book(X, Y) ? "true" : "false") << "\n";
        } else if (query == "CANCEL") {
            int X, Y;
            cin >> X >> Y;
            cout << (mt.cancel(X, Y) ? "true" : "false") << "\n";
        } else if (query == "IS_BOOKED") {
            int X, Y;
            cin >> X >> Y;
            cout << (mt.isBooked(X, Y) ? "true" : "false") << "\n";
        } else if (query == "AVAILABLE_TICKETS") {
            int Y;
            cin >> Y;
            cout << mt.availableTickets(Y) << "\n";
        }
    }
    return 0;
}

