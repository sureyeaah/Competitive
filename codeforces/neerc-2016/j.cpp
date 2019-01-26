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
const int N = 5000 + 5; int n, w, h, m, l, k, x[N][2], lt[N], rt[N];
ll cnt[N];
bitset<10005> rem[N];
void update(int l) {
    while(rem[l][lt[l]] && lt[l] <= n) lt[l]++;
    while(rem[l][rt[l]] && rt[l]) rt[l]--;
}
int main() {
    SYNC
    cin >> n >> w >> h >> m;
    FOR(i, 1, h + 1) lt[i] = 1, rt[i] = n;
    FOR0(i, m) {
        cin >> l >> k;
        rem[l][k] = 1;
        update(l);
        FOR(j, 1, l + 1) {
            x[j][l&1] += 2*k - 1;
            x[j][(l&1)^1] += n;
            cnt[j]++;
        }
        int t=0;
        FORD(j, 1, h + 1) {if(rt[j]) t = j; break;}
        FORD(j, 1, t - 1) {
            if(!rt[j]) {
                cout << "yes" << endl << i + 1;
                return 0;
            }
            P<int, int> bound[2];
            bound[j & 1] = {(lt[j] - 1) * 2, rt[j] * 2};
            bound[(j & 1) ^ 1] = {0, 2*n};
            ll tot = n * (h - j);
            FOR0(k, 2) {
                if((tot * n - x[j+1][k]) <= (tot - cnt[j+1]) * (bound[k].ff) ||
                (tot * n - x[j+1][k]) >= (tot - cnt[j+1]) * (bound[k].ss)
                )
                    {
                        cout << "yes" << endl << i + 1;
                        return 0;
                    }
            }
        }
    }
    cout << "no";
}