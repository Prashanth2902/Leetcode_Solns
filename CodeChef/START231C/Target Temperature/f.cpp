#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

string f(vector<ll>& arr) {
    int max_val = *max_element(arr.begin(), arr.end());
    map<int, int> counts;
    for (int x : arr) {
        counts[x]++;
    }

    bool possible = true;
    for (auto const& [val, freq] : counts) {
        if (val < max_val && freq > 1) {
            possible = false;
            break;
        }
    }

    if (possible) return "YES";
    else return "NO";
}

void solve() {
    ll n;
    cin >> n;
    vector<ll> arr(n);
    for(int i=0;i<n;i++) cin >> arr[i];
    cout << f(arr) << endl;
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