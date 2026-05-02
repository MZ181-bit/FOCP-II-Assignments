#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    // Seed random
    srand(time(0));

    // Take input
    string name;
    cout << "Enter your name: ";
    getline(cin, name);

    // Roast templates
    vector<string> roasts = {
        "{name} writes code so slow...",
        "Even the compiler waits for {name}.",
        "{name}, your logic has buffering issues."
    };

    // Random selection
    int index = rand() % roasts.size();
    string selected = roasts[index];

    // ❌ BUG: Only replaces first occurrence
    size_t pos = selected.find("{name}");
    if (pos != string::npos) {
        selected.replace(pos, 6, name); // replaces only once
    }

    // Output
    cout << "Roast: " << selected << endl;

    return 0;
}