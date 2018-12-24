#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int N;
ll S;
ll V[1003];
int go(ll limit){
    ll acc = 0;
    for(int i = 0; i < N; i++) {
        acc += V[i] - limit;
    }
    return acc >= S;
}
int main(){
    cin >> N >> S;
    ll mn = 1e9 + 1;
    for(int i = 0; i < N; i++) {
        cin >> V[i];
        mn = min(mn, V[i]);
    }
    ll lo = 0, hi = mn + 1;
    while(lo < hi) {
        ll mid = (lo + hi) / 2;
        if(go(mid)) lo = mid + 1;
        else hi = mid;
    }
    cout << lo - 1;
    return 0;
}
