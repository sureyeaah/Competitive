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
#define N 105
int main() {
    SYNC
    int n, a[N][N], b[N][N];
    int ans = 2;
    cin >> n;
    FOR0(i, n) {
        FOR0(j, n) {
            cin >> a[i][j];
        }
    }
    FOR0(i, n) {
        FOR0(j, n) {
            cin >> b[i][j];
        }
    }
    FOR0(i, n) {
        FOR0(j, n) {
            if(a[i][j] != b[n-i-1][j]) {
                ans--; i = INF; break;
            }
        }
    }
    FOR0(i, n) {
        FOR0(j, n) {
            if(a[i][j] != b[i][n-1-j]) {
                ans--; i = INF; break;
            }
        }
    }
    cout << (ans ? 1: 0);
}