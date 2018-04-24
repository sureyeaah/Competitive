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
int seg[N*4] = {},lazy[4*N] = {};
void stupdate(int p, int l, int r, int lq, int rq, int val) {
    if(lazy[p]) {
        seg[p] += lazy[p];
        if(l != r) {
            lazy[p << 1] += lazy[p];
            lazy[p << 1|1] += lazy[p];
        }
        lazy[p] = 0;
    }
    if(l > rq || r < lq) return;
    if(lq <= l && r <= rq) {
        seg[p] += val;
        if(l != r) {
            lazy[p << 1] += val;
            lazy[p << 1|1] += val;
        }
        return;
    }
    int mid = (l + r) >> 1;
    stupdate(p << 1, l, mid, lq, rq, val);
    stupdate(p << 1|1, mid+1, r, lq, rq, val);
    seg[p] = max(seg[p << 1], seg[p << 1 | 1]);
}

int stquery(int p, int l, int r, int lq, int rq) {
    if(lazy[p]) {
        seg[p] += lazy[p];
        if(l != r) {
            lazy[p << 1] += lazy[p];
            lazy[p << 1|1] += lazy[p];
        }
        lazy[p] = 0;
    }
    if(l > rq || r < lq) return -INF;
    if(lq <= l && r <= rq) {
        return seg[p];
    }
    int mid = (l + r) >> 1;
    return max(stquery(p << 1, l, mid, lq, rq), stquery(p << 1|1, mid+1, r, lq, rq));
}

int main() {
    SYNC
    int n, a[N], b[N] = {};
    cin >> n;
    vvi done(N);
    FOR0(i, 4*N) seg[i] = -10000000;
    FOR(i, 1, n) {
        cin >> a[i];
        done[i + a[i]].pb(i);
        stupdate(1,1,n-1,i,i,-stquery(1,1,n-1,i,i));
        for(int x : done[i]) {
            stupdate(1,1,n-1,x,x,-stquery(1,1,n-1,x,x));
            stupdate(1,1,n-1,x,x,-10000000);
        }
        stupdate(1,1,n-1,1,n-1,1);
        b[i] = seg[1];
    }
    FOR0(i, n-1) cout << max(b[i+1],0) << " ";
}