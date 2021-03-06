// 3m 15s

class Solution {
public:
    map<int,int> mp;
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        for(int i = 0; i < A.size(); i++){
            for(int j = 0; j < B.size(); j++){
                mp[A[i] + B[j]]++;
            }
        }
        int ans = 0;
        for(int i = 0; i < C.size(); i++){
            for(int j = 0; j < D.size(); j++){
                ans += mp[-(C[i] + D[j])];
            }
        }
        return ans;
    }
};


