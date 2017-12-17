#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define FOR0(i,n) for(int i=0, _##i=(n); i<_##i; ++i)
#define FOR(i,l,r) for(int i=(l), _##i=(r); i<_##i; ++i)
#define FORD(i,l,r) for(int i=(r), _##i=(l); --i>=_##i; )
#define repi(i,a) for(__typeof((a).begin()) i=(a).begin(), _##i=(a).end(); i!=_##i; ++i)
#define dwni(i,a) for(__typeof((a).rbegin()) i=(a).rbegin(), _##i=(a).rend(); i!=_##i; ++i)
#define SZ(a) ((int)((a).size()))
#define printCase() "Case #" << caseNum << ": "
#define pb push_back
#define mp make_pair
#define EPS (1e-9)
#define PI 3.1415926535
#define inf ((int)1e9)
#define INF ((ll)9e18)
#define mod (1000000000 + 7)
#define newl '\n'
#define SYNC std::ios::sync_with_stdio(false);  cin.tie(NULL);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<vi> vvi;
int t, a, b, s;
ll m;
struct Matrix {
    vvi v;
    Matrix() {v.assign(2, vi(2, 0));};
};
Matrix A, I;
Matrix mult(Matrix a, Matrix b) {
    Matrix ret;
    FOR0(i, 2) {
        FOR0(j, 2) {
            FOR0(k, 2) {
                ret.v[i][j] = (1LL*ret.v[i][j] + a.v[i][k] * 1LL * b.v[k][j]) % m;
            }
        }
    }
    return ret;
}
Matrix exp(Matrix A, int n) {
    Matrix ret = I;
    for(;n;n>>=1) {
        if(n & 1)
            ret = mult(ret, A);
        A = mult(A, A);
    }
    return ret;
}
ii val(Matrix v, ll a, ll b) {
    return mp((a * v.v[0][0] + b * v.v[0][1]) % m, (a *  v.v[1][0] + b * v.v[1][1]) % m);
}
int main() {
    SYNC
    A.v = vvi({vi({1, 1}), vi({1, 0})});
    I.v = vvi({vi({1, 0}), vi({0, 1})});
    cin >> t;
    while(t--) {
        cin >> m >> a >> b;
        if(a==0 && b==1) {
            cout << 0 << newl;
            continue;
        }
        s = sqrt(10.0 * m);
        map<ii, ll> st;
        Matrix big = exp(A, s), cur = big;
        for(ll i = s; i <= 10*m; i += s) {
            auto it = st.find(val(cur, 1, 0));
            if(it == st.end()) st[val(cur, 1, 0)] = i;
            cur = mult(cur, big);
        }
        Matrix small = I;
        ll ans = -1;
        FOR0(i, s) {
            auto it = st.find(val(small, b, a));
            if(it != st.end() && (-i + it->ss) >= 0) {
                ans = min(ans==-1 ? INF: ans, -i + it->ss);
            }
            small = mult(small, A);
        }
        cout << ans << newl;
    }
}