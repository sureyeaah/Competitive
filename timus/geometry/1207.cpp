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
#define N 10005
int n, src = 0;
ll x[N], y[N];
int main() {
    SYNC
    cin >> n;
    FOR0(i, n) {
        cin >> x[i] >> y[i];
        if(x[i] < x[src]) src = i;
    }
    vi pts;
    FOR0(i, n) if(src != i) pts.pb(i);
    sort(pts.begin(), pts.end(), [&](int l, int r) {return 1LL * (y[src] - y[l])*(x[src] - x[r]) < 1LL * (y[src] - y[r])*(x[src] - x[l]);});
    cout << src+1 << " " << pts[n/2 - 1] + 1;
}