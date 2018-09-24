// 11m 2s O(NlgN)
// 1 try (2 compile error)

class Solution {
public:
    int N;
    int size;
    vector<int> tree;
    void update(int pos, int val){
        tree[pos += size] += val;
        for(int i = pos; i > 1; i /= 2){
            tree[i / 2] = tree[i] + tree[i ^ 1];
        }
    }
    int query(int l, int r){
        if(l > r) return 0;
        int ret = 0;
        for(l += size, r += size; l <= r; l /= 2, r /= 2){
            if(l & 1) ret += tree[l++];
            if(~r & 1) ret += tree[r--];
        }
        return ret;
    }
    vector<int> countSmaller(vector<int>& nums) {
        if(nums.size() == 0) return nums;
        N = nums.size();
        size = 1;
        while(size < N) size *= 2;
        tree = vector<int>(size * 2, 0);
        vector<int> sorted;
        for(int num : nums) sorted.push_back(num);
        sort(sorted.begin(), sorted.end());
        for(int i = 0; i < N; i++){
            nums[i] = lower_bound(sorted.begin(), sorted.end(), nums[i]) - sorted.begin();
        }
        vector<int> ret(N);
        for(int i = N - 1; i >= 0; i--){
            ret[i] = query(0, nums[i] - 1);
            update(nums[i], 1);
        }        
        return ret;
    }
};
