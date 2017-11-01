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
#define N 100005
int main() {
    SYNC
    int y, n, a, same = 0;
    vi x;
    cin >> n >> a;
    FOR0(i, n) {
        cin >> y;
        if(y == a) same++;
        else x.pb(y);
    }
    n -= same - 1;
    x.pb(a);
    sort(x.begin(), x.end());
    int p = lower_bound(x.begin(), x.end(), a) - x.begin();
    int ans = 1e9;
    if(n == 1) ans = 0;
    if(p != 0) ans = - x[1] + x[n-1] + min(- x[1] + x[p], x[n-1] - x[p]);
    if(p != n-1) ans = min(ans, - x[0] + x[n-2] + min(- x[0] + x[p], x[n-2] - x[p]));
    cout << ans;
}