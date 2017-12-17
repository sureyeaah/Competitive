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
int n;
string a, b;
unordered_set<ll> s;
const int N = 1e5 + 5;
const int p1 = 452521529, p2 = 641927113, p3 = 882681887, p4 = 807900637;
inline ll h(ll x, ll y) {
    return (x << 32) + y;
}
int hashing(string & x, int l, ll p, ll q) {
    int ret = 0; ll pp = 1;
    FOR0(i, l) {
        ret = (ret + (x[i] - 'A') * pp) % q;
        pp = pp * p % q;
    }
    return ret;
}
int modexp(int a, int b, int p) {
    int ret = 1;
    for(;b;b>>=1) {
        if(b & 1)
            ret = (ret * 1LL * a) % p;
        a = (a * 1LL * a) % p;
    }
    return ret;
}
int inv(int a, int p) {return modexp(a, p-2, p);}

int main() {
    SYNC
    cin >> n >> a >> b;
    int l = 1, r = n, st, ans = 0;
    int inv1 = inv(p1, p2), inv3 = inv(p3, p4), pp1[N], pp3[N];
    pp1[0] = pp3[0] = 1;
    FOR(i, 1, N) pp1[i] = pp1[i-1] * 1LL * p1 % p2;
    FOR(i, 1, N) pp3[i] = pp3[i-1] * 1LL * p3 % p4;
    while(l <= r) {
        s.clear();
        int len = (l + r) >> 1;
        ll val1 = hashing(a, len, p1, p2), val2 = hashing(a, len, p3, p4);
        s.insert(h(val1, val2));
        FOR(i, len, n) {
            val1 = ((val1 - (a[i - len] - 'A') + p2) * inv1) % p2;
            val2 = ((val2 - (a[i - len] - 'A') + p4) * inv3) % p4;
            val1 = (val1 + (a[i] - 'A') * 1LL * pp1[len-1]) % p2;
            val2 = (val2 + (a[i] - 'A') * 1LL * pp3[len-1]) % p4;
            s.insert(h(val1, val2));
        }
        val1 = hashing(b, len, p1, p2), val2 = hashing(b, len, p3, p4);
        if(s.find(h(val1, val2)) != s.end()) {
            st = 0, ans = len;
            l = len + 1;
            continue;
        }
        FOR(i, len, n) {
            val1 = ((val1 - (b[i - len] - 'A') + p2) * inv1) % p2;
            val2 = ((val2 - (b[i - len] - 'A') + p4) * inv3) % p4;
            val1 = (val1 + (b[i] - 'A') * 1LL * pp1[len-1]) % p2;
            val2 = (val2 + (b[i] - 'A') * 1LL * pp3[len-1]) % p4;
            if(s.find(h(val1, val2)) != s.end()) {
                st = i - len + 1, ans = len;
                l = len + 1;
                break;
            }
        }
        if(ans != len) r = len - 1;
    }
    cout << b.substr(st, ans);
}