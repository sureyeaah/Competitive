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
#define X 1000005
int n, q, x;
ll a;
int cnt[X]={}, num[X];
bitset<X> poss, p, have;
void sieve() {
    p.set(); p[0] = p[1] = 0;
    FOR0(i, X) num[i] = i;
    for(int i = 2; i < X; i++) {
        if(!p[i]) continue;
        for(int j = i; j < X; j+=i) {
            cnt[j]++; p[j] = 0; num[j] /= i;
        }
        if((ll(i))*(ll(i)) < X) {cnt[i*i] = 2; num[i*i] = 1;}
    }
    FOR(i,2,X) if(cnt[i] == 2 && num[i] == 1) {
        poss[i] = 1;
        for(int j = 2*i; j < X; j+=i) {
            if(j/i < X && have[j/i]) poss[j] = 1; 
        }
    }
}
int main() {
    SYNC
    cin >> n >> q;
    FOR0(i, n) {
        cin >> a;
        if(have[a] || a<=1) continue;
        ll b = a;
        while(b < X) {have[b] = 1; b *= a;}
    }
    sieve();
    while(q--) {
        cin >> x;
        cout << (poss[x] ? "YES\n": "NO\n");
    }
}