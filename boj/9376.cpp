#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf = 0x3c3c3c3c;
const ll infl = 0x3c3c3c3c3c3c3c3c;

struct Node{
    int i, j;
    bool operator==(Node& rhs) const{
        return i == rhs.i && j == rhs.j;
    }
};
int T;
int N, M;
int dist[3][103][103];
vector<Node> st;
string pane[103];

bool in_range(int i, int j){
    return 0 <= i && i < N && 0 <= j && j < M;
}

bool in_edge(int i, int j){
    return i == 0 || j == 0 || i == N - 1 || j == M - 1;
}
int bfs(deque<Node>& dq, int id){
    int ret = 0;
    while(!dq.empty()){
        auto p = dq.front();
        dq.pop_front();
        if(id == 2 && (p == st[0] || p == st[1])) {
            ret += dist[id][p.i][p.j];
        }
        for(int k = 0; k < 4; k++){
            int ni = p.i + "2110"[k] - '1';
            int nj = p.j + "1201"[k] - '1';
            if(!in_range(ni, nj) || pane[ni][nj] == '*' || dist[id][ni][nj] != -1) continue;
            int cost = pane[ni][nj] == '#';
            dist[id][ni][nj] = dist[id][p.i][p.j] + cost;
            if(!cost) dq.push_front(Node{ni, nj});
            else dq.push_back(Node{ni, nj});
        }
    }
    return ret;
}
int main(){
    cin >> T;
    while(T--){
        memset(dist,-1,sizeof(dist));
        st.clear();
        cin >> N >> M;
        int cnt = 0;
        for(int i = 0; i < N; i++) {
            cin >> pane[i];
            for(int j = 0; j < M; j++){
                if(pane[i][j] == '$'){
                    st.push_back(Node{i, j});
                    dist[cnt++][i][j] = 0;
                }
            }
        }
        deque<Node> dq;
        for(int i = 0; i < N; i++){
            for(int j = 0; j < M; j++){
                if(!in_edge(i, j) || pane[i][j] == '*') continue;
                int d = pane[i][j] == '#';
                dist[2][i][j] = d;
                if(!d) dq.push_front(Node{i, j});
                else dq.push_back(Node{i, j});
            }
        }
        int ans = bfs(dq, 2);
        dq.push_back(st[0]);
        bfs(dq, 0);
        dq.push_back(st[1]);
        bfs(dq, 1);

        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                if(dist[0][i][j] == -1 || dist[1][i][j] == -1 || dist[2][i][j] == -1) continue;
                int upd = dist[0][i][j] + dist[1][i][j] + dist[2][i][j] - (pane[i][j] == '#') * 2;
                ans = min(ans, upd);
            }
        }
        cout << ans << endl;
    }
    return 0;
}
