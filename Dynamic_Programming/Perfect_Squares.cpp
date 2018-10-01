// 13m 13s O(n*root(n))
// 1 try

class Solution {
public:
    vector<int> dp;
    int numSquares(int n) {
        dp = vector<int>(n + 1, 0x3c3c3c3c);
        dp[0] = 0;
        for(int i = 1; i <= n; i++){
            int sqt = (int)sqrt(i);
            if(sqt * sqt == i) {
                dp[i] = 1;
                continue;
            }
            for(int j = 1; i >= j * j; j++){
                dp[i] = min(dp[i], dp[i - j * j] + 1);
            }
        }
        return dp[n];
    }
};
