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
const int N = 1e3 + 3; int n, x[N], y[N], a[N], b[N];
int main() {
    SYNC
    cin >> n;
    FOR0(i, n) cin >> x[i] >> y[i];
    FOR0(i, n) cin >> a[i] >> b[i];
    FOR0(i, n) {
        int tx = x[0] + a[i], ty = y[0] + b[i];
        set<P<int, int>> s;
        FOR0(i, n) {
            s.insert({tx-x[i], ty-y[i]});
        }
        int as = 1;
        FOR0(i, n) {
            if(s.find(make_pair(a[i], b[i])) == s.end()) as=0;
        }
        if(as) {
            cout << tx << " " << ty; return 0;
        }
    }
}