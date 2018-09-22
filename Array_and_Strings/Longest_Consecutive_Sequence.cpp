// 54m 56s

class Solution {
public:
    unordered_map<int,pair<int,int>> mp;
    int longestConsecutive(vector<int>& nums) {
        int ans = 0;
        
        int N = nums.size();
        for(int i = 0; i < N; i++){
            int a = nums[i];
            if(mp.count(a)) continue;
            int bl = (mp.count(a - 1));
            int br = (mp.count(a + 1));
            
            int len = 0;
            if(bl && br) {
                int tmpl = mp[a - 1].second;
                int tmpr = mp[a + 1].second;
                
                len = mp[a - 1].first + mp[a + 1].first + 1;
                mp[tmpl] = {len, tmpr};
                mp[tmpr] = {len, tmpl};
                mp[a] = {len, -1};
            } else if(bl) {
                int tmpl = mp[a - 1].second;
                
                len = mp[a - 1].first + 1;
                mp[tmpl] = {len, a};
                mp[a] = {len, tmpl};
            } else if(br) {
                int tmpr = mp[a + 1].second;
                
                len = mp[a + 1].first + 1;
                mp[tmpr] = {len, a};
                mp[a] = {len, tmpr};
            } else {
                len = 1;
                mp[a] = {len, a};
            }
            ans = max(ans, len);
        }
        return ans;
    }
};
