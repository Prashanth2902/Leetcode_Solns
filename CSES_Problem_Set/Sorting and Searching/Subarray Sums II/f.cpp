#include<bits/stdc++.h>
using namespace std;
typedef long long ll;



ll f(vector<ll>& arr, ll& x) {
    int n = arr.size();
    map<ll, ll> counts;
    counts[0] = 1;
    ll current_sum = 0;
    ll res = 0;
    for(int i = 0; i < n; i++) {
        current_sum += arr[i];
        res += counts[current_sum - x];
        counts[current_sum]++;
    }
    return res;
}

void solve() {
    ll n, x;
    cin >> n >> x;
    vector<ll> arr(n);
    for(int i=0;i<n;i++) cin >> arr[i];
    cout << f(arr, x) << endl;
    
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}