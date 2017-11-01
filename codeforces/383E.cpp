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
#define N 24
int main() {
    SYNC
    int n, f[3][1 << N] = {};
    cin >> n;
    string s;
    FOR0(j, n) {
        cin >> s;
        int cur = 0;
        FOR0(i, 3) f[0][1 << (s[i]-'a')]++;
        FOR0(i, 3) cur |= 1 << (s[i]-'a');
        FOR0(i, 3) f[1][(1 << (s[(i+1)%3]-'a')) | (1 << (s[(i+2)%3]-'a'))]++;
        f[2][cur]++;
    }
    FOR0(k, 3) {
        FOR0(i, N) {
            FOR0(j, 1 << N) {
                if(j & (1 << i)) f[k][j] += f[k][j^(1 << i)];
            }
        }
    }
    int ans = 0;
    FOR0(i, 1 << N) {
        ll x = f[0][i] + f[2][i] - f[1][i];
        ans ^= (x*x);
    }
    // int ans = accumulate(f, f + (1 << N), 0, [&](int lhs, int rhs) {return lhs^(rhs*rhs);});
    cout << ans;
}