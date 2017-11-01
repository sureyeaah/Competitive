#include <bits/stdc++.h>
using namespace std;
#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define FOR0(i,n) for(int i=0, _##i=(n); i<_##i; ++i)
#define FOR(i,l,r) for(int i=(l), _##i=(r); i<_##i; ++i)
#define FORD(i,l,r) for(int i=(r), _##i=(l); --i>=_##i; )
#define repi(i,a) for(__typeof((a).begin()) i=(a).begin(), _##i=(a).end(); i!=_##i; ++i)
#define dwni(i,a) for(__typeof((a).rbegin()) i=(a).rbegin(), _##i=(a).rend(); i!=_##i; ++i)
#define pb push_back
#define mp make_pair
#define INF (int)1e9
#define EPS 1e-9
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<vi> vvi;

int main() {
    int n, len[100000 + 10];
    scanf("%d", &n);
    FOR0(i, n) scanf("%d", len + i);
    sort(len, len + n);
    bool possible = false;
    for(int i = n-1; i > 0; i--) {
        int curr_diff = len[i] - len[i-1];
        int lhs = upper_bound(len, len + i - 1, curr_diff) - len;
        if(lhs < i - 1){
            possible = true;
            break;
        }
    }
    if(possible) cout << "YES" << endl;
    else cout << "NO" << endl;
}