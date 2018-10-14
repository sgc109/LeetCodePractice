// 3m(or so) O(n^2)
// 28m 29s O(nlgn)

class Solution {
public:
    int N;
    int size;
    vector<int> tree;
    vector<int> sorted;
    
    void update(int pos, int val){
        pos += size;
        tree[pos] = min(tree[pos], val);
        for(int i = pos; i >= 1; i /= 2) {
            tree[i / 2] = min(tree[i], tree[i ^ 1]);
        }
    }
    int query(int l, int r) {
        int ret = N + 1;
        for(l += size, r += size; l <= r; l /= 2, r /= 2){
            if(l & 1) ret = min(ret, tree[l++]);
            if(~r & 1) ret = min(ret, tree[r--]);
        }        
        return ret;
    }
    int maxArea(vector<int>& height) {
        int ans = 0;
        N = height.size();
        for(int i = 0; i < N; i++) sorted.push_back(height[i]);
        sort(sorted.begin(), sorted.end());
        for(int i = 0; i < N; i++) {
            height[i] = lower_bound(sorted.begin(), sorted.end(), height[i]) - sorted.begin();
        }
        size = 1;
        while(size < N) size *= 2;
            
        for(int k = 0; k < 2; k++){
            tree = vector<int>(size * 2, N + 1);
            
            for(int i = 0; i < N; i++){
                int ml = query(height[i], N - 1);
                if(ml < i) {
                    ans = max(ans, (i - ml) * sorted[height[i]]);
                }
                update(height[i], i);
            }
            
            reverse(height.begin(), height.end());
        }
        return ans;
    }
};
