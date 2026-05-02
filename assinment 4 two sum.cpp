#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main() {
    int n, target;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter elements: ";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Enter target: ";
    cin >> target;

    unordered_map<int, int> mp;
    bool found = false;

    for(int i = 0; i < n; i++) {
        int complement = target - arr[i];

        if(mp.find(complement) != mp.end()) {
            cout << "Indices: " << mp[complement] << " " << i << endl;
            found = true;
            break;
        }

        mp[arr[i]] = i;
    }

    if(!found) {
        cout << "No valid pair found" << endl;
    }

    return 0;
}