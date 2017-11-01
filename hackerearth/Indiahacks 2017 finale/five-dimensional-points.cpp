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

int main() {
    SYNC
    int n, x[1005][5];
    cin >> n;
    FOR0(i, n) {
        FOR0(j, 5) cin >> x[i][j];
    }
    bitset<1005> ans;
    FOR0(i, n) ans[i] = 1;
    // if(n <= 2) {
    //     cout << n;
    //     FOR0(i, n) cout << i+1 << " ";
    //     return 0;
    // }
    FOR0(i, n) {
        FOR0(j, n) {
            if(j == i) continue;
            FOR0(k, n) {
                if(k == i || k == j) continue;
                ll cur = 0;
                FOR0(a, 5) {
                    cur += 1LL*(x[i][a] - x[j][a])*(x[i][a] - x[k][a]);
                }
                if(cur > 0) {
                    ans[i] = 0;
                    j = INF; break;
                }
            }
        }
    }
    cout << ans.count() << endl;
    FOR0(i, n) if(ans[i]) cout << i+1 << "\n";
}