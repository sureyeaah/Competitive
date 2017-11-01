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
#define INF ((int)1e9)
#define SYNC std::ios::sync_with_stdio(false);  cin.tie(NULL);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<vi> vvi;
int n; ll a[55], b[55], ans = 9e18;
bool poss(ll x) {
    ll val = 0;
    FOR0(i, n) {
        b[i] = a[i] + x;
        if(b[i] > n-1) val += (b[i] - (n-1) - 1) / (n + 1) + 1;
    }
    return (val <= x);
}
bool solve(ll x) {
    FOR0(i, n+2) if(poss(x + i)) {ans = x+i; return true;}
    return false;
}
int main() {
    SYNC
    
    cin >> n;
    FOR0(i, n) cin >> a[i];
    ll l = 0, r = 2e18;
    while(l <= r) {
        ll mid = (l + r) >> 1;
        if(solve(mid)) {
            r = mid - 1;
        } else l = mid + 1;
    }
    cout << ans;
}