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
long double sq(long double x) {
    return x * x;
}
int main() {
    SYNC
    int a, b, d, rt1, rt2, rb1, rb2, h;
    cin >> a >> b >> d;
    cin >> rb1 >> rt1;
    cin >> rb2 >> rt2 >> h;
    long double r1 = rt1, r2 = rt2;
    if(h > d) {
        r1 = rb1 + (rt1 - rb1)/2.0 / h * d;
        r2 = rb2 + (rt2 - rb2)/2.0 / h * d;
    }
    int ans = (sq(rt1 + rt2) <= sq(a - r1 - r2) + sq(b - r1 - r2)) && (2*max(r1, r2) <= min(a, b));
    cout << (ans ? "YES": "NO");
}