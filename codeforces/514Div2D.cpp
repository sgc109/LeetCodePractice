#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf = 0x3c3c3c3c;
const ll infl = 0x3c3c3c3c3c3c3c3c;

int N;
ll X[100003], Y[100003];
ll mn_x = infl, mx_x = -infl;
bool possi(double r){
    double lo = -infl, hi = infl;
    for(int i = 0; i < N; i++){
        if(pow(r, 2) < pow(r - Y[i], 2)) return false;
        double sq = sqrt(pow(r, 2) - pow(r - Y[i], 2));
        double nlo = X[i] - sq, nhi = X[i] + sq;
        lo = max(lo, nlo);
        hi = min(hi, nhi);
    }
    return !(lo > hi);
}
int main(){
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> X[i] >> Y[i];
    }
    for(int i = 0; i < N; i++){
        if(Y[0] * Y[i] < 0) return !printf("-1");
    }
    if(Y[0] < 0) {
        for(int i = 0; i < N; i++) Y[i] *= -1;
    }

    double lo = 0, hi = 2.5 * 1e14;
    for(int i = 0; i < 300; i++){
        double mid = (lo + hi) / 2;
        if(possi(mid)) hi = mid;
        else lo = mid;
    }
    cout.precision(10);
    cout << fixed << lo;
    return 0;
}
