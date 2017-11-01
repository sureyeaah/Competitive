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
#define N 1000005
#define M 1005
int main() {
    SYNC
    int a[N], n, m, cur = 0;
    cin >> n >> m;
    FOR0(i, n) {
        cin >> a[i];
    }
    int ans;
    if(n < m) {
        bitset<M> dp[M];
        FOR0(i, n) {
            dp[i+1][a[i] % m] = 1;
            FOR0(j, m) {
                int jj = ((j-a[i]) % m); if(jj < 0) jj += m;
                dp[i+1][j] = dp[i+1][j] | (dp[i][j]) | dp[i][jj];
            }
        }
        ans = dp[n][0];
    } else ans = 1;
    cout << (ans ? "YES": "NO");
}