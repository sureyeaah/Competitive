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
#define pb emplace_back
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
#define N 500005
#define A 1005
int t, n, a[N], cnt[A];
vi factors[A];
set<int> s;
bitset<A> prime, good;
void sieve() {
    prime.set();
    good.set();
    prime[0] = prime[1] = 0;
    FOR(i,2,A) {
        if(!prime[i]) continue;
        for(int j = i; j < A; j += i) {
            prime[j] = 0;
            factors[j].pb(i);
            int x = j;
            int p = 0;
            while(x % i == 0) {x /= i; p++;}
            if(p > 1) good[j] = 0;
        }
    }
}
bool add(int i) {
    bool ret = true;
    for(int p : factors[a[i]]) {
        if(cnt[p]) ret = false;
        else s.insert(p);
        cnt[p]++;
    }
    return ret;
}
void remove(int i) {
    for(int p : factors[a[i]]) {
        cnt[p]--;
        if(!cnt[p]) s.erase(p);
    }
}
int main() {
    SYNC
    cin >> t;
    sieve();
    while(t--) {
        cin >> n; 
        FOR0(i, n) cin >> a[i];
        memset(cnt,0,sizeof cnt);
        ll ans = 0;
        int l = 0, r = 0;
        while(r < n) {
            if(!good[a[r]]) {r++; l = r;
                for(int p : s) cnt[p] = 0;
                s.clear();
                continue;
            }
            if(add(r)) {ans += r-l+1; r++;}
            else {remove(r); remove(l); l++;}
        }
        cout << ans << endl;
    }
}