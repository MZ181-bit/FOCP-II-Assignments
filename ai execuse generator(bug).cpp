#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    string name;
    cout << "Enter your name: ";
    cin >> name; // BUG: won't take full name (stops at space)

    vector<string> excuses = {
        "{name} forgot the homework at home.",
        "{name}'s laptop stopped working suddenly.",
        "{name} had a power cut while studying."
    };

    srand(1); // BUG: fixed seed → same result every time

    int index = rand() % excuses.size();
    string result = excuses[index];

    // BUG: replaces only first occurrence AND wrong length (5 instead of 6)
    size_t pos = result.find("{name}");
    if (pos != string::npos) {
        result.replace(pos, 5, name); // incorrect length
    }

    cout << "\nExcuse:\n" << result << endl;

    return 0;
}