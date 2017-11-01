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
const int n = 2000;

//bitset<2005> lose[2005];
int pre[2005][2005];
int main() {
    SYNC
    FOR(sum,1,n+1) {
        FOR(i,1,sum+1) {
            int last = sum - i, k = last ? min(2*last, i): i - 1;
            if(k > 0) pre[sum][i] = pre[sum][i-1] + (pre[i][i-1] - (i-k-1 >= 0 ? pre[i][i-k-1]: 0) < k);
        }
    }
    FOR(i,2,n+1) if(pre[i][i]-pre[i][i-1] == 0) cout << i << '\n';
}