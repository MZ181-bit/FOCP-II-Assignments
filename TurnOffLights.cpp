#include <bits/stdc++.h>
using namespace std;

// Function to check if given l works within k operations
bool canTurnOff(const string &s, int n, int k, int l) {
    int ops = 0;
    int i = 0;
    while (i < n) {
        if (s[i] == '1') {
            ops++;
            i += l; // skip l bulbs since they are turned off
            if (ops > k) return false;
        } else {
            i++;
        }
    }
    return ops <= k;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    string s;
    cin >> n >> k >> s;

    int low = 1, high = n, ans = n;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (canTurnOff(s, n, k, mid)) {
            ans = mid;
            high = mid - 1; // try smaller l
        } else {
            low = mid + 1; // need larger l
        }
    }

    cout << ans << "\n";
    return 0;
}