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
    int t, n, m;
    cin >> t;
    while(t--) {
        cin >> n >> m;
        int ans = 0;
        for(int i = 2; i <= min(n,m); i += 2) {
            if((m-i) % 4 || m-i > ((n-i-1)/2)*2*i) continue;
            ans = 1;
            FOR(l,1,i+1) cout << l << " " << i + 1 << '\n';
            int j = i + 2; m -= i;
            while(m) {
                for(int l = 1; l <= i; l += 2) {
                    cout << l << " " << j << endl;
                    cout << l << " " << j+1 << endl;
                    cout << l+1 << " " << j << endl;
                    cout << l+1 << " " << j+1 << endl;
                    m -= 4;
                    if(!m) break;
                }
                j += 2;
            }
            break;
        }
        if(!ans) cout << "-1" << endl;
    }
}