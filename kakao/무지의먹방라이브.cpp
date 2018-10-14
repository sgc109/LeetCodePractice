#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

map<int, int> mp;
vector<int> order;
int N;
int solution(vector<int> foods, long long k) {
    mp.clear();
    order.clear();

    int ans = 0;
    N = foods.size();
    for(int i = 0; i < N; i++) {
        mp[foods[i]]++;
    }
    for(auto p : mp){
        order.push_back(p.first);
    }

    int prv = 0;
    int cur_cnt = N;
    int last = -1;
    for(auto food : order){
        int dif = food - prv;
        assert(dif > 0);
        ll prv_k = k;
        k -= (ll)dif * cur_cnt;
        if(k == 0){
            last = food + 1;
            break;
        }
        else if(k < 0) {
            k = prv_k;
            last = food;
            break;
        }

        cur_cnt -= mp[food];
        prv = food;
    }

    if(last == -1) return -1;

    vector<int> v;
    for(int i = 0; i < foods.size(); i++){
        if(foods[i] >= last) v.push_back(i + 1);
    }

    if(v.size() == 0) return -1;

    int rest = k % v.size();

    return v[rest];
}
