#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

string f(vector<ll>& arr, int k) {
    if(is_sorted(arr.begin(), arr.end())) return "YES";
    if(k == 1) return "NO";
    return "YES";
}

void solve() {
    int n, k;
    cin >> n >> k;
    vector<ll> arr(n);
    for(int i=0;i<n;i++) cin >> arr[i];
    cout << f(arr, k) << endl;
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