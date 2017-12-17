#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <cstring>
#include <bitset>
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
const int N = 1e4 + 5;
int n, w[N], m[N], x;
bitset<N> p;
vi primes;
inline ll c4(ll x) {return x * (x - 1) * (x - 2) * (x - 3) / 24;}
void sieve() {
    p.set(); p[0] = p[1] = 0;
    m[1] = 1;
    for(int i = 2; i < N; i ++) {
        if(p[i]) {
            primes.pb(i);
            m[i] = -1;
        }
        for(int j = 0; j < SZ(primes) && i * primes[j] < N; j++) {
            p[i * primes[j]] = 0;
            if(i % primes[j]) {
                m[i * primes[j]] = -m[i];
            } else {
                m[i * primes[j]] = 0;
                break;
            }
        }
    }
}
int main() {
    SYNC
    sieve();
    while(cin >> n) {
        memset(w, 0, sizeof w);
        FOR0(i, n) {
            cin >> x;
            w[x]++;
        }
        ll ans = 0;
        for(int i = 1; i < N; i++) {
            int val = 0;
            for(int j = i; j < N; j += i) {
                val += w[j];
            }
            ans += m[i] * c4(val);
        }
        cout << ans << newl;
    }
}