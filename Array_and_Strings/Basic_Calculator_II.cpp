// 37m 6s

class Solution {
public:
    string remove_space(string s){
        string ret = "";
        for(int i = 0; i < s.size(); i++) {
            if(s[i] != ' ') ret += s[i];
        }
        return ret;
    }
    int string_to_int(string s){
        int ret = 0;
        for(int i = 0; i < s.size(); i++){
            ret = ret * 10 + s[i] - '0';
        }
        return ret;
    }
    bool is_operator(char c){
        return c == '+' || c == '-' || c == '*' || c == '/';
    }
    vector<int> nums;
    vector<char> opers;
    int calculate(string s) {
        int N = s.size();
        s = remove_space(s);
        string snum = "";
        for(int i = 0; i < s.size(); i++){
            if(is_operator(s[i])) {
                int num = string_to_int(snum);
                nums.push_back(num);
                opers.push_back(s[i]);
                snum = "";
            }
            else {
                snum += s[i];
            }
        }
        
        int num = string_to_int(snum);
        nums.push_back(num);
        
        vector<int> tnums, topers;
        int cnt = opers.size();
        for(int i = 0; i < cnt; i++){
            if(opers[i] == '*' || opers[i] == '/') {
                int nxt;
                if(opers[i] == '/') nxt = nums[i] / nums[i + 1];
                else nxt = nums[i] * nums[i + 1];
                nums[i + 1] = nxt;
            }
            else {
                tnums.push_back(nums[i]);
                topers.push_back(opers[i]);
            }
        }
        tnums.push_back(nums[cnt]);
        
        cnt = topers.size();
        for(int i = 0; i < cnt; i++){
            int nxt;
            if(topers[i] == '+') nxt = tnums[i] + tnums[i + 1];
            else nxt = tnums[i] - tnums[i + 1];
            tnums[i + 1] = nxt;
        }
        return tnums[cnt];
    }
};
