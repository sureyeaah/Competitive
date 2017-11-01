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
int n; ll m, s[11];
map<ll, int> memo;
int solve(ll x) {
    if(memo.find(x) != memo.end()) return memo[x];
    int ret = 0;
    set<int> g;
    FOR0(i, n) {
        if(x % s[i]) continue;
        if(!(s[i] & 1)) g.insert(0);
        else g.insert(solve(x/s[i]));
    }
    for(int val : g) {
        if(ret == val) ret++;
    }
    return memo[x] = ret;
}
int main() {
    SYNC
    cin >> m >> n;
    FOR0(i, n) cin >> s[i];
    cout << (solve(m) ? "First": "Second");
}