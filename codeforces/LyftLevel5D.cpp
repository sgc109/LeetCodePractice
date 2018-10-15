#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf = 0x3c3c3c3c;
const ll infl = 0x3c3c3c3c3c3c3c3c;

ll root2(ll x){
    ll lo = 1, hi = 15 * 1e8;
    while(lo < hi){
        ll mid = (lo + hi) / 2;
        if(mid * mid == x) return mid;
        else if(mid * mid < x) lo = mid + 1;
        else hi = mid - 1;
    }
    if(lo * lo == x) return lo;
    return -1;
}

ll root3(ll x){
    ll lo = 1, hi = 14 * 1e5;
    while(lo < hi){
        ll mid = (lo + hi) / 2;
        if(mid * mid * mid == x) return mid;
        else if(mid * mid * mid < x) lo = mid + 1;
        else hi = mid - 1;
    }
    if(lo * lo * lo == x) return lo;
    return -1;
}

ll root4(ll x){
    ll sq = root2(x);
    if(sq == -1) return -1;
    return root2(sq);
}

ll gcd(ll a, ll b){
    return !b ? a : gcd(b, a % b);
}

map<ll, int> mp;
int N;
ll A[503];
int chk[503];
void go4(ll sq, int idx){
    if(!chk[idx]) {
        mp[sq] += 4;
        chk[idx] = 1;
    }
}
void go3(ll sq, int idx){
    if(!chk[idx]) {
        ll tmp = A[idx] / (sq * sq * sq);
        if(tmp == 1) mp[sq] += 3;
        else mp[sq] += 4;
        chk[idx] = 1;
    }
}
void go2(ll sq, int idx){
    if(!chk[idx]){
        ll tmp = A[idx] / (sq * sq);
        if(tmp == 1) mp[sq] += 2;
        else if(tmp / sq == 1) mp[sq] += 3;
        else mp[sq] += 4;
        chk[idx] = 1;
    }
}
void go1(ll g, int idx) {
    if(!chk[idx]) {
        int cnt = 0;
        ll tmp = A[idx];
        while(tmp % g == 0){
            tmp /= g;
            cnt++;
        }
        if(tmp > 1) mp[g]++, mp[tmp]++;
        else mp[g] += cnt;
        chk[idx] = 1;
    }
}
int main(){
    cin >> N;
    for(int i = 0; i < N; i++) cin >> A[i];

    ll ans = 1;
    ll mod = 998244353;
    for(int i = 0; i < N; i++){
        for(int j = i + 1; j < N; j++){
            ll g = gcd(A[i], A[j]);
            if(g == 1) continue;
            ll sq2 = root2(g);
            ll sq3 = root3(g);
            ll sq4 = root4(g);
            if(sq4 != -1){
                go4(sq4, i);
                go4(sq4, j);
            } else if(sq3 != -1){
                go3(sq3, i);
                go3(sq3, j);
            } else if(sq2 != -1){
                go2(sq2, i);
                go2(sq2, j);
            } else if(A[i] != A[j]){
                go1(g, i);
                go1(g, j);
            }
        }
    }
    for(auto p : mp){
        ans = (ans * (p.second + 1)) % mod;
    }
    map<ll, int> mp2;
    for(int i = 0; i < N; i++){
        if(chk[i]) continue;
        ll sq2 = root2(A[i]);
        ll sq3 = root3(A[i]);
        ll sq4 = root4(A[i]);
        if(sq4 != -1) ans = (ans * 5) % mod;
        else if(sq3 != -1) ans = (ans * 4) % mod;
        else if(sq2 != -1) ans = (ans * 3) % mod;
        else mp2[A[i]]++;
    }
    for(auto p : mp2){
        ans = (ans * (p.second + 1) * (p.second + 1)) % mod;
    }
    cout << ans;
    return 0;
}
