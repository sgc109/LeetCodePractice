class Solution {
public:
    vector<int> left, right;
    vector<int> productExceptSelf(vector<int>& nums) {
        int N = nums.size();
        left.resize(N);
        right.resize(N);
        left[0] = nums[0];
        right[N - 1] = nums[N - 1];
        for(int i = 1; i < N; i++) left[i] = left[i - 1] * nums[i];
        for(int i = N - 2; i >= 0; i--) right[i] = right[i + 1] * nums[i];
        vector<int> ans(N);
        for(int i = 0; i < N; i++) {
            if(i == 0) ans[i] = right[i + 1];
            else if(i == N - 1) ans[i] = left[i - 1];
            else ans[i] = left[i - 1] * right[i + 1];
        }
        return ans;
    }
};
