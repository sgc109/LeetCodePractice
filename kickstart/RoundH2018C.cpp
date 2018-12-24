#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf = 0x3c3c3c3c;
const ll infl = 0x3c3c3c3c3c3c3c3c;
const ll mod = 1e9 + 7;

int T, N, M;
ll dp[103][203][2];
ll go(int i, int j, int k) {
    ll& cache = dp[i][j][k];
    if(cache != -1) return cache;
    if(i < 0 || j < 0) return 0;
    if(!i && !j) return 1;
    return cache = (go(i - 1, j + 1, 1) * i * 2 + go(i, j - 1, 0) * (j - k)) % mod;
}
int main(){
    cin >> T;
    for(int t = 1; t <= T; t++) {
        memset(dp,-1,sizeof(dp));
        cin >> N >> M;
        cout << "Case #" << t << ": ";
        cout << go(M, 2 * N - 2 * M, 0) << '\n';
    }
    return 0;
}
