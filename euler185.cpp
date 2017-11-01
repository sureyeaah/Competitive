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
#define N 25
int correct(string &a, string &b) {
    int ans = 0;
    FOR0(i, a.length()) {
        if(a[i] == b[i]) ans++;
    }
    return ans;
}
int main() {
    SYNC
    srand(time(NULL));
    int n, c[N], no[12][10];
    bitset<12> done;
    string g[N], ans;
    cin >> n;
    FOR0(i, n) {
        cin >> g[i] >> c[i];
    }
    FOR0(i, n) {
        FOR0(j, n-1) {
            if(c[j] < c[j+1]) {
                swap(c[j], c[j+1]);
                swap(g[j], g[j+1]);
            }
        }
    }
    while(1) {
        done.reset();
        memset(no, 0, sizeof no);
        int cnt = 0;
        ans = string(12,'.');
        FOR0(i, n) {
            int fix = correct(ans, g[i]);
            if(fix > c[i]) break;
            while(fix < c[i]) {
                int nxt = rand() % 12;
                if(done[nxt] || no[nxt][g[i][nxt] - '0']) continue;
                ans[nxt] = g[i][nxt];
                done[nxt] = 1;
                fix++;
            }
            FOR0(j, 12) {
                if(!done[j]) {
                    no[j][g[i][j] - '0']++;
                }
            }
            cnt++;
        }
        if(cnt == n) break;
    }
    cout << ans;
}