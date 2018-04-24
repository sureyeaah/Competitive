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
#define EPS (1e-9)
#define PI 3.1415926535
#define inf ((int)1e9)
#define INF ((ll)9e18)
#define mod (1000000000 + 7)
#define newl '\n'
#define SYNC std::ios::sync_with_stdio(false);  cin.tie(NULL);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<vi> vvi;
const int N = 1e5 + 5;
int n, h, w, a[N], vis[N] = {}, uses[N] = {}, nxt[N];
ll suf[N] = {};
ll val(int st, int nd) {
    ll ret = nd - st;
    if(nd < n) ret += suf[st] - suf[nd + 1];
    else ret += suf[st] + suf[0] - suf[(nd % n) + 1] + suf[0] * (nd / n - 1);
    return ret;
}
int main() {
    SYNC
    cin >> n >> w >> h;
    FOR0(i, n) cin >> a[i];
    suf[n] = 0;
    FORD(i,0,n) {
        suf[i] = suf[i+1] + a[i];
    }
    FOR(i,0,n) {
        int l = i, r = 1e9, ans;
        while(l <= r) {
            int mid = (l + r) >> 1;
            if(val(i, mid) <= w) {
                ans = mid;
                l = mid + 1;
            } else r = mid - 1;
        }
        nxt[i] = (ans + 1) % n;
        uses[i] = ans/n + !i;
        // DEBUG(nxt[i]); DEBUG(uses[i]);
    }
    ll ans = 0; int cur = 0, ind = 0;
    while(!vis[cur] && h > 0) {
        ans += uses[cur];
        a[ind++] = cur;
        vis[cur] = 1;
        h--;
        cur = nxt[cur];
    }
    if(h > 0) {
        int st;
        FORD(i, 0, ind) {
            if(a[i] == cur) {
                st = i;
                break;
            }
        }
        ll totwt = 0, toth = ind - st;
        FOR(i, st, ind) {
            totwt += uses[a[i]];
        }
        ll k = h/toth;
        ans += totwt * k;
        h -= k * toth;
        while(h > 0) {
            ans += uses[cur];
            h--;
            cur = nxt[cur];
        }
    }
    cout << ans;
}