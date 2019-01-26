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
const int N = 1.5e5;
int n;
int main() {
    SYNC
    cin >> n;
    map<int, int> c;
    V<P<int, int>> x, y;
    FOR(i, 1, n + 1) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        x.push_back(make_pair(x1, -i));
        x.push_back(make_pair(x2, i));
        y.push_back(make_pair(y1, -i));
        y.push_back(make_pair(y2, i));
    }
    sort(x.begin(), x.end());
    sort(y.begin(), y.end());
    set<int> s;
    int ansx=-1, ansy=-1;
    FOR0(i, n) s.insert(i+1);
    for(auto cur : x) {
        if(cur.second < 0) {
            s.erase(-cur.second);
            if(s.size() <= 1) ansx = cur.first;
        } else {
            if(s.size() <= 1) ansx = cur.first;
            s.insert(cur.second);
        }
    }
    s.clear();
    x = y;
    FOR0(i, n) s.insert(i+1);
    for(auto cur : x) {

        if(cur.second < 0) {
            s.erase(-cur.second);
            if(s.size() <= 1) ansy = cur.first;
        } else {
            if(s.size() <= 1) ansy = cur.first;
            s.insert(cur.second);
        }
    }
    cout << ansx << " " << ansy;
}