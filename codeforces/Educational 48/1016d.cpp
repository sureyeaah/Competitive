// Gear4        
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define FOR0(i,n) for(int i=0, _##i=(n); i<_##i; ++i)
#define FOR(i,l,r) for(int i=(l), _##i=(r); i<_##i; ++i)
#define FORD(i,l,r) for(int i=(r), _##i=(l); --i>=_##i; )
#define SZ(a) ((int)((a).size()))
#define printCase() "Case #" << caseNum << ": "
#define pb push_back
#define mp make_pair
#define SYNC std::ios::sync_with_stdio(false);  cin.tie(NULL);
#define ff first
#define ss second
template<typename T> using V = vector<T>;
template<typename T, typename U> using P = pair<T,U>;
using ld = long double;
using ll = long long;
#define endl '\n'
const int inf = 1e9, mod = 1e9 + 7;
const ll INF = 9e18;
const ld EPS = 1e-9, PI = acosl(-1.0);
const int N = 105;
int a[N], b[N], ans[N][N];int n, m;
int solve(int k) {
    int aa[N], bb[N];
    FOR0(i, n) aa[i] = (a[i] & (1 << k)) != 0;
    FOR0(i, m) bb[i] = (b[i] & (1 << k)) != 0;
    int r = count(aa, aa + n, 1);
    int c = count(bb, bb + m, 1);
    if((r & 1) != (c & 1)) return 0;
    if(r & 1) {
        FOR0(i, n) {
            FOR0(j, m) {
                if(aa[i] && bb[j]) ans[i][j] |= (1 << k);
            }
        }
    } else if(r && c) {
        int tmp = 1;
        FOR0(i, n) {
            if(aa[i]) {
                FOR0(j, m) {
                    if(bb[j] && tmp) {
                        tmp = 0;
                        continue;
                    }
                    if(bb[j]) ans[i][j] |= (1 << k);
                }
                break;
            }
        }
        tmp = 1;
        FOR0(j, m) {
            if(bb[j]) {
                FOR0(i, n) {
                    if(aa[i] && tmp) {
                        tmp = 0;
                        continue;
                    }
                    if(aa[i]) ans[i][j] |= (1 << k);
                }
                break;
            }
        }
    } else if(r) {
        FOR0(i, n) if(aa[i]) ans[i][0] |= (1 << k);
    } else if(c) {
        FOR0(j, m) if(bb[j]) ans[0][j] |= (1 << k);
    }
    return 1;
}
int main() {
    SYNC
    
    cin >> n >> m;
    FOR0(i, n) cin >> a[i];
    FOR0(j, m) cin >> b[j];
    FOR0(i, 30) if(!solve(i)) {cout << "NO"; return 0;}
    cout << "YES" << endl;
    FOR0(i, n) FOR0(j, m) cout << ans[i][j] << " \n"[j==m-1];
}