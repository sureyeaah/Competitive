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
    int k, n, op[30] = {}, cl[30] = {};
    char x;
    cin >> n >> k;
    int cur = 0;
    memset(op,63,sizeof op);
    FOR0(i, n) {
        cin >> x;
        int val = x - 'A';
        op[val] = min(op[val], i + 1);
        cl[val] = max(cl[val], i + 1);
    }
    int ans = 0;
    FOR(i,1,n+1) {
        FOR0(j, 26) if(op[j] == i) cur ++;
        if(cur > k) {
            ans = 1;
        }
        FOR0(j, 26) if(cl[j] == i) cur--;
    }
    cout << (ans ? "YES": "NO") << '\n';
}