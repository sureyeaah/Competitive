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
    int t, n, a[105];
    cin >> t;
    while(t--) {
        cin >> n;
        int ans = 1;
        FOR0(i, n) {
            cin >> a[i];
        }
        int cur = 1, cnt[20] = {}, dec = 0, val = 1; 
        FOR0(i, n) {
            if (a[i] > 7 || a[i] <= 0) {ans = 0; break;}
            if(a[i] == cur) {;}
            else if(a[i] == cur+1 && !dec) {
                cur++; val++;
            } else if(a[i] == cur-1) {
                if(!dec && cur != 7) {ans = 0; break;}
                else dec = 1;
                cur--;
                val++;
            } else {ans = 0; break;}
            cnt[val]++;
        }
        FOR(i,1,8) if(!cnt[i] || cnt[i] != cnt[14-i]) ans = 0;
        cout << (ans ? "yes": "no") << "\n";
    }
}