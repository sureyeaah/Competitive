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
    int n;
    char x1, x2;
    map<int, int> m;
    m[118] = 0; m[60] = 1; m[94] = 2; m[62] = 3;
    cin >> x1 >> x2 >> n;
    n %= 4;
    int b1 = 0, b2 = 0;
    if((m[(int)x1] + n + 4) % 4 == m[(int)x2]) b1 =1;
    if((m[(int)x2] + n + 4) % 4 == m[(int)x1]) b2 = 1;
    if(b1 && b2) cout << "undefined";
    else if (b1) cout << "cw";
    else cout << "ccw";
}