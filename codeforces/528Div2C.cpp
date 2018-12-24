#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf = 0x3c3c3c3c;
const ll infl = 0x3c3c3c3c3c3c3c3c;

struct Point{
    int x, y;
    bool operator==(const Point& rhs) const {
        return x == rhs.x && y == rhs.y;
    }
    bool operator<(const Point& rhs) const {
        if(x == rhs.x) return y < rhs.y;
        return x < rhs.x;
    }
};
Point ps[3];
vector<int> xs, ys;
set<Point> st;
void push_path(Point src, Point des){
    while(src.x != des.x) {
        st.insert({src.x, src.y});
        if(src.x < des.x) src.x++;
        else src.x--;
    }
    while(src.y != des.y) {
        st.insert({src.x, src.y});
        if(src.y < des.y) src.y++;
        else src.y--;
    }
    st.insert({src.x, src.y});
}
int main(){
    for(int i = 0; i < 3; i++) {
        cin >> ps[i].x >> ps[i].y;
        xs.push_back(ps[i].x);
        ys.push_back(ps[i].y);
    }
    sort(xs.begin(), xs.end());
    sort(ys.begin(), ys.end());
    int xx = xs[1], yy = ys[1];
    Point mid = Point{xx, yy};

    push_path(ps[0], mid);
    push_path(ps[1], mid);
    push_path(ps[2], mid);

    cout << st.size() << endl;
    for(auto it : st) {
        cout << it.x << ' ' << it.y << '\n';
    }
    return 0;
}
