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

int main() {
    SYNC
    int t, mini, maxi, mean, med;
    cin >> t;
    FOR(caseNum,1,t+1) {
        cin >> mini >> maxi >> mean >> med;
        int ans = INF;
        if(maxi == mini && maxi == med && maxi == mean) ans = 1;
        else if(mean*2 == maxi+mini && med == mean) ans = 2;
        FOR(i,3,15) {
            if(i%2 == 1) {
                if((i/2)*(mini + med) + maxi <= i*mean && mini + maxi*(i/2) + (i/2)*med >= mean*i) {ans = min(ans, i); break;}
            } else {
                FOR(j,1,med+1) {
                    int med2 = 2*med - j;
                    if(med2 < j || j < mini || med2 > maxi) continue;
                    if((i/2-1)*(mini + med2) + j + maxi <= i*mean && mini + (maxi+j)*(i/2-1) + med2 >= mean*i) {ans = min(ans, i); i = INF; break;}
                }
            }
        }
        if(med < mini || med > maxi || mini > maxi) ans = INF;
        cout << printCase();
        if(ans < INF) cout << ans << '\n';
        else cout << "IMPOSSIBLE\n";
    }
}