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
#define N 105
#define S 30005
int main() {
    SYNC
    int n, m, c[N], s, dp[S], src[S];
    memset(dp, -1, sizeof dp);
    cin >> n;
    FOR0(i,n) {
        cin >> c[i+1];
    }
    dp[0] = 1; src[0] = 0;
    FOR(i,1,n+1) {
        FOR(val, c[i], S) {
            int & cur = dp[val];
            int & prev = dp[val-c[i]];
            if(prev == -1 || cur == 2) continue;
            if(prev == 2 || cur == 1) cur = 2;
            else {
                cur = 1;
                src[val] = i;
            }
        }
    }
    cin >> m;
    FOR0(i, m) {
        cin >> s;
        if(dp[s] == -1) cout << "Impossible\n";
        else if(dp[s] == 2) cout << "Ambiguous\n";
        else {
            vi output;
            while(src[s]) {
                output.pb(src[s]);
                s -= c[src[s]];
            }
            reverse(output.begin(), output.end());
            for(int x : output) cout << x << " ";
            cout << newl;
        }
    }
}