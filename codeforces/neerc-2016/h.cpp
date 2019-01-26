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
const int L = -(1 << 15), R = -L - 1;
int main() {
    freopen("hard.in", "r", stdin);
    freopen("hard.out", "w", stdout);
    string s, x;
    V<P<int, int>> v, out;
    int t = 0;
    while(1) {
        getline(cin, x);
        int a = L, b = R, c = 0;
        istringstream ixx(x);
        while(ixx >> s) {
            if(s == "||") break;
            else if(s[0] == '>') {
                c = 1;
            }
            else if (s[0] == '<') {
                c = 2;
            }
            else if(c==1) {
                istringstream iss(s);
                iss >> a;
                c = 0;
            } else if(c==2) {
                istringstream iss(s);
                iss >> b;
                c = 0;
            }
        }
        if(a <= b) {
            t = 1;
            v.push_back(make_pair(a, b));
        }
        if(x.back() != '|') break;
    }
    if(!t) {
        cout << "false"; return 0;
    }
    sort(v.begin(), v.end());
    int a, b, start = 0;
    FOR0(i, v.size()) {
        auto cur = v[i];
        if(!start) start = 1, a = cur.first, b = cur.second;
        if(cur.first > b+1) {
            out.push_back(make_pair(a, b));
            i--;
            start = 0;
            continue;
        }
        b = max(cur.second, b);
        if(i == v.size()-1) out.push_back(make_pair(a, b));
    }
    FOR0(i, out.size()) {
        int a = out[i].first, b = out[i].second;
        if(a == L && b == R) cout << "true";
        else if(a == L) cout << "x <= " << b;
        else if(b == R) cout << "x >= " << a;
        else cout << "x >= " << a << " && " << "x <= " << b;
        if(i != out.size() - 1) cout << " ||\n";
    }
}