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
typedef pair<int,ii> iii;
#define N 100005
int n,p[N];
ii  x[N], y[N];
int findSet(int u) {
    return p[u] == u ? u : p[u] = findSet(p[u]);
}
bool sameSet(int u, int v) {
    return findSet(u) == findSet(v);
}
void unite(int u, int v) {
    if(((int)rand()) &1) swap(u, v);
    p[findSet(u)] = findSet(v);
}
int main() {
    SYNC
    cin >> n;
    FOR0(i, n) {
        cin >> x[i].ff >> y[i].ff;
        x[i].ss = y[i].ss = p[i] = i;
    }
    priority_queue<iii> pq;
    sort(x, x + n);
    sort(y, y + n);
    FOR0(i, n-1) {
        pq.push(mp(x[i].ff - x[i+1].ff, mp(x[i].ss, x[i+1].ss)));
    }
    FOR0(i, n-1) {
        pq.push(mp(y[i].ff - y[i+1].ff, mp(y[i].ss, y[i+1].ss)));
    }
    ll ans = 0;
    while(!pq.empty()) {
        int curw = pq.top().ff, u = pq.top().ss.ff, v = pq.top().ss.ss; pq.pop();
        if(sameSet(u, v)) continue;
        unite(u, v);
        ans += curw;
    }
    cout << -ans;
}