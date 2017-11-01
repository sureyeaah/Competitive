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
#define SYNC std::ios::sync_with_stdio(false);  cin.tie(NULL);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<vi> vvi;
const int N = 100000 + 5;
const int LEN = 20;
const int S = (1 << LEN) + 5;
inline int opp(int x) {return (~x)&((1<<LEN)-1);}
int main() {
    SYNC
    string s;
    int n, a[N] = {}, cnt[S] = {}, dp[S] = {};
    cin >> n;
    FOR0(i, n) {
        cin >> s;
        for(char c : s) {
            a[i] |= 1 << (c - 'A');
        }
        cnt[a[i]]++;
        dp[opp(a[i])]++;
    }
    FOR0(i, LEN) {
        FOR(mask, 0, 1 << LEN) {
            if (mask & (1<<i))
                dp[mask] += dp[mask ^ (1 << i)];
        }
    }
    ll ans = 0;
    FOR0(i, 1 << LEN) {
        ans += 1LL * cnt[i] * dp[i];
    }
    cout << ((ans + cnt[(1 << LEN)-1]) >> 1) << endl;
}