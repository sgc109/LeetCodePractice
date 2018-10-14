#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf = 0x3c3c3c3c;
const ll infl = 0x3c3c3c3c3c3c3c3c;

int N, K;
int tree[200003];
void update(int pos, int val){
    while(pos <= 200000) {
        tree[pos] += val;
        pos += pos & -pos;
    }
}
int query(int pos){
    int ret = 0;
    while(pos) {
        ret += tree[pos];
        pos -= pos & -pos;
    }
    return ret;
}
int main(){
    cin >> N >> K;
    int mn = inf;
    int mx = -inf;
    for(int i = 0; i < N; i++){
        int h;
        cin >> h;
        mn = min(mn, h);
        mx = max(mx, h);
        update(1, 1);
        update(h + 1, -1);
    }
    int ans = 0;
    int acc = 0;
    for(int i = mn + 1; i <= mx; i++){
        int q = query(i);
        if(acc + q > K) {
            ans++;
            acc = q;
        }
        else {
            acc += q;
        }
    }
    if(acc) ans++;
    cout << ans;
    return 0;
}
