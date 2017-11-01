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
typedef pair<ii, ll> iii;
#define N 100005
int n,m,k,l,p[N],siz[N];
ll c[65];
vector<iii> g;
int findSet(int i) {
    return i == p[i] ? i: p[i] = findSet(p[i]);
}
void unite(int u, int v) {
    int x = findSet(u), y = findSet(v);
    if(x != y) {
        if(((int)rand()*10) & 1) swap(x, y);
        p[x] = y;
        siz[y] += siz[x];
    }
}
bool solve(ll mask) {
    FOR0(i,n+1) p[i] = i;
    FOR0(i,n+1) siz[i] = 1;
    
    for(auto& curr: g) {
        if((mask & curr.ss) == curr.ss) unite(curr.ff.ff, curr.ff.ss);
    }
    return (siz[findSet(1)] == n);
}
int main() {
    SYNC
    int u, v, x;
    cin >> n >> m >> k;
    FOR0(i, k) cin >> c[i];
    ll sum = 0;
    FOR0(i, k) sum += c[i];
    FOR0(i, m) {
        cin >> u >> v >> l;
        ll mask = 0;
        while(l--) {
            cin >> x;
            mask |= 1LL << (x - 1);
        }
        g.pb(mp(mp(u, v), mask));
    }
    ll mask = (1LL << k) - 1;
    if(solve(mask)) {
        FORD(i,0,k) {
            if(solve(mask ^ (1LL << i))) {
                mask ^= 1LL << i;
                sum -= c[i];
            }
        }
    } else sum = -1;
    cout << sum;
}