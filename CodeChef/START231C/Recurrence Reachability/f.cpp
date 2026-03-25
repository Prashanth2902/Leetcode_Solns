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

        // Case k=0: f(0)=x=M, need y in (M, N]
        if(M >= 1 && M < N){
            cout << M << " " << M + 1 << "\n";
            continue;
        }

        // Case k=1: f(1)=y=M, need x in [1, M), y<=N
        if(M >= 2 && M <= N){
            cout << M - 1 << " " << M << "\n";
            continue;
        }

        // Case k>=2: x = M - d*(2^k - 1), y = M - d*(2^k - 2)
        // Need: x >= 1, y <= N, d >= 1
        // d <= (M-1)/(2^k - 1)       [from x >= 1]
        // d >= (M - N)/(2^k - 2)     [from y <= N]
        bool found = false;
        for(int k = 2; k <= 62; k++){
            long long pk = 1LL << k;      // 2^k
            long long a = pk - 1;          // 2^k - 1
            long long b = pk - 2;          // 2^k - 2

            if(a > M - 1) break;          // no valid d >= 1

            long long d_max = (M - 1) / a;
            long long d_min = 1;
            if(M > N){
                // y = M - d*b <= N  =>  d >= (M-N)/b
                d_min = max(1LL, (M - N + b - 1) / b); // ceil division
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