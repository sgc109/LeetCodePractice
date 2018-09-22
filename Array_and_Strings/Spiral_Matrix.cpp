class Solution {
public:
    vector<vector<int>> chk;
    int N, M;
    vector<int> ans;
    bool in_range(int i, int j){
        return 0 <= i && i < N && 0 <= j && j < M;
    }
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        N = matrix.size();
        if(N == 0) return ans;
        
        M = matrix[0].size();
        chk = vector<vector<int>>(N, vector<int>(M, 0));
        
        int dir = 0;
        int ci = 0, cj = 0;
        while(1){
            if(!in_range(ci, cj) || chk[ci][cj]) break;
            chk[ci][cj] = 1;
            ans.push_back(matrix[ci][cj]);
            int ni = ci + "1210"[dir] - '1';
            int nj = cj + "2101"[dir] - '1';
            if(!in_range(ni, nj) || chk[ni][nj]) {
                dir = (dir + 1 ) % 4;
                ni = ci + "1210"[dir] - '1';
                nj = cj + "2101"[dir] - '1';
            }
            ci = ni;
            cj = nj;
        }
        
        
        return ans;
    }
};
