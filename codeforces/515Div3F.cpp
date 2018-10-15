#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf = 0x3c3c3c3c;
const ll infl = 0x3c3c3c3c3c3c3c3c;

struct point{
    int x, y;
};
point pos[200003][2];
map<int, vector<point>> mp;
ll dp[200003][2];
int N;
point ps[200003];
point find_left(vector<point>& v){
    point ret = point{inf, -1};
    for(auto p : v){
        if(p.x < ret.x) ret = p;
        else if(p.x == ret.x && ret.y < p.y) ret = p;
    }
    return ret;
}

point find_right(vector<point>& v){
    point ret = point{-1, inf};
    for(auto p : v){
        if(ret.x < p.x) ret = p;
        else if(ret.x == p.x && p.y < ret.y) ret = p;
    }
    return ret;
}

ll dist(point& a, point& b){
    return abs(a.x - b.x) + abs(a.y - b.y);
}
int main(){
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> ps[i].x >> ps[i].y;
        int level = max(ps[i].x, ps[i].y);
        mp[level].push_back(ps[i]);
    }
    int i = 1;
    pos[0][0] = pos[0][1] = point{0, 0};
    for(auto p : mp){
        vector<point> v = p.second;
        pos[i][0] = find_left(v);
        pos[i][1] = find_right(v);
        ll d = dist(pos[i][0], pos[i][1]);

        dp[i][1] = min(dp[i - 1][0] + dist(pos[i - 1][0], pos[i][0]),
                dp[i - 1][1] + dist(pos[i - 1][1], pos[i][0])) + d;

        dp[i][0] = min(dp[i - 1][0] + dist(pos[i - 1][0], pos[i][1]),
                dp[i - 1][1] + dist(pos[i - 1][1], pos[i][1])) + d;

        i++;
    }
    cout << min(dp[i - 1][0], dp[i - 1][1]);
    return 0;
}
