#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        int N;
        cin >> N;
        vector<int> freq(1001, 0);
        for (int i = 0; i < N; ++i) {
            int x; cin >> x;
            if (x >= 1 && x <= 1000) freq[x]++;
        }
        
        vector<int> tokens;
        tokens.reserve(2000);
        for (int v = 1; v <= 1000; ++v) {
            int take = min(2, freq[v]);
            for (int k = 0; k < take; ++k) tokens.push_back(v);
        }
        sort(tokens.rbegin(), tokens.rend());
        
        long long alex = 0, bob = 0;
        bool turnAlex = true;
        for (int val : tokens) {
            if (turnAlex) alex += val;
            else bob += val;
            turnAlex = !turnAlex;
        }
        
        if (alex > bob) cout << "Alex\n";
        else cout << "Bob\n";
    }
    return 0;
}
