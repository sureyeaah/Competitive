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
const int LOGN = 20;
const int N = 1 << LOGN;
int main() {
    SYNC
    int t, n, a[N];
    bitset<N> e;
    cin >> t;
    while(t--) {
        cin >> n;
        e.reset();
        FOR0(i, n) {
            cin >> a[i];
            e[a[i]] = 1;
        }
        FOR0(i, LOGN) {
            FOR(mask,1,N) {
                if(mask & (1 << i)) {
                    e[mask] = e[mask] | e[mask ^ (1 << i)];
                }
            }
        }
        FOR0(i, n) {
            cout << (e[~a[i] & ((1 << LOGN) - 1)]) << " \n"[i==n-1];
        }
    }
}