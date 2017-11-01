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
bool check(ll x) {
    char ans;
    cout << "? " << x << endl;
    fflush(stdout);
    cin >> ans;
    return (ans == 'Y');
}
int main() {
    ll n = 1;
    while(1) {
        if(!check(n)) break;
        n *= 10;
        if(n > (ll)1e10) {
            ll z = 1;
            while(n) {
                if(!check(n+1)) {
                    z = n*10;
                    break;
                }
                else n/= 10;
            }
            cout << "! " << z << endl;
            return 0;
        }
    }
    ll r = n*10 - 1, l = n-1;
    while(l < r) {
        ll mid = (l+r) >> 1;
        if(check(mid)) {
            n = mid; r = mid - 1;
        } else l = mid + 1;
    }
    cout << "! " << n/10 << endl;
    fflush(stdout);
    return 0;
}