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
const int N = 1e5 + 5;
int t, n, a[N], x[N], b[N], out[N];
int main() {
    SYNC
    cin >> t;
    while(t--) {
        cin >> n;
        FOR0(i, n) cin >> a[i];
        FOR0(i, n) x[i] = i;
        sort(x, x + n, [&](int l, int r) {return a[l] < a[r];});
        FOR0(i, n) b[i] = x[n - i - 1];
        
        FOR0(i, n) {
            if(a[x[i]] == a[b[i]]) {
                swap(b[i], b[n-1]);
                break;
            }
        }
        FORD(i, 0, n) {
            if(a[x[i]] == a[b[i]]) {
                swap(b[i], b[0]);
                break;
            }
        }
        int ans = 0;
        FOR0(i, n) out[x[i]] = a[b[i]];
        FOR0(i, n) ans += a[i] != out[i];
        cout << ans << newl;
        FOR0(i, n) cout << out[i] << ' ';
        cout << newl;
    }
}