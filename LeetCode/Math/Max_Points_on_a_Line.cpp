// 36m 10s O(N^3lgN)
// so many tries..
/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
public:
    long long calc(Point p1, Point p2){
        return (long long)p1.x * p2.y - (long long)p1.y * p2.x;
    }
    vector<pair<int,int>> ps;
    map<pair<int,int>, int> mp;
    int maxPoints(vector<Point>& points) {
        ps.clear();
        for(auto p : points) ps.push_back({p.x, p.y});
        for(auto p : ps) mp[p]++;
        
        int ans = 0;
        for(auto it : mp) ans = max(ans, it.second);
        ps.clear();
        for(auto it : mp) ps.push_back(it.first);
        for(int i = 0; i < ps.size(); i++) {
            auto p1 = ps[i];
            for(int j = i + 1; j < ps.size(); j++){
                auto p2 = ps[j];
                int cnt = mp[p1] + mp[p2];
                for(int k = 0; k < ps.size(); k++){
                    if(i == k || j == k) continue;
                    auto p3 = ps[k];
                    long long tmp = calc(Point(p1.first - p2.first, p1.second - p2.second), Point(p1.first - p3.first, p1.second - p3.second));
                    if(!tmp) cnt += mp[p3];
                }
                ans = max(ans, cnt);
            }
        }
        return ans;
    }
};
