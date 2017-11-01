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
#define N 1005
int n, a[N << 1];

bool check(int x) {
    multiset<int> s;
    vi output;
    FOR0(i, n + n) s.insert(a[i]);
    FOR0(i, n) {
        int z = *(s.begin());
        auto it = s.find(z + x);
        if(it == s.end()) return false;
        output.pb(*it);
        s.erase(it);
        s.erase(s.begin());
    }
    cout << x << endl;
    for(int z : output) cout << z << " ";
    return true;
}
int main() {
    SYNC
    
    cin >> n;
    FOR0(i, n << 1) cin >> a[i];
    sort(a, a + n + n);
    FOR(i, 1, n+1) {
        int x = a[i] - a[0];
        if(x == 0) continue;
        if(check(x)) {
            return 0;
        }
    }
    cout << -1;
}