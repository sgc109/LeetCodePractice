#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf = 0x3c3c3c3c;
const ll infl = 0x3c3c3c3c3c3c3c3c;

#include <string>
#include <vector>

using namespace std;
struct node{
    int x, y, id;
};
vector<node> pre_order(vector<node> nodes){
    if(nodes.size() <= 1) return nodes;
    vector<node> l, r, ret;
    node mid = node{-1, -1, 0};
    for(auto p : nodes){
        if(mid.y < p.y) mid = p;
    }
    assert(mid.y >= 0);
    for(auto p : nodes){
        if(p.x < mid.x) l.push_back(p);
        else if(p.x > mid.x) r.push_back(p);
    }
    ret.push_back(mid);
    l = pre_order(l);
    r = pre_order(r);
    ret.insert(ret.end(), l.begin(), l.end());
    ret.insert(ret.end(), r.begin(), r.end());

    return ret;
}

vector<node> post_order(vector<node> nodes){
    if(nodes.size() <= 1) return nodes;
    vector<node> l, r, ret;
    node mid = node{-1, -1, 0};
    for(auto p : nodes){
        if(mid.y < p.y) mid = p;
    }
    for(auto p : nodes){
        if(p.x < mid.x) l.push_back(p);
        else if(p.x > mid.x) r.push_back(p);
    }
    l = post_order(l);
    r = post_order(r);
    ret.insert(ret.end(), l.begin(), l.end());
    ret.insert(ret.end(), r.begin(), r.end());
    ret.push_back(mid);

    return ret;
}
vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    vector<vector<int>> answer;
    vector<node> nodes;
    for(int i = 0; i < nodeinfo.size(); i++){
        auto p = nodeinfo[i];
        nodes.push_back(node{p[0], p[1], i + 1});
    }
    auto tmp1 = pre_order(nodes);
    auto tmp2 = post_order(nodes);

    vector<int> ans1, ans2;
    for(auto p : tmp1) ans1.push_back(p.id);
    for(auto p : tmp2) ans2.push_back(p.id);

    vector<vector<int>> ret;
    ret.push_back(ans1);
    ret.push_back(ans2);
    return ret;
}
