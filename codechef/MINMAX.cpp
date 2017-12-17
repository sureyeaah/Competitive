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
typedef vector<ll> vi;
typedef vector<vi> vvi;
struct Poly {
    vi v;
    Poly operator+(Poly other) {
        Poly ret;
        ret.v.assign(max(SZ(other.v), SZ(v)), 0);
        FOR0(i, SZ(ret.v)) {
            if(i < SZ(v)) ret.v[i] += v[i];
            if(i < SZ(other.v)) ret.v[i] += other.v[i];
        }
        return ret;
    }
    Poly operator-(Poly other) {
        Poly ret;
        ret.v.assign(max(SZ(other.v), SZ(v)), 0);
        FOR0(i, SZ(ret.v)) {
            if(i < SZ(v)) ret.v[i] += v[i];
            if(i < SZ(other.v)) ret.v[i] -= other.v[i];
        }
        return ret;
    }
    Poly operator*(Poly other) {
        Poly ret;
        ret.v.assign(SZ(other.v) + SZ(v), 0);
        FOR0(i, SZ(v)) {
            FOR0(j, SZ(other.v)) {
                ret.v[i + j] += v[i] * other.v[j];
            }
        }
        return ret;
    }
};
Poly z;
Poly solve() {
    char x;
    cin >> x;
    if(x=='x') {
        return z;
    }
    Poly l = solve(); Poly r = solve();
    if(x=='M') {
        return l*r;
    }
    return l + r - l * r;
}
int main() {
    SYNC
    z.v.pb(0); z.v.pb(1);
    int t;
    cin >> t;
    while(t--) {
        Poly f = solve();
        long double ans = accumulate(f.v.begin(), f.v.end(), 0LL);
        FOR0(i, f.v.size()) {
            ans -= f.v[i] / ((long double)i + 1);
        }
        cout << fixed << setprecision(10) << ans << newl;
    }
}