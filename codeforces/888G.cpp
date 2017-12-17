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
const int N = 2e5 + 5;
const int B = 30;
const int inf = INT_MAX;
int n, a[N], x[N];
int best(int x[], int l1, int r1, int l2, int r2, int b) {
    if(l1 > r1 || l2 > r2) return inf;
    if(b < 0) return 0;
    int m1 = l1, m2 = l2;
    while(m1 <= r1 && (a[x[m1]] & (1 << b)) == 0) m1++;
    while(m2 <= r2 && (a[x[m2]] & (1 << b)) == 0) m2++;
    if((l1 < m1 && l2 < m2) || (m1 <= r1 && m2 <= r2)) {
        return min(best(x, l1, m1 - 1, l2, m2 - 1, b - 1),
            best(x, m1, r1, m2, r2, b - 1));
    } else return min(best(x, l1, m1 - 1, m2, r2, b - 1),
        best(x, m1, r1, l2, m2 - 1, b - 1)) + (1 << b);
}
ll solve(int x[], int n, int b) {
    if(n <= 1 || b < 0) return 0;
    int l = 0;
    while(l < n && !(a[x[l]] & (1 << b))) l++;;
    ll ans = solve(x, l, b - 1) + solve(x + l, n - l, b - 1);
    if(l > 0 && l < n) ans += best(x, 0, l - 1, l, n-1, b - 1) + (1 << b);
    return ans;
}
int main() {
    SYNC
    srand(time(0));
    cin >> n;
    FOR0(i, n) {
        cin >> a[i];
        x[i] = i;
    }
    sort(a, a + n);
    cout << solve(x, n, B - 1);
}