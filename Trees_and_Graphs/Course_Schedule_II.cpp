// 4m 22s O(N + M)
// 1 try

class Solution {
public:
    int N;
    vector<int> in;
    vector<vector<int>> G;
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        N = numCourses;
        G = vector<vector<int>>(N);
        in = vector<int>(N);
        for(auto p : prerequisites) {
            int u = p.first, v = p.second;
            G[v].push_back(u);
            in[u]++;
        }
        vector<int> ans;
        queue<int> q;
        for(int i = 0; i < N; i++) if(!in[i]) q.push(i);
        while(!q.empty()){
            int cur = q.front();
            q.pop();
            
            ans.push_back(cur);
            for(int nxt : G[cur]) {
                in[nxt]--;
                if(!in[nxt]) q.push(nxt);
            }
        }
        if(ans.size() < N) ans.clear();
        return ans;
    }
};
