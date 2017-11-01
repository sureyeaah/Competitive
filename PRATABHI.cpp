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
#define isset(x,i) (((x) & (1 << i)) != 0)
#define N 100005
#define BITS 30
int n, a[N], q, type, val, ind, f[BITS], pos[BITS], st[4*N] = {};
void update(int p, int l, int r, int i) {
    if(i > r || i < l) return;
    if(l == r) {st[p] = val; return;}
    update(p << 1, l, (l+r) >> 1, i);
    update(p << 1|1, ((l+r) >> 1) + 1, r, i);
    st[p] =st[p << 1] | st[p << 1|1];
}
int query(int p, int l, int r, int bit) {
    if(1 > r || n < l) return INF;
    if (l == r) return isset(st[p],bit) ? l : INF;
    return isset(st[p<<1], bit) ? query(p<<1,l,(l+r)>>1,bit) : query(p<<1|1,((l+r)>>1) + 1,r,bit);
}
int main() {
    SYNC
    cin >> n >> q;
    memset(f, 63, sizeof f);
    FOR0(i, BITS) pos[i] = i;
    while(q--) {
        cin >> type;
        if(type == 1) {
            cin >> ind >> val;
            update(1,1,n,ind);
            FOR0(i, BITS) {
                f[i] = query(1,1,n,i);
            }
            sort(pos, pos + BITS, [&](int lhs, int rhs) {return f[lhs] > f[rhs];});
            a[ind] = val;
        } else {
            cin >> val;
            int cnt = 0, last = n+2;
            FOR(i, 0, BITS) {
                int cur = f[pos[i]];
                if(isset(val, pos[i])) {
                    if(cur > n) break;
                    if((last == cur && cnt) || last > cur) {
                        val -= 1 << pos[i];
                        last = cur;
                        cnt = 1;
                    }
                    else break;
                } else {
                    if(cur <= n) {
                        if((cnt)) {
                            if(last == cur) {val = 1; break;}
                            cnt = 0;
                        }
                        last = cur;
                    }
                }
            }
            cout << (val ? "NO\n": "YES\n");
        }
    }
}