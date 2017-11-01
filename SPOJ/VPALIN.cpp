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
#define N 6000005
int back[N];
int solve(string& s) {
    s = s + "$" + s + s;
    back[0] = -1;
    int i = 0, j = -1, ret = 0, n = s.length(), m = n/3;
    while(i < n) {
        while(j >= 0 && s[j] != s[i]) j = back[j];
        j++; i++;
        back[i] = j;
        if(j == m) {
            j = back[j];
            ret++;
        }
    }
    return m/(ret-1);
}
int main() {
    SYNC
    int n, tmp;
    cin >> n;
    string s;
    unordered_map<string, int> m;
    FOR0(i, n) {
        cin >> tmp >> s;
        int x = solve(s);
        m[s.substr(0,x)]++;
    }
    ll ans = 0;
    for(auto& cur : m) {
        ans += 1LL*cur.ss*cur.ss;
    }
    cout << ans;
}