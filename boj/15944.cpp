#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf = 0x3c3c3c3c;
const ll infl = 0x3c3c3c3c3c3c3c3c;

struct Node{
    int i, j, d;
};
int N, M, D;
string pane[503];
int dist[503][503];
bool in_range(int i, int j){
    return 0 <= i && i < N && 0 <= j && j < M;
}

bool is_cand(int i, int j, int d){
    return in_range(i, j) && dist[i][j] > d;
}

void push(int i, int j, int d, int back, deque<Node>& dq){
    if(!is_cand(i, j, d)) return;
    if(!back && pane[i][j] == '#') return;
    dist[i][j] = d;
    if(back) dq.push_back({i, j, d});
    else dq.push_front({i, j, d});
}

int main(){
    memset(dist,0x3c,sizeof(dist));
    cin >> N >> M >> D;
    for(int i = 0; i < N; i++) cin >> pane[i];

    deque<Node> dq;
    dist[0][0] = 0;
    dq.push_back({0, 0, 0});
    while(!dq.empty()){
        auto cur = dq.front();
        dq.pop_front();
        int ci = cur.i, cj = cur.j;
        if(dist[ci][cj] < cur.d) continue;
        for(int k = 0; k < 4; k++){
            int ni = ci + "2110"[k] - '1';
            int nj = cj + "1201"[k] - '1';
            push(ni, nj, cur.d, 0, dq);
        }
        for(int j = cj - D + 1; j <= cj + D - 1; j++) {
            push(ci - D, j, cur.d + 1, 1, dq);
            push(ci + D, j, cur.d + 1, 1, dq);
        }
        for(int i = ci - D + 1; i <= ci + D - 1; i++) {
            push(i, cj - D, cur.d + 1, 1, dq);
            push(i, cj + D, cur.d + 1, 1, dq);
        }
        if(N - D <= ci && M - D <= cj) {
            push(N - 1, M - 1, cur.d + 1, 1, dq);
        }
    }

    cout << dist[N - 1][M - 1];

    return 0;
}
