#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf = 0x3c3c3c3c;
const ll infl = 0x3c3c3c3c3c3c3c3c;

string guess(int x, int y = 1){
    cout << x << ' ' << y << endl;
    string col;
    cin >> col;
    return col;
}
void gotcha(int x1, int y1, int x2, int y2){
    cout << x1 << ' ' << y1 << ' ' << x2 << ' ' << y2 << endl;
}
int main(){
    int N;
    cin >> N;
    string col1 = guess(0);
    int lo = 0, hi = 1e9;
    int cnt = N - 1;
    while(lo + 1 < hi && cnt){
        int mid = (lo + hi) / 2;
        string nxt = guess(mid);
        if(col1 == nxt) lo = mid;
        else hi = mid;

        cnt--;
    }
    gotcha(lo, 0, hi, 2);
    return 0;
}
