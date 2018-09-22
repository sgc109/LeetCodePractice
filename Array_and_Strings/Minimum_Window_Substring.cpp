// 25m 28s
// 4 try

class Solution {
public:
    int cnt_alpha[330];
    int chk_cnt_alpha[330];
    int cnt;
    int chk_cnt;
    void inc(char c){
        int idx = c;
        if(chk_cnt_alpha[idx] == 0) return;
        cnt_alpha[idx]++;
        if(cnt_alpha[idx] == chk_cnt_alpha[idx]) cnt++;
    }
    void dec(char c){
        int idx = c;
        if(chk_cnt_alpha[idx] == 0) return;
        if(cnt_alpha[idx] == chk_cnt_alpha[idx]) cnt--;
        cnt_alpha[idx]--;
    }
    string minWindow(string s, string t) {
        memset(cnt_alpha,0,sizeof(cnt_alpha));
        memset(chk_cnt_alpha,0,sizeof(chk_cnt_alpha));
        cnt = 0;
        chk_cnt = 0;
        
        for(int i = 0; i < t.size(); i++) {
            chk_cnt_alpha[t[i]]++;
        }
        for(int i = 0; i < 330; i++) {
            if(chk_cnt_alpha[i]) chk_cnt++;
        }
        int ans_l, ans_r;
        int ans_len = s.size() + 1;
        int l = 0, r = 0;
        inc(s[0]);
        while(l < s.size() && r < s.size()) {
            while (l <= r && cnt == chk_cnt) {
                if(ans_len > r - l + 1) {
                    ans_len = r - l + 1;
                    ans_l = l;
                    ans_r = r;
                }
                dec(s[l++]);
            }
            if(l == s.size()) break;
            
            while(r < s.size() - 1 && cnt < chk_cnt) {
                inc(s[++r]);
            }
            if(cnt == chk_cnt) {
                if(ans_len > r - l + 1) {
                    ans_len = r - l + 1;
                    ans_l = l;
                    ans_r = r;
                }
            } else break;
        }
        
        if(ans_len == s.size() + 1) return "";
        return s.substr(ans_l, ans_r - ans_l + 1);
    }
};
