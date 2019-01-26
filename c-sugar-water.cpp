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
#define SYNC std::ios::sync_with_stdio(false);  cin.tie(NULL);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<vi> vvi;
#define N 3005
int main() {
    SYNC
    int a, b, c, d, e, f;
    cin >> a >> b >> c >> d >> e >> f;
    bitset<N> pw, ps;
    pw[0] = ps[0] = 1;
    FOR(i,100*a,N) {
        pw[i] = pw[i] | pw[i-100*a];
    }
    FOR(i,100*b,N) {
        pw[i] = pw[i] | pw[i-100*b];
    }
    FOR(i,c,N) {
        ps[i] = ps[i] | ps[i-c];
    }
    FOR(i,d,N) {
        ps[i] = ps[i] | ps[i-d];
    }

    int aw=0 ,as=0;
    long double ans = -1.0;
    FOR(tot, 1, f+1) {
        FOR(water, 1, tot+1) {
            int sugar = tot - water;
            if(pw[water] && ps[sugar] && sugar <= e*water/100) {
                long double cur = (100.0 * sugar)/tot;
                if(cur > ans) {
                    ans = cur;
                    aw = tot; as = sugar;
                }
            }
        }
    }
    cout << aw << " " << as;
}