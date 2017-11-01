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
#define N 160
#define mod (7 + (int)1e9)
#define add(x,y) (((x)+(y))%mod)
int main() {
    SYNC
    int t, n, a[N] = {}, sum[2][N][N] = {};
    cin >> t;
    while(t--) {
        cin >> n;
        memset(a, 0, sizeof a);
        memset(sum, 0, sizeof sum);
        FOR0(i, n) cin >> a[i];
        sum[1][0][0] = 1;
        n += 105;
        FOR0(i,n) {
            int ind = (i&1);
            memset(sum[ind], 0, sizeof sum[ind]);
            FOR(j,a[i],N) {
                FOR0(k, N) {
                    if(k-j+a[i] >= 0 && k-j+a[i] < N)
                        sum [ind] [j] [k - j + a[i]] = sum[!ind] [ k ] [ j-a[i] ];
                }
                FORD(k, 0, N-1)
                    sum[ind][j][k] = add(sum[ind][j][k], sum[ind][j][k+1]);
            }
        }
        cout << sum[0][0][0] << endl;
    }
}