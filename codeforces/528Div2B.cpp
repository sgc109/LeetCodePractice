#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf = 0x3c3c3c3c;
const ll infl = 0x3c3c3c3c3c3c3c3c;

int N, K;
vector<int> divs;
int main(){
    cin >> N >> K;
    for(int i = 1; i * i <= N; i++) {
        if(N % i == 0) {
            divs.push_back(i);
            if(i * i != N) divs.push_back(N / i);
        }
    }
    sort(divs.begin(), divs.end());
    reverse(divs.begin(), divs.end());
    int find = -1;
    for(int i = 0; i < divs.size(); i++) {
        if(divs[i] < K) {
            find = divs[i];
            break;
        }
    }
    assert(find != -1);
    ll a = N / find;
    ll b = find;
    a *= K;
    cout << a + b;
    return 0;
}
