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
    int t, n, b, c;
    ll a[3005];
    cin >> t;
    while(t--) {
        cin >> n >> b >> c;
        FOR0(i, n) cin >> a[i];
        vector<ll> x, y;
        FOR0(i, n-1) x.pb(a[i+1] - a[i]);
        while(SZ(x) > b) {
            int ind = 0; ll best = 1e18;
            FOR0(i, SZ(x) - 1) {
                if(x[i]*x[i+1] < best) {
                    ind = i;
                    best = x[i]*x[i+1];
                }
            }
            y.clear();
            FOR0(i, SZ(x)) {
                if(i == ind) {
                    y.pb(x[i] + x[i+1]);
                    i++;
                } else y.pb(x[i]);
            }
            x = y;
        }
        cout << accumulate(x.begin(), x.end(), 0LL, [&](ll lhs, ll rhs) {return lhs + rhs*rhs;}) << '\n';
    }
}