#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    ll n, c, k;
    cin >> n >> c >> k;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    sort(a.begin(), a.end());

    for (int i = 0; i < n; i++) {
        if (a[i] <= c) {
            ll max_flips_for_this = c - a[i];
            ll use = min(k, max_flips_for_this);
            
            c += (a[i] + use);
            k -= use;
        } else {
            break;
        }
    }
    cout << c << endl;
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