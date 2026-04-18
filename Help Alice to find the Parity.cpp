#include <bits/stdc++.h>
using namespace std;

int main() {
    long long L, R;
    cin >> L >> R;

    // Count odd numbers in [L, R]
    long long countOdd = (R + 1) / 2 - L / 2;

    if (countOdd % 2 == 0)
        cout << "even\n";
    else
        cout << "odd\n";

    return 0;
}
