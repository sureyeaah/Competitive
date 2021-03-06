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
#define mod (7 + (int)1e9)
#define add(x, y) (((x)+(y))%mod)
#define mul(x, y) (((x)*(y))%mod)
#define N 20
int main() {
    SYNC
    int n;
    ll val[3][1 << N], r[1 << N] = {}, cnt[1 << N] = {};
    cin >> n;
    FOR0(j, 3) FOR0(i, 1 << n) cin >> val[j][i];
    FOR0(k, 3) {
        FOR0(i, n) {
            FOR0(j, 1 << n) {
                if(j & (1 << i)) val[k][j] = add(val[k][j], val[k][j^(1 << i)]);
            }
        }
    }
    FOR0(j, 1 << n) {
        r[j] = mul(val[2][j], (mul(val[0][j],val[1][j])));
    }
    FOR0(i, n) {
        FOR0(j, 1 << n) {
            if(j & (1 << i)) {
                cnt[j]++;
                r[j] = add(r[j], -r[j^(1 << i)]);
            }
        }
    }
    ll ans = 0;
    FOR0(j, 1 << n) ans = add(ans, mul(1<<cnt[j],(r[j]+mod)));
    cout << add(ans, mod);
}