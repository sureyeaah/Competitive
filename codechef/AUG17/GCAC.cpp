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
#define N 1005
int main() {
    SYNC
    int t, n, m, salary[N], qual[N][N], off[N], cnt[N], comp[N], done[N]; char x;
    cin >> t;
    while(t--) {
        ll tot = 0; int nojob = 0, job = 0;
        cin >> n >> m;
        memset(done, 0, sizeof done);
        FOR0(i, n) cin >> salary[i];
        FOR0(i, m) cin >> off[i] >> cnt[i];
        FOR0(i, n) FOR0(j, m) {
            cin >> x;
            qual[i][j] = x - '0';
        }
        FOR0(i, m) comp[i] = i;
        sort(comp, comp + m, [&](const int& l, const int& r) {return off[l] > off[r];});
        FOR0(i, n) {
            int cur = -1;
            FOR0(j, m) {
                int c = comp[j];
                if(qual[i][c] && done[c] < cnt[c] && off[c] >= salary[i]) {
                    cur = c;
                    break;
                }
            }
            if(cur != -1) {
                job++;
                tot += off[cur];
                done[cur]++;
            }
        }
        FOR0(i, m) if(!done[i]) nojob++;
        cout << job << " " << tot << " " << nojob << '\n';
    }
}