#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll mod = 1e9 + 7;

ll A, AB, ans;
string S;
int main(){
    cin >> S;
    for(int i = 0; i < S.size(); i++) {
        char c = S[i];
        if(c != 'a' && c != 'b') continue;
        if(c == 'a') {
            ans = (ans + AB + 1) % mod;
            A = (A + AB + 1) % mod;
        } else if(c == 'b') {
            AB = (AB + A) % mod;
            A = 0;
        }
    }
    cout << ans;
    return 0;
}
