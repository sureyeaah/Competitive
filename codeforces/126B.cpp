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
const int N = 1e6 + 6;
int n, z[N], l = 0, r = 0;
string s;
int main() {
    SYNC
    cin >> s; n = s.length();
    int suf = 0, mid = 0;
    FOR(i, 1, n) {
        if(i > r) {
            l = r = i;
            while(r < n && s[r-l] == s[r]) r++;
            z[i] = r - l; r--;
        } else {
            int k = i - l;
            if(z[k] < r - i + 1) z[i] = z[k];
            else {
                l = i;
                while(r < n && s[r-l] == s[r]) r++;
                z[i] = r - l; r--;
            }
        }
        if(i + z[i] < n) mid = max(mid, z[i]);
        else if(i + z[i] == n) mid = max(mid, z[i] - 1);
    }
    FOR(i, 1, n) {
        if(i + z[i] == n && z[i] <= mid) suf = max(suf, z[i]);
    }
    if(suf) cout << s.substr(0, suf);
    else cout << "Just a legend";
}