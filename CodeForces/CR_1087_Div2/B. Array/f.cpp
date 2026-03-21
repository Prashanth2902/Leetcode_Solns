#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    for (int i = 0; i < n; i++) {
        int greater = 0;
        int smaller = 0;
        for (int j = i + 1; j < n; j++) {
            if (a[j] > a[i]) greater++;
            else if (a[j] < a[i]) smaller++;
        }
        cout << max(greater, smaller) << (i == n - 1 ? "" : " ");
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}