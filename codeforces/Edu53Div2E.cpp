#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf = 0x3c3c3c3c;
const ll infl = 0x3c3c3c3c3c3c3c3c;
const ll mod = 998244353;

ll L, R, K;
ll dp1[18][1 << 10][2];
ll dp2[18][1 << 10][2];
ll X;
int num[20];
ll md[20];
ll go1(int pos, int mask, int shit){
    if(pos == -1) return 1;
    ll& cache = dp1[pos][mask][shit];
    if(cache != -1) return cache;
    ll ret = 0;
    int cnt = 0;
    for(int i = 0; i < 10; i++) cnt += ((mask >> i) & 1);
    for(int i = 0; i < 10; i++) {
        if(!shit && num[pos] < i) continue;
        int add = ((~(mask >> i)) & 1);
        if(cnt + add > K) continue;
        int n_mask = (mask | (1 << i));
        if(mask == 0 && i == 0) n_mask = 0;
        ret = (ret + go1(pos - 1, n_mask, shit || (i < num[pos]))) % mod;
    }
    return cache = ret;
}

ll go2(int pos, int mask, int shit){
    if(pos == -1) return 0;
    ll& cache = dp2[pos][mask][shit];
    if(cache != -1) return cache;
    ll ret = 0;
    int cnt = 0;
    for(int i = 0; i < 10; i++) cnt += ((mask >> i) & 1);
    for(int i = 0; i < 10; i++) {
        if(!shit && num[pos] < i) continue;
        int add = ((~(mask >> i)) & 1);
        if(cnt + add > K) continue;
        int n_mask = (mask | (1 << i));
        if(mask == 0 && i == 0) n_mask = 0;
        int n_shit = (shit || (i < num[pos]));
        ll tmp = (md[pos] * i) % mod * go1(pos - 1, n_mask, n_shit) % mod;
        
        ret = ((ret + tmp) % mod + go2(pos - 1, n_mask, n_shit)) % mod;
    }
    return cache = ret;
}

void init(ll x){
    memset(dp1,-1,sizeof(dp1));
    memset(dp2,-1,sizeof(dp2));
    memset(num,0,sizeof(num));
    X = x;
    int idx = 0;
    while(x){
        num[idx] = x % 10;
        x /= 10;
        idx++;
    }
}

int main(){
    cin >> L >> R >> K;
    md[0] = 1;
    for(int i = 1; i < 20; i++) {
        md[i] = (md[i - 1] * 10) % mod;
    }
    init(L - 1);
    go1(17, 0, 0);
    ll lo = go2(17, 0, 0);

    init(R);
    go1(17, 0, 0);
    ll hi = go2(17, 0, 0);

    cout << (hi - lo + mod) % mod << endl;
    return 0;
}
