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
#define N (5 + (int)3e5)
int n, h[N], st[4*N];
int build(int p, int l, int r) {
    if(l == r) return st[p] = l;
    int mid = (l + r) >> 1;
    int lt = build(p << 1, l, mid), rt = build(p << 1|1, mid +1, r);
    return st[p] = h[lt] > h[rt] ? lt : rt;
}
int query(int p, int l, int r, int lq, int rq) {
    if(l > rq || r < lq) return n;
    if(lq <= l && r <= rq) return st[p];
    int mid = (l + r) >> 1;
    int lt = query(p << 1, l, mid, lq, rq);
    int rt = query(p << 1|1, mid+1, r, lq, rq);
    return h[lt] > h[rt] ? lt : rt;
}
int main() {
    SYNC
    cin >> n;
    FOR0(i, n) {
        cin >> h[i];
    }
    h[n] = -1;
    build(1,0,n-1);
    queue<ii> q[2]; q[0].push(mp(0,n-1));
    int cur = 0;
    while(!q[cur].empty()) {
        ll ret = 0;
        while(!q[cur].empty()) {
            int l = q[cur].front().ff; int r = q[cur].front().ss;
            q[cur].pop();
            int b = query(1,0,n-1,l,r);
            ret += h[b];
            if(b != l) q[!cur].push(mp(l, b-1));
            if(b != r) q[!cur].push(mp(b+1,r));
        }
        cout << ret << '\n';
        cur ^= 1;
    }
}