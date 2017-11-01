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
int mod[2] = {7+(int)1e9, 9+(int)1e9};
long long inv(long long a, long long b){
 return 1<a ? b - inv(b%a,a)*b/a : 1;
}
ll gcd(ll a, ll b) {
    return b ? gcd(b, a%b): a;
}
int main() {
    SYNC
    int t;
    ll n;
    cin >> t;
    while(t--) {
        cin >> n;
        FOR0(j, 2) {
            ll a = n, b = n-1, c = 4*n - 6;
            int g = gcd(a,c);
            a /= g; c /= g;
            g = gcd(b, c);
            b /= g; c /= g;
            a %= mod[j]; b %= mod[j]; c %= mod[j];
            cout << ((a*b)%mod[j] * inv(c,mod[j]))%mod[j] << " ";
        }
        cout << "\n";
    }
}