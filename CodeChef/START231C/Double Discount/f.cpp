#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int N, K;
    if (!(cin >> N >> K)) return;

    vector<int> A(N), B(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    for (int i = 0; i < N; i++) cin >> B[i];

    int max_total_tastiness = 0;

    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            int a_max = max(A[i], A[j]);
            int a_min = min(A[i], A[j]);

            int discount = min(a_max / 2, 100);
            int current_cost = a_min + (a_max - discount);

            if (current_cost <= K) {
                max_total_tastiness = max(max_total_tastiness, B[i] + B[j]);
            }
        }
    }

    cout << max_total_tastiness << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}