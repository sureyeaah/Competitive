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
int n, m, h[501][501],q,l,u,init[501],final[501],valid[501];
// O(n)
bool check (int w) {
    memset(valid,true,sizeof(valid));
    FOR0(j, n) {
        if (final[j] == -1 || init[j] == m || init[j] > final[j]) {
            valid[j] = false;
        }
        if (final[j] - init[j] + 1 < w) {
                valid[j] = false;
        }
    }
    int checkedBefore = 0;
    FOR0(i, n-w+1) {
        int j = checkedBefore;
        while(j < i+w) {
            if (!valid[j]) {
                checkedBefore = j+1;
                i = j;
                break;
            }
            j++;
        }
        if(i != j) {
            checkedBefore = i+w-1;
            if(final[i+w-1] - init[i] + 1 >= w) return true;
        }
    }
    return false;
}
// O(n.lg(n))
int square() {
    FOR0(i, n) init[i] = lower_bound(h[i],h[i]+m,l) - h[i];
    FOR0(i, n) final[i] = upper_bound(h[i],h[i]+m,u) - h[i] - 1;
    int l = 0, r = min(n,m);
    while(l < r) {
        int mid = (l+r+1) >> 1;
        if(check(mid)) l = mid;
        else r = mid - 1;
    }
    return r;
}
int main() {
    while(scanf("%d%d",&n,&m) && (n || m)) {
        FOR0(i, n) FOR0(j, m) scanf("%d", h[i] + j);
        scanf("%d",&q);
        while(q--) {
            scanf("%d%d",&l,&u);
            printf("%d\n", square());
        }
        printf("-\n");
    }
}