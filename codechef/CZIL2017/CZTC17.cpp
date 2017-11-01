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
const int N = 105;
int t, n, a[N], b[N];
bitset<N> vis;
ll gcd(ll a, ll b) {
    return b ? gcd(b, a % b): a;
}
int main() {
    SYNC
    cin >> t;
    while(t--) {
        cin >> n;
        FOR(i,1,n+1) {
            cin >> a[i];
        }
        FOR(i,1,n+1) {
            cin >> b[i];
        }
        vis.reset();
        ll ans = 1;
        FOR(i,1,n+1) {
            if(!vis[i]) {
                int j = i, len = 0;
                do {
                    vis[j] = 1;
                    j = b[j];       
                    len++;
                } while(j != i);
                ans = ans * len / gcd(ans, len);
            }
        }
        cout << ans << newl;
    }
}