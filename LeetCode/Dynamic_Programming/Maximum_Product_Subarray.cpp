class Solution {
public:
    int inf = 0x3c3c3c3c;
    int getMaxPdt(vector<int>& arr){
        if(arr.size() == 0) return -inf;
        int cnt_minus = 0;
        int prd = 1;
        for(int i = 0; i < arr.size(); i++) {
            if(arr[i] < 0) cnt_minus++;
            prd *= arr[i];
        }
        if(cnt_minus % 2 == 0) return prd;
        int idx_l, idx_r;
        for(int i = 0; i < arr.size(); i++) {
            if(arr[i] < 0) {
                idx_l = i;
                break;
            }
        }
        for(int i = (int)arr.size() - 1; i >= 0; i--){
            if(arr[i] < 0) {
                idx_r = i;
                break;
            }
        }
        int ans = arr[0];
        prd = -inf;
        for(int i = 0; i < idx_r; i++) {
            if(prd == -inf) prd = arr[i];
            else prd *= arr[i];
        }
        ans = max(ans, prd);
        prd = -inf;
        for(int i = idx_l + 1; i < arr.size(); i++) {
            if(prd == -inf) prd = arr[i];
            else prd *= arr[i];
        }
        ans = max(ans, prd);
        
        return ans;
    }
    int maxProduct(vector<int>& nums) {
        if(nums.size() == 1 && nums[0] < 0) return nums[0];
        
        int ans = -inf;
        vector<int> v;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == 0) {
                ans = max(ans, 0);
                ans = max(ans, getMaxPdt(v));
                v.clear();
            }
            else v.push_back(nums[i]);
        }
        ans = max(ans, getMaxPdt(v));
        return ans;
    }
};
