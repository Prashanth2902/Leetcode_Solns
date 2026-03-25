#include <iostream>
#include <cmath>
using namespace std;

bool isImperfect(long long m) {
    if (m <= 0) return false;
    bool div2 = (m % 2 == 0);
    bool div5 = (m % 5 == 0);
    return div2 ^ div5;
}

void solve() {
    long long n;
    cin >> n;

    if (isImperfect(n)) {
        cout << 0 << endl;
        return;
    }

    long long diff = 1;
    while (true) {
        if (n - diff > 0 && isImperfect(n - diff)) {
            cout << diff << endl;
            break;
        }
        if (isImperfect(n + diff)) {
            cout << diff << endl;
            break;
        }
        diff++;
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}