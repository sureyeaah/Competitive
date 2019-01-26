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
#define N 70005
#define S 10000000
#define M 200000
#define MM (ll)(1e9)
int main() {
    SYNC
    int n;
    string s[N];
    map <ll, int> selfcnt[N];
    map<ll, int> mapcnt;
    cin >> n;
    FOR0(i, n) cin >> s[i];
    FOR0(i, n) {
        FOR0(j, 9) {
            ll curr = MM;
            FOR(k,j,9) {
                int len = k-j+1;
                curr = curr*10 + (s[i][k] - '0');
                mapcnt[curr]++;
                selfcnt[i][curr]++;
            }
        }
    }
    FOR0(i, n) {
        int ansLen = 10, ind;
        FOR0(j, 9) {
            ll cur = 0, curr = MM;
            FOR(k,j,9) {
                int len = k-j+1;
                curr = curr*10 + (s[i][k] - '0');
                if (mapcnt[curr] == selfcnt[i][curr] && len < ansLen) {
                    ansLen = len;
                    ind = j;
                }
            }
        }
        cout << s[i].substr(ind, ansLen) << '\n';
    }
}