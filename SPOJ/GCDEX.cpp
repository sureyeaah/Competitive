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
const int N = 1000005;
vi primes;
int phi[N] = {};
ll ans[N] = {};
void sieve() {
    phi[1] = 1;
    for(int i = 2; i < N; i ++) {
        if(!phi[i]) {
            primes.pb(i);
            phi[i] = i - 1;
        }
        for(int pri : primes) {
            if(pri * i >= N) break;
            if(i % pri == 0) {
                phi[pri * i] = phi[i] * pri;
                break;
            } else phi[pri * i] = (phi[i] * (pri - 1));
        }
    }
    for(int i = 1; i < N; i++) {
        for(int j = 1; j*i < N; j ++) {
            ans[j*i] += phi[j]*1LL*i;
        }
        ans[i] += ans[i-1];
    }
}
int main() {
    SYNC
    sieve();
    int n;
    while(cin >> n && n) {
        cout << (ans[n] - (n * 1LL * (n+1))/2) << newl;
    }
}