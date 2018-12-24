#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf = 0x3c3c3c3c;
const ll infl = 0x3c3c3c3c3c3c3c3c;

int T, N;
string S;
int main(){
    cin >> T;
    for(int t = 1; t <= T; t++) {
        cin >> N >> S;
        int len = ((int)N + 1) / 2;
        ll sum = 0;
        for(int i = 0; i < len; i++) sum += S[i] - '0';
        ll ans = 0;
        for(int i = len; i <= N; i++) {
            ans = max(ans, sum);
            if(i == N) break;
            sum -= S[i - len] - '0';
            sum += S[i] - '0';
        }
        cout << "Case #" << t << ": ";
        cout << ans << '\n';
    }
    return 0;
}
