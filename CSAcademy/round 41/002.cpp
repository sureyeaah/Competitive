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
#define N 100005
int main() {
    SYNC
    int n = 0, lt[N] = {}, rt[N] = {}; char x;
    bitset<N> bs;
    while(cin >> x) {
        bs[n+1] = x - '0';
        n++;
    }
    int ans = 0;
    lt[1] = 1; rt[n] = n;
    FOR(i, 2, n+1) {
        if(bs[i]) {
            lt[i] = 0;  continue;
        }
        lt[i] = bs[i-1] ? i : lt[i-1];
    }
    FORD(i,1,n) {
        if(bs[i]) {
            rt[i] = 0;  continue;
        }
        rt[i] = bs[i+1] ? i : rt[i+1];
        if(!bs[i]) ans = max(ans, rt[i] - lt[i] + 1);
    }
    FOR(i,1,n+1) {
        if(bs[i]) {
            int l = i > 1 && !bs[i-1] ? rt[i-1] - lt[i-1] + 1 : 0;
            int r = i < n && !bs[i+1] ? rt[i+1] - lt[i+1] + 1 : 0;
            ans = max(ans, r + l + (n-(int)bs.count() != r + l));
        }
    }
    cout << ans;
}