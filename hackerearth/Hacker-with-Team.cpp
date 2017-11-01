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
#define maxn 100005
int n, q, s[maxn], x, o, l, r, k;
ll ft1[2*maxn] = {}, ft2[2*maxn] = {};
void update(ll ft[], int i, ll x) {
    for(; i <=2*n+2; i+=i&(-i))
        ft[i] += x;
}
ll query(ll ft[], int i) {
    ll ans = 0;
    for(; i; i-=i&(-i))
        ans += ft[i];
    return ans;
}
ll query(int b) {
    return query(ft1,b)*b - query(ft2,b);
}
int main() {
    SYNC
    cin >> n >> q;
    FOR(i, 1, n+1) {
        cin >> s[i];
        update(ft1, i+n+2, s[i]);
        update(ft2, i+n+2, s[i]*((ll) i+n+1));
    }
    while(q--) {
        cin >> o;
        if(o == 1) {
            cin >> l >> r >> k;
            ll ans = 
            l += n+2; r += n+2;
            cout << query(r) - query(l-1) + query(l - k - 2) - query(r - k - 1) << '\n';
        } else {
            cin >> l >> x;
            //ll pre = query(l+n+2)-query(l+n+1);
            update(ft1, l+n+2, x-s[l]);
            update(ft2, l+n+2, (x-s[l])*((ll) l+n+1));
            s[l] = x;
        }
    }
}