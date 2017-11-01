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
#define N 500005
int n, start, x, nxt[N] = {}, val[N] = {};
bitset<N> done;
void query(int x) {
    cout << "? " << x << endl;
    cin >> val[x] >> nxt[x];
}
int main() {
    std::srand(std::time(0));
    cin >> n >> start >> x;
    int ans = 2*INF + 1, l = start;
    FOR0(i, 1998) {
        int cur = start;
        if(done.count()==n) break;
        while(done[cur]) {
            cur = 1 + (((1LL * rand() << 15) + rand()) % n);
        }
        query(cur); done[cur] = 1;
        if(val[cur] >= x) {
            ans = min(ans, val[cur]);
            if(nxt[cur] != -1) done[nxt[cur]] = 1;
        }
        else {
            if(val[cur] > val[l] || val[l] > x) {
                l = cur;
            }
        }
    }
    if(nxt[l] != -1 && !val[nxt[l]] && !done[nxt[l]]) {
        query(nxt[l]);
        if(val[nxt[l]] >= x) ans = min(ans, val[nxt[l]]);
    }
    cout << "! " << (ans > INF+1 ? -1 : ans) << endl;
    return 0;
}