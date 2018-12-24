#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf = 0x3c3c3c3c;
const ll infl = 0x3c3c3c3c3c3c3c3c;

string ans;
string S;
int main(){
    cin >> S;
    int len = S.size();
    int cnt = 0;
    int r = 1;
    int mid = (len - 1) / 2;
    ans += S[mid];
    cnt++;
    while(1){
        if(cnt == len) break;
        ans += S[mid + r];
        cnt++;
        if(cnt == len) break;
        ans += S[mid - r];
        cnt++;
        r++;
    }
    cout << ans;
    return 0;
}
