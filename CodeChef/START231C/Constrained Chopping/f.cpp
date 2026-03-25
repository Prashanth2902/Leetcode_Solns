#include <bits/stdc++.h>
using namespace std;

int main(){
    int T;
    scanf("%d", &T);
    while (T--) {
        int n;
        scanf("%d", &n);
        vector<int> A(n);
        for (int i = 0; i < n; i++) scanf("%d", &A[i]);
        
        if (n <= 2) {
            printf("%d\n", *max_element(A.begin(), A.end()));
            continue;
        }
        
        vector<int> vals(A.begin(), A.end());
        sort(vals.begin(), vals.end());
        vals.erase(unique(vals.begin(), vals.end()), vals.end());
        
        int lo = 0, hi = (int)vals.size() - 1, ans = 0;
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            int v = vals[mid];
            
            vector<int> f(n, 0);
            f[0] = (A[0] >= v);
            if (n > 1) f[1] = (A[0] >= v || A[1] >= v);
            
            for (int i = 2; i < n; i++) {
                if (A[i] >= v && i >= 2 && f[i-2])
                    f[i] = 1;
                if (i >= 1 && (A[i-1] >= v || A[i] >= v)) {
                    if (i == 1) f[i] = 1;
                    else if (i >= 3 && f[i-3]) f[i] = 1;
                }
            }
            
            if (f[n-1]) {
                ans = v;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        
        printf("%d\n", ans);
    }
    return 0;
}