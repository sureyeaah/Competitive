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
typedef pair<ll, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<vi> vvi;
set<pair<pair<ll,int>, pair<ll, int>>> ans;
ll n;
const ll M = 2e18;
ll exp(ll ret, ll a, int b) {
    if(ret == -1) return -1;
    FOR0(i, b) {
        if(ret > M/a) return -1;
        ret *= a;
    }
    return ret;
}
void solve(int x, int y) {
    ll l = 1, r = pow(1.0*n, 1.0/(x + y)) + 1;
    while(l <= r) {
        ll mid = (l + r) >> 1, val = exp(exp(1, mid, x), mid + 1, y);
        if(val != -1 && val < n) {
            l = mid + 1;
        } else if(val == n) {
            ans.insert({{mid, x}, {mid + 1, y}});
            break;
        } else r = mid - 1;
    }
}
int main() {
    SYNC
    ifstream cin("little.in");
    ofstream cout("little.out");
    cin >> n;
    for(int i = 0; i < 62; i++) {
        if((1LL << i) == n) {
            cout << -1; return 0;
        }
    }
    ans.insert(mp(mp(n,1),mp(n+1,0)));
    FOR(i, 1, 61) {
        FOR(j, 0, 61) {
            solve(i, j);
        }
    }
    cout << SZ(ans) << newl;
    for( auto cur : ans) {
        cout << cur.ff.ss + cur.ss.ss << " ";
        FOR0(i, cur.ff.ss) cout << cur.ff.ff << " ";
        FOR0(i, cur.ss.ss) cout << cur.ss.ff << " ";
        cout << newl;
    }
}