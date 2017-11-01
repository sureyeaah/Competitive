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
#define N 100005
int main() {
    SYNC
    int t, n, d;
    ll a[N];
    cin >> t;
    while(t--) {
        cin >> n >> d;
        ll ans = -1;
        FOR0(i, n) cin >> a[i];
        ll sum = 0;
        FOR0(i, n) sum += a[i];
        if(sum%n == 0) {
            ans = 0;
            int x = sum/n;
            FOR0(i, d) {
                int cur = 0;
                for(int j = i; j < n; j += d) {
                    a[j] -= cur;
                    ans += abs(cur);
                    if(j + d >= n && a[j] != x) {ans = -1; i = INF; break;}
                    cur = x - a[j];
                }
            }
        }
        cout << ans << '\n';
    }
}