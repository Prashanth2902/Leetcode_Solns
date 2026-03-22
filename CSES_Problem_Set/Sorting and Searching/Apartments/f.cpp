#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll f(vector<ll>& apps, vector<ll>& apts, ll k) {
    ll res = 0;
    sort(apps.begin(), apps.end());
    sort(apts.begin(), apts.end());
    int l = 0, r = 0;
    while(l < apps.size() && r < apts.size()) {
        if(abs(apps[l] - apts[r]) <= k) {
            res++;
            l++;
            r++;
        } else if(apps[l] - apts[r] > k) {
            r++;
        } else {
            l++;
        }
    }
    return res;
}

void solve() {
    ll n, m, k;
    cin >> n >> m >> k;
    vector<ll> apps(n);
    for(int i=0;i<n;i++) cin >> apps[i];
    vector<ll> apts(m);
    for(int i=0;i<m;i++) cin >> apts[i];
    cout << f(apps, apts, k) << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}