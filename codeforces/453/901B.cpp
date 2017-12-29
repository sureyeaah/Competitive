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
#define newl '\n'
#define SYNC std::ios::sync_with_stdio(false);  cin.tie(NULL);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<vi> vvi;
int n;
vi add(vi& a, vi& b) {
    vi ret(max(SZ(a), SZ(b)), 0);
    FOR0(i, SZ(a)) ret[i] += a[i];
    FOR0(i, SZ(b)) ret[i] += b[i];
    return ret;
}
int valid(vi& v) {
    for(int x : v) if(abs(x) > 1) return 0;
    return 1;
}
int main() {
    SYNC
    cin >> n;
    vi a({1}), b({0});
    while(SZ(a) < n + 1) {
        a.insert(a.begin(), 0);
        vi p = add(a,b);
        // for(int x : a) cout << x << " ";cout << endl;
        if(!valid(p)) {
            transform(b.begin(), b.end(), b.begin(), [&](int x) {return -x;});
            p=add(a,b);
        }
        b=a; a=p;
        b.erase(b.begin());
    }
    cout << SZ(a)-1 << newl;
    for(int x : a)
        cout << x << " ";
    cout << endl;
    cout << SZ(b)-1 << newl;
    for(int x : b) 
        cout << x << " ";
}