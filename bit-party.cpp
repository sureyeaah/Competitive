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
const int N = 1e3+3;
int t, r, b, c, m[N], s[N], p[N];
bitset<N> used;
bool ok(ll val) {
    int left = b, rs=0;
    while(left) {
        int cur=-1,curval=0;
        FOR0(i, c) {
            ll x = (val-p[i]) / s[i];
            if(x<0) x=0;
            ll avail = min(1LL*x,1LL*left); avail = min(avail, 1LL*m[i]);
            if(!used[i] && s[i]*1LL*avail+p[i]<=val&&curval<avail)
                cur=i,curval=avail;
        }
        if(cur==-1) return 0;
        left -= curval;
        rs++;
        used[cur]=1;
    }
    return rs<=r;
}
int main() {
    SYNC
    cin >> t;
    FOR(caseNum, 1, t+1) {
        cout << printCase();
        cin >> r >> b >> c;
        FOR0(i, c) cin >> m[i] >> s[i] >> p[i];
        ll l = 1, r = 4e18, ans=-1;
        while(l <= r) {
            used.reset();
            ll mid = (l+r)>>1;
            if(ok(mid)) ans=mid, r=mid-1;
            else l=mid+1;
        }
        cout << ans << endl;
    }
}