#include <string>
#include <vector>
#define MAX_CNT 200
using namespace std;

struct Rect{
    int l, r, u, d;
    Rect(){
        l = 51, r = -1, u = 51, d = -1;
    }
};

int N;
Rect rects[MAX_CNT + 1];
int exist[MAX_CNT + 1];

void init(vector<vector<int>>& board){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(!board[i][j]) continue;
            int id = board[i][j];
            exist[id] = 1;
            rects[id].l = min(rects[id].l, j);
            rects[id].r = max(rects[id].r, j);
            rects[id].u = min(rects[id].u, i);
            rects[id].d = max(rects[id].d, i);
        }
    }
}
void fill(vector<vector<int>>& board){
        for(int j = 0; j < N; j++){
            for(int i = 0; i < N; i++){
                if(board[i][j] > 0) break;
                board[i][j] = -1;
            }
        }
}

void remove(vector<vector<int>>& board){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(board[i][j] == -1) board[i][j] = 0;
        }
    }
}
int solution(vector<vector<int>> board) {
    N = board.size();
    int ans = 0;
    init(board);
    while(1){
        int cnt = 0;
        fill(board);
        for(int k = 1; k <= MAX_CNT; k++){
            if(!exist[k]) continue;
            int ok = 1;
            for(int i = rects[k].u; i <= rects[k].d; i++){
                if(!ok) break;
                for(int j = rects[k].l; j <= rects[k].r; j++){
                    if(board[i][j] != -1 && board[i][j] != k) {
                        ok = 0;
                        break;
                    }
                }
            }
            if(!ok) continue;
            exist[k] = 0;
            cnt++;
            for(int i = rects[k].u; i <= rects[k].d; i++){
                for(int j = rects[k].l; j <= rects[k].r; j++){
                    board[i][j] = 0;
                }
            }
        }
        remove(board);
        if(!cnt) break;
        else ans += cnt;
    }
    return ans;
}
