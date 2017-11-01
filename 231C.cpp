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
int n, k, a[N] = {}, ans = 0, ind = 0;
ll dp1[N] = {}, dp2[N] = {};
int search(int i) {
    int l = 0, r = i-1, ret = 0;
    while(l <= r) {
        int mid = (l + r) >> 1;
        ll cur = (mid - i)*(dp1[i] - dp1[i - mid]) + dp2[i] - dp2[i-mid];
        if(cur <= k) {ret = mid; l = mid + 1;}
        else r= mid - 1;
    }
    return ret;
}
int main() {
    SYNC
    cin >> n >> k;
    FOR0(i, n) cin >> a[i+1];
    sort(a+1, a+n+1);
    a[0] = a[1];
    FOR(i,1,n+1) {
        ll d = a[i] - a[i-1];
        dp1[i] = dp1[i-1] + d;
        dp2[i] = dp2[i-1] + i*d;
    }
    FOR(i,1,n+1) {
        ll cur = search(i);
        if(cur > ans) {ans = cur; ind = i;}
    }
    cout << ans+1 << " " << a[ind];
}