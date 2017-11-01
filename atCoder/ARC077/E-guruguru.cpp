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
#define INF ((ll)1e16)
#define SYNC std::ios::sync_with_stdio(false);  cin.tie(NULL);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<vi> vvi;
#define N 100005
int main() {
    SYNC
    int m, n, p, a, preva;
    ll dp1[N] = {}, dp2[N] = {}, ans = INF;
    cin >> n >> m >> preva;
    while(--n) {
        cin >> a;
        int d = a - preva;
        if(a > preva) {
            dp1[preva] += d - (a + 1);
            dp1[a] += a + 1 - d;
            dp1[m] += d;
            dp2[a]++; dp2[preva]--;
        } else {
            dp1[preva] += d - a - 1;
            dp1[a] += 1 + a - d - m;
            dp1[m] += 1 + m + a;
            dp2[m]++; dp2[preva]--; dp2[a]++;
        }
        preva = a;
    }
    FORD(i,1,m+1) {
        dp2[i] += dp2[i+1];
        dp1[i] += dp1[i+1];
        ans = min(ans, dp1[i] - i*dp2[i]);  
    }
    cout << ans;
}