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
const int N = 4005; 
int dp[N][N], n;
vi a, l, r;
int main() {
    SYNC
    cin >> n; a.resize(n);
    FOR0(i, n) {
        cin >> a[i];
        dp[i][i] = a[i];
    }
    FOR0(i, n) {
        FOR(j, i+1, n) {
            dp[i][j] = max(dp[i][j-1], a[j]);
        }
    }
    FOR(k, 1, n) {
        FOR0(i, n-k) {
            a.pb(dp[i][i + k]);
        }
    }
    n = SZ(a); l.resize(n);
    if(1) {
        stack<int> s;
        FOR0(i, n) {
            while(!s.empty() && a[s.top()] <= a[i]) s.pop();
            l[i] = s.empty() ? i + 1: i - s.top();
            s.push(i);
        }
    }
    int ans = 0;
    if(1) {
        stack<int> s;
        FORD(i, 0, n) {
            while(!s.empty() && a[s.top()] < a[i]) s.pop();
            ll len = (s.empty() ? n - i: s.top() - i);
            // cerr << i << " " << l[i] << " " << len << newl;
            ans = (ans + a[i] * (len * l[i])) % mod;
            s.push(i);
        }
    }
    cout << ans;
}