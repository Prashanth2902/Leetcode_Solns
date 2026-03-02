#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<ll> calculateRange(vector<ll> arr) {
    vector<ll> res(arr.size()+1);
    for(ll i=0;i<arr.size();i++) {
        res[i+1] = arr[i] + res[i];
    }
    return res;
}

ll getRange(vector<ll>& rangeQuery, ll l, ll r) {
    return rangeQuery[r] - rangeQuery[l-1];
}

int main() {
    ll n, q;
    cin >> n >> q;
    vector<ll> arr(n);
    for(int i=0;i<n;i++) cin >> arr[i];
    vector<ll> rangeQuery = calculateRange(arr);
    for(int i=0;i<q;i++) {
        ll l, r;
        cin >> l >> r;
        cout << getRange(rangeQuery, l, r) << endl;
    }
    return 0; 
}