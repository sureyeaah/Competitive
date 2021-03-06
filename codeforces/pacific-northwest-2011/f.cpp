// Gear4        
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define FOR0(i,n) for(int i=0, _##i=(n); i<_##i; ++i)
#define FOR(i,l,r) for(int i=(l), _##i=(r); i<_##i; ++i)
#define FORD(i,l,r) for(int i=(r), _##i=(l); --i>=_##i; )
#define SZ(a) ((int)((a).size()))
#define printCase() "Case #" << caseNum << ": "
#define pb push_back
#define mp make_pair
#define SYNC std::ios::sync_with_stdio(false);  cin.tie(NULL);
#define ff first
#define ss second
template<typename T> using V = vector<T>;
template<typename T, typename U> using P = pair<T,U>;
using ld = long double;
using ll = long long;
#define endl '\n'
const int inf = 1e9, mod = 1e9 + 7;
const ll INF = 9e18;
const ld EPS = 1e-9, PI = acosl(-1.0);

V<int> solve(V<int> v) {
    V<int> ret;
    FOR0(i, SZ(v)-1) {
        ret.pb(v[i+1] - v[i]);
    }
    return ret;
}
int main() {
    SYNC
    int n, m, x;
    cin >> n;
    while(n--) {
        vector<int> v;
        cin >> m;
        FOR0(i, m) {
            cin >> x;
            v.pb(x);
        }
        while(SZ(v) > 1 && count(v.begin(), v.end(), 0) != SZ(v)) {
            v = solve(v);
        }
        if(SZ(v) == 1 && v[0] > 0) cout << "*fizzle*" << endl;
        else if(SZ(v) == 1 && v[0] < 0) cout << "*bunny*" << endl;
        else cout << string(m-SZ(v),'z') << "ap!" << endl;
    }
}