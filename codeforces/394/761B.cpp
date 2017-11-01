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
    int n, l, a[55], b[55], curr, prev;
    cin >> n >> l;
    prev = 0;
    FOR0(i, n) {
        scanf("%d", &curr);
        a[i] = curr - prev;
        prev = curr;
    }
    a[n] = l - prev + a[0];
    prev = 0;
    FOR0(i, n) {
        scanf("%d", &curr);
        b[i] = curr - prev;
        prev = curr;
    }
    b[n] = l - prev + b[0];
    bool same = false;
    FOR(s2, 1, n+1) {
        if(a[1] == b[s2]) {
            same = true;
            FOR(i, s2+1, n+1) {
                if(a[i - s2 + 1] != b[i]) {same = false; break;}
            }
            FOR(i, 1, s2) {
                if(a[n - s2 + 1 + i] != b[i]) {same = false; break;}
            }
            if(same) break;
        }
    }
    if(same) cout << "YES" << endl;
    else if(!same) cout << "NO" << endl;
}