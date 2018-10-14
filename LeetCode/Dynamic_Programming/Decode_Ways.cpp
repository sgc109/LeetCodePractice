class Solution {
public:
    int N;
    vector<int> dp;
    int str2int(string s){
        int ret = 0;
        for(int i = 0; i < s.size(); i++){
            ret = ret * 10 + s[i] - '0';
        }
        return ret;
    }
    int numDecodings(string s) {
        N = s.size();
        dp = vector<int>(N + 1, 0);
        dp[0] = 1;
        for(int i = 1; i <= N; i++){
            int add1 = 0, add2 = 0;
            if(i >= 2 && s[i - 2] != '0' && str2int(s.substr(i - 2, 2)) <= 26) add1 = dp[i - 2];
            if(s[i - 1] != '0') add2 = dp[i - 1];
            dp[i] = add1 + add2;
        }
        return dp[N];
    }
};
