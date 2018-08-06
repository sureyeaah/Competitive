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
const int N = 2e5 + 5;
string s, sl, sr; int n, cnt[26], cur[26], loc[N], a[N], ft[N];
ll ans = 0;
int query(int i) {
    int ret = 0;
    for(; i; i-=i&-i) ret += ft[i];
    return ret;
}
void upd(int i) {
    for(; i <= n; i += i&-i) ft[i]++;
}
int main() {
    SYNC
    cin >> s; n = s.length();
    for (char c : s) {
        cnt[c-'a']++;
    }
    int oe[2] = {};
    FOR0(i, 26) oe[cnt[i]&1]++;
    if(oe[1] > 1) {
        cout << -1;
        return 0;
    }
    FOR0(i, n) {
        int c = s[i] - 'a';
        if(++cur[c] > cnt[c] / 2)
            loc[i] = 1;
    }
    int tmp = 0;
    FOR0(i, n) {
        if(!loc[i]) tmp++;
        if(loc[i]) ans += n/2 - tmp;
    }
    cerr << ans << endl;
    FOR0(i, n) {
        if(loc[i]) sr.pb(s[i]);
        else sl.pb(s[i]);
    }
    if(n&1) {
        FOR0(i, (int)sr.length()) {
            if(cnt[sr[i] - 'a'] & 1) {
                ans += i;
                sr.erase(i, 1);
                break;
            }
        }
    }
    reverse(sr.begin(), sr.end());
    V<V<int>> pos(26);
    FORD(i, 0, sr.length()) {
        pos[sr[i] - 'a'].pb(i+1);
    }
    FOR0(i, sl.length()) {
        int c = sl[i] - 'a';
        a[i] = pos[c].back();
        pos[c].pop_back();
    }
    n = sl.length();
    FOR0(i, n) {
        ans += i-query(a[i]);
        upd(a[i]);
    }
    cout << ans;
}