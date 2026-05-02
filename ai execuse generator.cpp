#include <iostream>
#include <vector>
#include <string>
#include <random>

using namespace std;

// Replace all occurrences of {name}
string replaceName(string text, const string& name) {
    const string placeholder = "{name}";
    size_t pos = text.find(placeholder);

    while (pos != string::npos) {
        text.replace(pos, placeholder.length(), name);
        pos = text.find(placeholder, pos + name.length());
    }
    return text;
}

// Generate random index using modern C++
int getRandomIndex(int maxIndex) {
    static random_device rd;
    static mt19937 gen(rd());
    uniform_int_distribution<int> dist(0, maxIndex);
    return dist(gen);
}

int main() {
    string name;
    cout << "Enter your name: ";
    getline(cin, name);

    vector<string> excuses = {
        "{name} forgot the homework at home.",
        "{name}'s laptop stopped working suddenly.",
        "{name} had a power cut while studying.",
        "{name} was helping someone in need.",
        "{name} got stuck in traffic.",
        "{name}'s file got deleted accidentally.",
        "{name} was not feeling well.",
        "{name} missed the deadline by mistake.",
        "{name} had internet issues.",
        "{name} was busy with an emergency."
    };

    int index = getRandomIndex(excuses.size() - 1);
    string result = replaceName(excuses[index], name);

    cout << "\nExcuse:\n" << result << endl;

    return 0;
}