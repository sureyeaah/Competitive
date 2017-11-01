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
#define N 100000
bitset<N> bs;
vi primes;
void sieve() {
    bs.set(); bs[0] = bs[1] = 0;
    FOR(i,2,N) {
        if(!bs[i]) continue;
        primes.pb(i);
        for(ll j = 1LL*i*i; j < N; j+=i) {
            bs[j] = 0;
        }
    }
}
unordered_map<string, int> g;
int solve(set<int> & s) {
    if(s.empty()) return 0;
    string str = "";
    for(int elem : s) {
        str.pb('a' + elem);
    }
    // sort(str.begin(), str.end());
    if(g.find(str) != g.end()) return g[str];
    set<int> curG;
    FOR(i,1,1 + *(s.rbegin())) {
        set<int> news;
        for(int x : s) {
            if(x - i > 0) news.insert(x - i);
            else if (x < i) news.insert(x);
        }
        curG.insert(solve(news));
    }
    int ans = 0;
    for(int x : curG) {
        if(ans == x) ans++;
        else break;
    }
    return g[str] = ans;
}
int main() {
    SYNC
    sieve();
    map<int, set<int>> m;
    int n, a;
    cin >> n;
    int ans = 0;
    while(n--) {
        cin >> a;
        for(int p: primes) {
            if(a%p) continue;
            int cnt = 0;
            while(a % p == 0) {
                a/=p; cnt++;
            }
            m[p].insert(cnt);
        }
        if(a > 1) m[a].insert(1);
    }
    for(auto&cur: m) {
        g.clear();
        ans ^= solve(cur.ss);
    }
    cout << (ans ? "Mojtaba": "Arpa");
}