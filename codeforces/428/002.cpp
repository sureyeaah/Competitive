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
    int n, k, a[101], b[3], odd = 0, four = 0, two = 0, left;
    cin >> n >> k;
    b[0] = n*2;  b[1] = b[2] = n;
    FOR0(i, k) cin >> a[i];
    FOR0(i, k) {
        if(a[i]%2) {
            odd++;
            a[i] ^= 1;
        }
        four += a[i]/4;
        a[i] -= 4*(a[i]/4);
        two += a[i]/2;
    }
    if(odd > n) {
        b[2] = 0;
        odd -= n;
        if(odd <= n) b[1] -= odd;
        else {
            odd -= n;
            b[1] = 0;
            if(odd <= b[0]) b[0] -= odd;
            else {
                cout << "NO";
                return 0;
            }
        }
    } else {
        b[2] -= odd;
    }
    // left = n - b[2] - (n - b[1]);
    int x = min(four, (b[1], b[2]));
    b[1] -= x; b[2] -= x; four -= x;
    two += four*2;
    int y = b[0] + b[1] + b[2]/2;
    cout << ((two <= y) ? "YES": "NO");
}