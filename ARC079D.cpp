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
ll k, a[55] = {};
#define A ((ll)1e16+1000)
int main() {
    SYNC
    FOR(n,2,51) {
        ll done = 0;
        FOR0(i, n - 1) {
            a[i] = max(0LL, n-k-1);
            done += (a[i] + k - n )/ (n + 1) + 1;
        }
        if(done <= k) {
            a[n-1] = (k - done) - k - 1 + n;
        }
        if(a[n-1] <= A && a[n-1] >= 0) 
            cout << n << endl;
            FOR0(i, n) cout << a[i] << " ";
            return 0;

    }
}