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
int n, p[105];
struct matrix {
    int mat[2][2];
    matrix() {
        memset(mat, 0, sizeof mat);
    };
};
// id.mat[0][0] = id.mat[1][1] = 1;
// // id.mat[0][1] = id.mat[1][0] = 0;
// base.mat[0][0] = base.mat[0][1] = base.mat[1][1] = 1;
// // base.mat[0][0] = 0;
matrix mult(matrix a, matrix b, int p) {
    matrix res;
    FOR0(i, 2) {
        FOR0(j, 2) {
            FOR0(k, 2) {
                res.mat[i][j] += (int)((1LL * a.mat[i][k] * b.mat[k][j]) % p);
                res.mat[i][j] %= p;
            }
        }
    }
    return res;
}
matrix modexp(matrix a, int b, int p) {
    matrix res;
    res.mat[0][0] = res.mat[1][1] = 1;
    for(;b;b>>=1) {
        if(b&1)
            res = mult(res, a, p);
        a = mult(a,a,p);
    }
    return res;
}
bool valid(int x, int p) {
    matrix base;
    base.mat[0][0] = base.mat[0][1] = base.mat[1][0] = 1;
    return (modexp(base, x-1, p).mat[0][0] % p == 0);
}
int solve(int x, int p) {
    int ans = 2e9;
    if(p == 5) return 5;
    for(int i = 1; 1LL*i*i <= x; i++) {
        if(x%i == 0) {
            if(valid(i, p)) {
                ans = i;
                break;
            } else if(valid(x/i, p)) {
                ans = x/i;
            }
        }
    }
    return ans;
}
int main() {
    SYNC
    valid(5, mod);
    int n;
    cin >> n;
    FOR0(i, n) {
        cin >> p[i];
        cout << min(solve(p[i]-1, p[i]), solve(p[i]+1, p[i])) << newl;
    }
}