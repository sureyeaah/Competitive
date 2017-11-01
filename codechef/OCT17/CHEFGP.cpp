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

int main() {
    SYNC
    int t, x, y; string s;
    cin >> t;
    while(t--) {
        cin >> s >> x >> y;
        int a = 0, b = 0;
        FOR0(i, s.length()) {
            if(s[i] == 'a') a++;
            else b++;
        }
        char A = 'a';
        char B = 'b';
        if(a < b) {
            swap(a, b);
            swap(x, y);
            swap(A, B);
        }
        if(1LL*x*(b+1) >= a) {
            cout << string(a/(b+1), A);
            FOR0(i, b) {
                cout << B;
                cout << string(a/(b+1), A);
                if(a%(b+1) > i) cout << A;
            }
        } else {
            cout << string(x, A);
            a -= x;
            while(b) {
                cout << B;
                cout << string(x, A);
                a -= x; b--;
            }
            while(a > 0) {
                cout << '*';
                cout << string(min(x, a), A);
                a -= x;
            }
        }
        cout << newl;
    }
}