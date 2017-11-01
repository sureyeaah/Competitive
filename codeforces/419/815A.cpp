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
#define SYNC std::ios::sync_with_stdio(false)
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<vi> vvi;
#define maxn 105

int main() {
    SYNC;
    int n, m, g[maxn][maxn], row[maxn], col[maxn], rans[maxn], cans[maxn], rr[maxn], cc[maxn];
    cin >> n >> m;
    FOR0(i, n) FOR0(j, m) cin >> g[i][j];
    FOR0(i, n) FOR0(j, m) row[i] += g[i][j];
    FOR0(j, m) FOR0(i, n) col[j] += g[i][j];
    int ans = 2000000000;
    FOR0(x, 500*max(n,m) + 1) {
        bool poss = true;
        FOR0(i, n) if(row[i] - x < 0 || (row[i] - x)%m != 0) poss = false; else rans[i] = (row[i] - x)/m;
        if(!poss) continue;
        int y = 0;
        FOR0(i, n) y += rans[i];
        FOR0(i, m) if(col[i] - y < 0 || (col[i] - y)%n != 0) poss = false; else cans[i] = (col[i] - y)/n;
        if(!poss) continue;
        if(ans <= x + y) continue;
        ans = x + y;
        FOR0(i, n) rr[i] = rans[i];
        FOR0(i, m) cc[i] = cans[i];
    
    }
    if(ans == 2000000000) cout << -1 << endl;
    else {
        cout << ans << endl;
        FOR0(i, n) FOR0(j, rr[i]) cout << "row " << i+1 << '\n';
        FOR0(i, m) FOR0(j, cc[i]) cout << "col " << i+1 << '\n';
    }
}