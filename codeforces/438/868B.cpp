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
int between(int x, int y, long  double a) {
    if(x > y) swap(x, y);
    return (a > x && a < y);
}
int main() {
    SYNC
    int h, m, s, t1, t2;
    cin >> h >> m >> s >> t1 >> t2;
    long double a ,b ,c;
    if(t1 == 12) t1 = 0;
    if(t2 == 12) t2 = 0;
    h %= 12;
    a = s/5.0;
    b = m/5.0 + s/300.0;
    c = h + (m*60 + s)/3600.0;
    // DEBUG(a);
    // DEBUG(b);
    // DEBUG(c);
    int ans = 0;
    int cnt = 0;
    cnt += between(t1, t2, a);
    cnt += between(t1, t2, b);
    cnt += between(t1, t2, c);
    ans = cnt == 0 || cnt == 3;
    cout << (ans ? "YES": "NO");
}