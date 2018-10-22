#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf = 0x3c3c3c3c;
const ll infl = 0x3c3c3c3c3c3c3c3c;

int T, N;
int A[7003];
map<int, int> mp;
int main(){
    cin >> T;
    for(int t = 1; t <= T; t++) {

        ll ans = 0;

        cin >> N;
        for(int i = 0; i < N; i++) cin >> A[i];

        sort(A, A + N);

        int st = N;
        while(0 < st && 0 < A[st - 1]) {
            st--;
        }

        for(int i = st; i < N; i++) {
            mp.clear();
            for(int j = st; j < i; j++) {
                if(A[i] % A[j]) continue;
                ans += mp[A[i] / A[j]];
                mp[A[j]]++;
            }
        }
        if(st >= 3) {
            ans += (ll)st * (st - 1) * (st - 2) / 6;
        }
        if(st >= 2 && N > st) {
            ans += (ll)st * (st - 1) / 2 * (N - st);
        }
        cout << "Case #" << t << ": " << ans << '\n';
    }
    return 0;
}
