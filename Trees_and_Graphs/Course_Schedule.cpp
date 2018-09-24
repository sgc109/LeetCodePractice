// 7m O(N + M)
// 1 try

class Solution {
public:
    int N;
    vector<int> in;
    vector<vector<int>> G;
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        N = numCourses;
        in = vector<int>(N, 0);
        G = vector<vector<int>>(N);
        for(auto p : prerequisites) {
            int a = p.first, b = p.second;
            G[a].push_back(b);
            in[b]++;
        }
        queue<int> q;
        for(int i = 0; i < N; i++) if(!in[i]) q.push(i);
        int cnt = 0;
        while(!q.empty()){
            cnt++;
            int cur = q.front();
            q.pop();
            for(int nxt : G[cur]){
                in[nxt]--;
                if(!in[nxt]) q.push(nxt);
            }
        }
        return cnt == N;
    }
};
