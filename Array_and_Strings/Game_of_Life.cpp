// 10m 8s

class Solution {
public:
    int N, M;
    bool in_range(int i, int j){
        return 0 <= i && i < N && 0 <= j && j < M;
    }
    void gameOfLife(vector<vector<int>>& board) {
        if(board.size() == 0) return;
        N = board.size();
        M = board[0].size();
        vector<vector<int>> nxt_board = vector<vector<int>>(N, vector<int>(M, -1));
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < M; j++){
                int cnt = 0;
                for(int k = 0; k < 8; k++){
                    int ni = i + "12221000"[k] - '1';
                    int nj = j + "22100012"[k] - '1';
                    if(!in_range(ni, nj)) continue;
                    if(board[ni][nj] == 1) cnt++;
                }
                int nxt = -1;
                if(board[i][j] == 1){
                    if(cnt < 2) nxt = 0;
                    else if(2 <= cnt && cnt <= 3) nxt = 1;
                    else nxt = 0;
                } else {
                    if(cnt == 3) nxt = 1;
                    else nxt = 0;
                }
                nxt_board[i][j] = nxt;
            }
        }
        for(int i = 0; i < N; i++){
            for(int j = 0; j < M; j++){
                board[i][j] = nxt_board[i][j];
            }
        }
    }
};
