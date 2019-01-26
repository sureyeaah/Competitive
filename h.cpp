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
#define pb push_back(
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
const int N = 2e5 + 5;
int t, n, m, x[N], s[N], d[N], cnt[N];
int main() {
    SYNC
    ifstream cin("bugged.in");
    cin >> t;
    while(t--) {
        cin >> n >> m;
        FOR0(i, n) cnt[i+1] = 0;
        FOR0(i, n) cin >> x[i+1];
        ll ans  = 0;
        FOR0(i, m) {
            cin >> s[i] >> d[i];
            cnt[s[i]]++;
            cnt[d[i]]--;
            ans += abs(x[d[i]] - x[s[i]]);
        }
        FOR(i, 1, n + 1) if(cnt[i]) ans=-1;
        cout << ans << endl;
    }
}