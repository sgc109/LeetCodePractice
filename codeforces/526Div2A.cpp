#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int N;
int A[103];
int go(int x){
    int ret = 0;
    for(int i = 0; i < N; i++) {
        if(x <= i) ret += 4 * i * A[i];
        else ret += 4 * x * A[i];
    }
    return ret;
}
int main(){
    cin >> N;
    for(int i = 0; i < N; i++) cin >> A[i];
    int ans = 0x3c3c3c3c;
    for(int i = 0; i < N; i++) ans = min(ans, go(i));
    cout << ans;
    return 0;
}
