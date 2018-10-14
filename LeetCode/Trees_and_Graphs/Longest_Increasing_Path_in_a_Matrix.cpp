// 7m 53s O(NMlgNM)
// 1 try

class Solution {
public:
    vector<pair<int,pair<int,int>>> sorted;
    int N, M;
    vector<vector<int>> dp;
    
    bool in_range(int i, int j){
        return 0 <= i && i < N && 0 <= j && j < M;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
       if(matrix.size() == 0) return 0;
        N = matrix.size();
        M = matrix[0].size();
        dp = vector<vector<int>>(N, vector<int>(M, 0));
        for(int i = 0; i < N; i++){
            for(int j = 0; j < M; j++){
                sorted.push_back({matrix[i][j], {i, j}});
            }
        }
        sort(sorted.begin(), sorted.end());
        
        int ans = 1;
        for(auto p : sorted){
            int ci = p.second.first;
            int cj = p.second.second;
            dp[ci][cj] = 1;
            for(int k = 0; k < 4; k++){
                int ni = ci + "2110"[k] - '1';
                int nj = cj + "1201"[k] - '1';
                if(!in_range(ni, nj)) continue;
                if(matrix[ni][nj] < matrix[ci][cj]) {
                    dp[ci][cj] = max(dp[ci][cj], dp[ni][nj] + 1);
                    ans = max(ans, dp[ci][cj]);
                }
            }
        }
        
        return ans;
    }
};
