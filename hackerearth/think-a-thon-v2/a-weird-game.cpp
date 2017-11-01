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
const int N = 100005;
int a[N], b[N];
void solve(string s, string p, int a[N]) {
    a[0] = 0;
    p += "$";
    FOR0(i, s.length()) {
        a[i+1] = a[i] + (s[i] == p[a[i]]);
    }
}
int cases; string s, p;
int search(int i) {
    int l = i, r = s.length(), ans = 0;
    while(l <= r) {
        int mid = (l + r) >> 1;
        if(a[i-1] + b[s.length() - mid] >= p.length()) {
            ans = mid - i + 1;
            l = mid + 1;
        } else r = mid - 1;
    }
    // DEBUG(ans);
    return ans;
}
int main() {
    SYNC
    cin >> cases;
    while(cases--) {
        cin >> s >> p;
        solve(s, p, a);
        reverse(s.begin(), s.end());
        reverse(p.begin(), p.end());
        solve(s, p, b);
        // reverse(b, b + 1 + n);
        ll ans = 0;
        FOR(i,1,s.length() + 1)
            ans += search(i);
        cout << ans << newl;
    }
}