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
#define mod (1000000007)
struct matrix {
    ll mat[4][4] = {};
};
matrix mult(matrix a, matrix b) {
    matrix ans;
    FOR0(i, 4) FOR0(j, 4) {
        ans.mat[i][j] = 0;
        FOR0(k, 4) ans.mat[i][j] = (ans.mat[i][j] + (a.mat[i][k] * b.mat[k][j]) % mod) % mod;
    }
    return ans;
}
ll matpow(matrix base, int p) {
    matrix ans;
    FOR0(i, 4) FOR0(j, 4) ans.mat[i][j] = (i == j);
    while(p) {
        if(p & 1) ans = mult(ans, base);
        base = mult(base, base);
        p >>= 1;
    } 
    return (ans.mat[0][0] + ans.mat[0][3]) % mod;
}
int main() {
    SYNC
    matrix A;
    A.mat[0][0] = 4; A.mat[0][1] = -4+mod; A.mat[0][2] = A.mat[0][3] = A.mat[1][0] = A.mat[2][1] = A.mat[3][3] = 1;
    int t, n;
    cin >> t;
    while(t--) {
        cin >> n;
        if(n < 3) cout << n-1 << '\n';
        else {
            cout << matpow(A, n - 2) << '\n';
        }
    }
}