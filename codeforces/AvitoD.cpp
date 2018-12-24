#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf = 0x3c3c3c3c;
const ll infl = 0x3c3c3c3c3c3c3c3c;

struct Edge{
    int u, v, w;
    bool operator<(const Edge &rhs) const {
        return w < rhs.w;
    }
};
int N, M, K;
vector<int> G[100003];
int par[100003];
int siz[100003];
int find(int u){
    if(par[u] == u) return u;
    return par[u] = find(par[u]);
}
int merge(int u, int v){
    u = find(u), v = find(v);
    siz[u] += siz[v];
    par[v] = u;
    return siz[u];
}
vector<Edge> edges;

int main(){
    cin >> N >> M >> K;
    for(int i = 1; i <= N; i++) par[i] = i;

    for(int i = 0; i < K; i++) {
        int a;
        cin >> a;
        siz[a] = 1;
    }
    for(int i = 0; i < M; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back(Edge{u, v, w});
    }
    sort(edges.begin(), edges.end());
    int ans = 0;
    for(auto e : edges){
        int u = find(e.u), v = find(e.v);
        if(u == v) continue;
        int sz = merge(u, v);
        if(sz == K) {
            ans = e.w;
            break;
        }
    }
    for(int i = 0; i < K; i++) cout << ans << ' ';
    return 0;
}
