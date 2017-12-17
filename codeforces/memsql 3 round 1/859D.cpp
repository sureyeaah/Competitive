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
const int N = 6 + 1;
int n, table[1 << N][1 << N];
long double e[N + 10][1 << N], prob[N+10][1 << N];
void solve(int p, int l, int r, int point) {
    if(l == r) {
        prob[p][l] = 1;
        e[p][l] = 0;
        return;
    }
    int mid = (l + r) >> 1;
    solve(p + 1, l, mid, point >> 1);
    solve(p + 1, mid + 1, r, point >> 1);
    FOR(i, l, mid + 1) {
        prob[p][i] = 0;
        FOR(j, mid + 1, r + 1) {
            prob[p][i] += prob[p + 1][i] * prob[p+1][j] * table[i][j]/100.0;
        }
    }
    FOR(i, mid + 1, r + 1) {
        prob[p][i] = 0;
        FOR(j, l, mid + 1) {
            prob[p][i] += prob[p + 1][i] * prob[p+1][j] * table[i][j]/100.0;
        }
    }
    FOR(i, l, mid + 1) {
        FOR(j, mid + 1, r + 1) {
            e[p][i] = max(e[p][i], e[p+1][i] + e[p+1][j] + (point * prob[p][i]));
        }
    }
    FOR(i, mid + 1, r + 1) {
        FOR(j, l, mid + 1) {
            e[p][i] = max(e[p][i], e[p+1][i] + e[p+1][j] + (point * prob[p][i]));
        }
    }
}
int main() {
    SYNC
    cin >> n;
    FOR0(i, 1 << n) {
        FOR0(j, 1 << n) {
            cin >> table[i + 1][j + 1];
        }
    }
    FOR0(i, N+10) FOR0(j, 1 << N) e[i][j] = 0;
    solve(0, 1, (1 << n), 1 << (n - 1));
    cout << fixed << setprecision(11) << *max_element(e[0] + 1, e[0] + (1 << n) + 1) << endl;
}