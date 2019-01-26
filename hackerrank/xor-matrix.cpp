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
int n, a[N], b[N];
void nxt(int k) {
    FOR0(i, n) b[i] = a[i] ^ a[(i+k)%n];
    FOR0(i, n) a[i] = b[i];
}
int main() {
    SYNC
    ll m;
    cin >> n >> m; m--;
    FOR0(i, n) cin >> a[i];
    for(int i = 0; m; i++) {
        if(m & (1LL << i)) {
            nxt((1LL << i) % n);
            m ^= 1LL << i;
        }
    }
    FOR0(i, n) cout << a[i] << " ";
}
