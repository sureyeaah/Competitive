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
const int N = 10005;
int main() {
    SYNC
    int n, l, w, x[N], r[N], lt[N];
    long double ld[N], rd[N];
    while(cin >> n) {
        cin >> l >> w;
        FOR0(i, n) {
            cin >> x[i] >> r[i];
            lt[i] = i;
            if(2*r[i] <= w) ld[i] = rd[i] = l + 100;
            else {
                ld[i] = x[i] - pow((long double)r[i]*r[i] - w*w/4.0, 0.5);
                rd[i] = x[i] + pow((long double)r[i]*r[i] - w*w/4.0, 0.5);
            }
        }
        sort(lt, lt + n, [&](int lhs, int rhs){ return ld[lhs] < ld[rhs];});
        long double cur = 0;
        int ans = 0;
        int i = 0;
        while(i < n) {
            bool found = false;
            long double rmax = -1e8;
            if(abs(l - cur) <= EPS) {
                break;
            }
            while(i < n && ld[lt[i]] - cur <= 2*EPS) {
                if(rd[lt[i]] > rmax && rd[lt[i]] - cur > EPS) {
                    rmax = rd[lt[i]];
                    found = true;
                }
                i++;
            }
            if(found) {
                ans++;
                cur = rmax;
                // DEBUG(cur);
            } else break;
        }
        if(l - cur > EPS) ans = -1;
        cout << ans << newl;
    }
}