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
const int N = 305;
int n, m, l[N], r[N], x[N], dp[N][N][N] = {};
int main() {
    SYNC
    cin >> n >> m;
    FOR0(i, m) cin >> l[i] >> r[i] >> x[i];
    dp[0][0][0] = 1;
    FOR(i, 1, n + 1) {
        FOR(j, 0, i) {
            int kl = 0, kr = max(0, j - 1), valid = 1;
            FOR0(k, m) {
                if(r[k] == i) {
                    if(x[i] == 1 && j >= l[i]) valid = 0;
                    else if(x[i] == 2) {
                        if(l[i] > j) valid = 0;
                        else kr = min(kr, l[i] - 1);
                    }
                    else if(x[i] == 3) {
                        if(l[i])
                    }
                }
            }
            FOR(k, 0, max(1, j)) {

            }
        }
    }
}