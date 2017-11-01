#include <bits/stdc++.h>
using namespace std;
#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define FOR0(i,n) for(int i=0, _##i=(n); i<_##i; ++i)
#define FOR(i,l,r) for(int i=(l), _##i=(r); i<_##i; ++i)
#define FORD(i,l,r) for(int i=(r), _##i=(l); --i>=_##i; )
#define repi(i,a) for(__typeof((a).begin()) i=(a).begin(), _##i=(a).end(); i!=_##i; ++i)
#define dwni(i,a) for(__typeof((a).rbegin()) i=(a).rbegin(), _##i=(a).rend(); i!=_##i; ++i)
#define pb push_back
#define mp make_pair
#define INF (int)1e9
#define EPS 1e-9
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<vi> vvi;

int main() {
    int n, l, r, a[100000 + 10], x, c, pindex[100000 + 10], b[100000+10]; // px is automatically sorted
    bool possible = true;
    cin >> n >> l >> r;
    FOR0(i, n) scanf("%d", a+i);
    FOR0(i, n) {
        scanf("%d", &x);
        pindex[x] = i;
    }
    b[pindex[1]] = l; // start b with lowest val;
    c = b[pindex[1]] - a[pindex[1]];
    FOR(pval,2,n+1) {
        c++;
        b[pindex[pval]] = a[pindex[pval]] + (c);
        if(b[pindex[pval]] < l) {
            b[pindex[pval]] = l;
            c = b[pindex[pval]] - a[pindex[pval]];
        }
        if(b[pindex[pval]] > r) {
            possible = false;
            break;
        }
    }
    if(possible) {
        FOR0(i, n) printf("%d ", b[i]);
    } else printf("-1");
    printf("\n");
}