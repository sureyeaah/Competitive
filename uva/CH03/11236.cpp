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
    // abcd = 10^6*(a+b+c+d) when using integers
    // a >= 159
    FOR(a, 159, 2001) {
        FOR(b, (int)ceil(pow(634960421.0/a,1.0/3)),a+1) {
            FOR(c, (int)ceil(1000001.0/((double)a*b)), b+1) {
                double d = (1000000.0*(a+b+c))/((ll)a*b*c-1000000);
                if(d == (int)d && d <= c) printf("%.2f %.2f %.2f %.2f\n",d/100.0,c/100.0,b/100.0,a/100.0);
            }
        }
    }
}