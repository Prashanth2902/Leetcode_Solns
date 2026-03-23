#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

string f(vector<int>& arr) {
    bool c1 = false, c67 = false;
    for(auto n: arr) {
        if(n == 1) c1 = true;
        if(n == 67) c67 = true;
    }
    if(c67) return "YES";
    return "NO";
}

void solve() {
    int n;
    cin >> n;
    vector<int> arr(n);
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