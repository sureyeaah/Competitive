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
#define val(i, j) (i >= 0 && j >= 0 && i < n && j < n ? g[i][j]: 0)
bitset<500> isPrime;
int main() {
    SYNC
    isPrime.set();
    isPrime[0] = isPrime[1] = 0;
    FOR(i, 2, 500) {
        if(!isPrime[i]) continue;
        for(int j = i*i; j < 500; j += i) isPrime[j] = 0;
    }
    int n, g[101][101], dx[4] = {0,1,0,-1}, dy[4] = {1,0,-1,0};
    cin >> n;
    FOR0(i, n) {
        FOR0(j, n) {
            cin >> g[i][j];
        }
    }
    int ans = 0;
    FOR0(i, n) {
        FOR0(j, n) {
            int cur = 0;
            FOR0(a, 4) cur += val((i + dx[a]), (j + dy[a]));
            if(isPrime[cur]) ans++;
        }
    }
    cout << ans;
}