#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while(T--){
        long long N, M;
        cin >> N >> M;

        if(M >= 1 && M < N){
            cout << M << " " << M + 1 << "\n";
            continue;
        }

        if(M >= 2 && M <= N){
            cout << M - 1 << " " << M << "\n";
            continue;
        }

        bool found = false;
        for(int k = 2; k <= 62; k++){
            long long pk = 1LL << k;     
            long long a = pk - 1;         
            long long b = pk - 2;        

            if(a > M - 1) break;        

            long long d_max = (M - 1) / a;
            long long d_min = 1;
            if(M > N){
                d_min = max(1LL, (M - N + b - 1) / b); 
            }

            if(d_min > d_max) continue;

            long long d = d_min;
            long long x = M - d * a;
            long long y = M - d * b;

            if(x >= 1 && y <= N && x < y){
                cout << x << " " << y << "\n";
                found = true;
                break;
            }
        }

        if(!found){
            cout << -1 << "\n";
        }
    }

    return 0;
}