// 30m 28s O(LN^2)
// many tries..  read the problem wrong..

class Solution {
public:
    map<string,int> mp;
    vector<int> dist;
    vector<vector<int>> G;
    int N;
    bool is_poss(string a, string b){
        int cnt = 0;
        for(int i = 0; i < a.size(); i++) {
            if(a[i] != b[i]) cnt++;
        }
        return cnt == 1;
    }
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        N = wordList.size();
        G = vector<vector<int>>(N + 1);
        dist = vector<int>(N + 1, -1);
        for(int i = 0; i < N; i++) {
            mp[wordList[i]] = i;
        }
        if(mp.count(endWord) == 0) return 0;
        int dst = mp[endWord];
        for(int i = 0; i < N; i++){
            if(is_poss(beginWord, wordList[i])) {
                G[N].push_back(i);
            }
        }
        for(int i = 0; i < N; i++){
            for(int j = i + 1; j < N; j++){
                if(is_poss(wordList[i], wordList[j])) {
                    G[i].push_back(j);
                    G[j].push_back(i);
                }
            }
        }
        queue<int> q;
        q.push(N);
        dist[N] = 0;
        while(!q.empty()){
            int cur = q.front();
            q.pop();
            for(int nxt : G[cur]){
                if(dist[nxt] != -1) continue;
                dist[nxt] = dist[cur] + 1;
                q.push(nxt);
            }
        }
        return dist[dst] + 1;
    }
};
