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
#define N 5000
int main() {
    SYNC
    int n, b[N], d[N];
    cin >> n;
    FOR0(i, n) {
        cin >> b[i];
    }
    FOR0(i, n) cin >> d[i];
    vii edges;
    if(n > 1 && b[1] != d[1]) {
        cout << -1;
        return 0;
    }
    FOR(i,1,n) edges.pb(mp(1, b[i]));
    FOR(i,1,n-1) edges.pb(mp(d[i],d[i+1]));
    cout << SZ(edges) << endl;
    for(auto e : edges) {
        cout << e.ff << " " << e.ss << '\n';
    }
}