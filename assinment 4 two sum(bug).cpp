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

    for(int i = 0; i < n; i++) {
        int complement = target - arr[i];

        if(mp.find(complement) != mp.end()) {
            cout << "Indices: " << mp[complement] << " " << i << endl;
            return 0;
        }

        mp[arr[i]] = i;
    }

    // ❌ BUG: no proper handling
    cout << "Indices: 0 0" << endl;

    return 0;
}