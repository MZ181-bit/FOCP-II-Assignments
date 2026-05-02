#include <iostream>
#include <vector>
#include <string>
#include <random>
using namespace std;

// Replaces ALL occurrences of "{name}" with userName
string replaceAllName(string text, const string& userName) {
    const string placeholder = "{name}";
    size_t pos = 0;

    // Find and replace repeatedly
    while ((pos = text.find(placeholder, pos)) != string::npos) {
        text.replace(pos, placeholder.length(), userName);
        pos += userName.length(); // move past the replaced text
    }
    return text;
}

int main() {
    string userName;
    cout << "Enter your name: ";
    getline(cin, userName);

    vector<string> roasts = {
        "{name} writes code so slow...",
        "Even the compiler waits for {name}.",
        "{name}, your logic has buffering issues."
    };

    // Proper randomness
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dist(0, roasts.size() - 1);

    string selected = roasts[dist(gen)];

    // Replace placeholder correctly
    string result = replaceAllName(selected, userName);

    cout << "Roast: " << result << endl;
    return 0;
}