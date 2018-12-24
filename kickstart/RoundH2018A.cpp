#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf = 0x3c3c3c3c;
const ll infl = 0x3c3c3c3c3c3c3c3c;

int T, N, P;
string S[100];
int chk[100];
int main(){
    cin >> T;
    for(int t = 1; t <= T; t++) {
        memset(chk,0,sizeof(chk));
        cin >> N >> P;
        for(int i = 0; i < P; i++) cin >> S[i];
        for(int i = 0; i < P; i++) {
            for(int j = i + 1; j < P; j++) {
                if(chk[i] || chk[j]) continue;
                string a = S[i], b = S[j];
                int idx1 = i, idx2 = j;
                if(a.size() > b.size()) {
                    swap(a, b);
                    swap(idx1, idx2);
                }

                if(b.substr(0, a.size()) == a) chk[idx2] = 1;
            }
        }
        ll ans = 1ll << N;
        for(int i = 0; i < P; i++) {
            if(chk[i]) continue;
            int len = N - (int)S[i].size();
            ans -= (1ll << len);
            assert(ans >= 0);
        }
        cout << "Case #" << t << ": ";
        cout << ans << '\n';
    }
    return 0;
}
