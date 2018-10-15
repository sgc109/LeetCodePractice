#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf = 0x3c3c3c3c;
const ll infl = 0x3c3c3c3c3c3c3c3c;

struct Node{
    int i, j;
};
int distX[2003][2003], distY[2003][2003];
int N, M, R, C, X, Y;
string pane[2003];
bool in_range(int i, int j){
    return 0 <= i && i < N && 0 <= j && j < M;
}
int main(){
    memset(distX,-1,sizeof(distX));
    memset(distY,-1,sizeof(distY));
    cin >> N >> M >> R >> C >> X >> Y;
    for(int i = 0; i < N; i++) {
        cin >> pane[i];
    }
    deque<Node> dq;
    dq.push_back({R - 1, C - 1});
    distX[R - 1][C - 1] = 0;
    distY[R - 1][C - 1] = 0;
    int ans = 0;
    while(!dq.empty()){
        auto cur = dq.front();
        dq.pop_front();
        ans++;
        for(int k = 0; k < 4; k++){
            int ni = cur.i + "2110"[k] - '1';
            int nj = cur.j + "1201"[k] - '1';
            if(!in_range(ni, nj) || distX[ni][nj] != -1 || pane[ni][nj] == '*') continue;
            int tx = distX[cur.i][cur.j] + (k == 2);
            int ty = distY[cur.i][cur.j] + (k == 1);
            if(tx > X || ty > Y) continue;
            distX[ni][nj] = tx;
            distY[ni][nj] = ty;
            if(k == 1 || k == 2) dq.push_back({ni, nj});
            else dq.push_front({ni, nj});
        }
    }
    cout << ans;
    return 0;
}
