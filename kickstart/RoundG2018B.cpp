#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf = 0x3c3c3c3c;
const ll infl = 0x3c3c3c3c3c3c3c3c;

struct Query{
    int id;
    ll k;
    bool operator<(const Query& rhs) const {
        return k < rhs.k;
    }
};

int T, N, Q;
ll L[400003], R[400003];
ll K[100003];
ll X[400003], Y[400003];
ll Z[100003];
ll A[4], B[4], C[4], M[4];
ll ans[100003];

vector<Query> qrs;
vector<ll> pts;
map<ll, int> open, close;
set<ll> st;

void init();
int main(){
    cin >> T;
    for(int t = 1; t <= T; t++) {
        qrs.clear();
        pts.clear();
        open.clear();
        close.clear();
        st.clear();

        cin >> N >> Q;
        init();

        for(int i = 1; i <= N; i++) {
            open[R[i]]++;
            close[L[i]]++;
            st.insert(R[i]);
            st.insert(L[i]);
        }

        pts = vector<ll>(st.begin(), st.end());

        for(int i = 1; i <= Q; i++) {
            qrs.push_back(Query{i, K[i]});
        }

        sort(qrs.begin(), qrs.end());
        reverse(pts.begin(), pts.end());

        int qth = 0;
        int cnt = 0;
        ll prv = pts[0];
        ll acc = 0;

        for(auto x : pts) {
//            printf("----------start-----------\n");
//            printf("x : %lld\n", x);
//            printf("acc : %lld, cnt : %d\n", acc, cnt);
            ll diff = prv - x;
            ll cacc = acc + cnt * (prv - x) + open[x] + cnt;
            while(qth < Q && cacc >= qrs[qth].k) {
                ll lo = 0, hi = diff;
//                printf("cacc : %lld, curk : %lld\n", cacc, qrs[qth].k);
                while(lo < hi) {
                    ll mid = (lo + hi) / 2;
                    ll tmp = acc + cnt * (mid + 1);
                    if(tmp < qrs[qth].k) lo = mid + 1;
                    else hi = mid;
                }
                ans[qrs[qth++].id] = prv - lo;
            }
            if(qth >= Q) break;

            acc += cnt * diff + close[x];
            cnt += open[x] - close[x];
            prv = x;
//            printf("----------end-----------\n");
        }

        for(int i = qth; i < Q; i++) {
            ans[qrs[i].id] = 0;
        }

        ll sum = 0;
        for(int i = 1; i <= Q; i++) {
//            printf("ans[%d] : %lld\n", i, ans[i]);
            sum = sum + ans[i] * i;
        }

        cout << "Case #" << t << ": " << sum << '\n';
    }
    return 0;
}

void init(){
    cin >> X[1] >> X[2] >> A[1] >> B[1] >> C[1] >> M[1];
    cin >> Y[1] >> Y[2] >> A[2] >> B[2] >> C[2] >> M[2];
    cin >> Z[1] >> Z[2] >> A[3] >> B[3] >> C[3] >> M[3];

    for(int i = 3; i <= N; i++) {
        X[i] = (A[1] * X[i - 1] + B[1] * X[i - 2] + C[1]) % M[1];
        Y[i] = (A[2] * Y[i - 1] + B[2] * Y[i - 2] + C[2]) % M[2];
    }
    for(int i = 3; i <= Q; i++) {
        Z[i] = (A[3] * Z[i - 1] + B[3] * Z[i - 2] + C[3]) % M[3];
    }

    for(int i = 1; i <= N; i++) {
        L[i] = min(X[i], Y[i]) + 1;
        R[i] = max(X[i], Y[i]) + 1;
    }
    for(int i = 1; i <= Q; i++) {
        K[i] = Z[i] + 1;
    }
}
