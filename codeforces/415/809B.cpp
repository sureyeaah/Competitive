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
#define EPS (1e-9)
#define PI 3.1415926535
#define inf ((int)1e9)
#define INF ((ll)9e18)
#define mod (1000000000 + 7)
#define SYNC std::ios::sync_with_stdio(false);  cin.tie(NULL);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<vi> vvi;
int query(int x, int y) {
    cout << 1 << " " << x << " " << y << endl;
    string s;
    cin >> s;
    return (s[0] == 'T');
}
int search(int l, int r) {
    if(l > r) return -1;
    while(l < r) {
        int mid = (l + r) >> 1;
        if(query(mid, mid+1))
            r = mid;
        else l = 1 + mid;
    }
    return l;
}
int main() {
    int n, k;
    cin >> n >> k;
    int x = search(1, n);
    int y = search(1,x-1), z = search(x+1,n);
    if(y == -1 || (z!=-1 && !query(y, z)))
        y = z;
    cout << 2 << " " << x << " " << y << endl;
}