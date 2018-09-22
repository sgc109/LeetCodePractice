// 4m 45s

class Solution {
public:
    vector<int> chk;
    int firstMissingPositive(vector<int>& nums) {
        int N = nums.size();
        chk = vector<int>(N + 1, 0);
        for(int i = 0; i < N; i++){
            if(1 <= nums[i] && nums[i] <= N) chk[nums[i]] = 1;
        }
        for(int i = 1; i <= N; i++) {
            if(chk[i] == 0) return i;
        }
        return N + 1;
    }
};
