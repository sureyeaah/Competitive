// Gear4        
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define FOR0(i,n) for(int i=0, _##i=(n); i<_##i; ++i)
#define FOR(i,l,r) for(int i=(l), _##i=(r); i<_##i; ++i)
#define FORD(i,l,r) for(int i=(r), _##i=(l); --i>=_##i; )
#define SZ(a) ((int)((a).size()))
#define printCase() "Case #" << caseNum << ": "
#define pb push_back
#define mp make_pair
#define SYNC std::ios::sync_with_stdio(false);  cin.tie(NULL);
#define ff first
#define ss second
template<typename T> using V = vector<T>;
template<typename T, typename U> using P = pair<T,U>;
using ld = long double;
using ll = long long;
#define endl '\n'
const int inf = 1e9, mod = 1e9 + 7;
const ll INF = 9e18;
const ld EPS = 1e-9, PI = acosl(-1.0);

int main() {
    SYNC
    int n;
    cin >> n;
    map<P<string, int>, vector<int>> m;
    FOR0(i, n) {
        string s, t;
        cin >> s >> t;
        int x = 0;
        for(char c : t) x |= 1 << (c - 'a');
        while(!s.empty() && (x & (1 << (s.back() - 'a'))) ) s.pop_back();
        m[make_pair(s, x)].push_back(i+1);
    }
    cout << m.size() << endl;
    for(auto& cur: m) {
        cout << cur.ss.size() << ' ';
        for(int x: cur.ss) cout << x << ' ';
        cout << endl;
    }
}