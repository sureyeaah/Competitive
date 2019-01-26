// Gear4        
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define FOR0(i,n) for(int i=0, _##i=(n); i<_##i; ++i)
#define FOR(i,l,r) for(int i=(l), _##i=(r); i<_##i; ++i)
#define FORD(i,l,r) for(int i=(r), _##i=(l); --i>=_##i; )
#define SZ(a) ((int)((a).size()))
#define printCase() "Case #" << caseNum << ": "
#define pb push_back
#define mp make_pair
#define SYNC std::ios::sync_with_stdio(false);  cin.tie(NULL);
#define ff first
#define ss second
template<typename T> using V = vector<T>;
template<typename T, typename U> using P = pair<T,U>;
using ld = long double;
using ll = long long;
#define endl '\n'
const int inf = 1e9, mod = 1e9 + 7;
const ll INF = 9e18;
const ld EPS = 1e-9, PI = acosl(-1.0);
const int N = 3e5 + 5, B = 500;
int n, m, a[N], b[N], bpos[N], apos[N];
int us[N], s[N];
int query(int ind, int l, int r) {
    int i = ind * B;
    int ret = lower_bound(s + i, s + i + B, l) - s - i;
    int x = upper_bound(s + i, s + i + B, r) - s - i;
    return x - ret;
}
void upd(int ind, int x) {
    int st = ind / B * B;
    FOR(i, st, st + B) {
        if(s[i] == us[ind]) {
            FOR(j, i+1, st + B) {
                s[j-1] = s[j];
            }
            i=inf;
        }
    }
    s[st+B-1] = x;
    FORD(i, st+1, st + B) {
        if(s[i-1]>s[i]) swap(s[i-1], s[i]);
        else break;
    }
    us[ind] = x;
}
// void build(int p, int l, int r) {
//     int len = r-l+1;
//     if(l == r) {
//         st[p].resize(len);
//         return;
//     }
//     build()
//     build(p<<1,l,mid); build(p<<1|1,mid+1,r);
// }
int main() {
    SYNC
    cin >> n >> m;
    memset(us, 63, sizeof us);
    memset(s, 63, sizeof s);
    FOR0(i, n) cin >> a[i];
    FOR0(i, n) {
        cin >> b[i];
        bpos[b[i]]=i;
        apos[a[i]]=i;
    }
    FOR0(i, n) us[i] = s[i] = bpos[a[i]];
    for(int i = 0; i < n; i+= B) {
        sort(s+i, s+i+B);
    }
    while(m--) {
        int q, la, ra, lb, rb, x, y;
        cin >> q;
        if(q==1) {
            cin >> la >> ra >> lb >> rb;
            la--; ra--; lb--; rb--;
            int be = ((la/B) * B) + B - 1;
            int ans = 0;
            while(la <= ra && la <= be) {
                ans += us[la] >= lb && us[la] <= rb;
                la++;
            }
            be = ((ra/B) * B);
            while(la <= ra && ra >= be) {
                ans += us[ra] >= lb && us[ra] <= rb;
                ra--;
            }
            int bl = la / B, br = ra/B;
            if(la < ra) {
                FOR(i, bl, br+1) {
                    ans += query(i, lb, rb);
                }
            }
            cout << ans << endl;
        } else {
            cin >> x >> y;
            x--; y--;
            int bx = b[x], by = b[y];
            swap(b[x], b[y]);
            bpos[bx] = y; bpos[by] = x;
            int i = apos[bx], j = apos[by];
            upd(i, y); upd(j, x);
        }
    }
}