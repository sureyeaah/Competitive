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
const int N = 1e5 + 5;
int n, m, tot = 0;
V<V<int>> b(N);
V<V<int>> toy(N);
unordered_set<int> toyset[N];
V<int> ind(N);
V<int> gt(N, -1), a(N);
int main() {
    SYNC
    cin >> n >> m;
    FOR0(i, n) {
        int s; cin >> s;
        FOR0(j, s) {
            int x; cin >> x;
            b[i].push_back(x);
            tot++;
        }
    }
    V<int> v;
    FOR0(i, n) v.push_back(i);
    sort(v.begin(), v.end(), [&](int l, int r) {return b[l].size() > b[r].size();});
    FOR0(i, n) ind[v[i]] = i; // ind: gives original index
    priority_queue<P<int, int>, V<P<int, int>>, greater<P<int, int>>> minh;
    priority_queue<P<int, int>> maxh;
    FOR0(i, n) minh.push({b[ind[i]].size(), -i});
    FOR0(i, n) maxh.push({b[ind[i]].size(), -i});
    int k = inf, k2 = -1;
    FOR0(i, n) a[i] = b[ind[i]].size();
    while((!maxh.empty() && !minh.empty()) && maxh.top().ff - minh.top().ff > 1) {
        auto mx = maxh.top(); if(gt[-mx.ss] == 0) {maxh.pop(); continue;}
        auto mn = minh.top(); if(gt[-mn.ss] == 1) {minh.pop(); continue;}
        minh.pop();
        maxh.pop();
        gt[-mx.ss] = 1;
        gt[-mn.ss] = 0;
        mx.ff--; mn.ff++;
        maxh.push(mx); minh.push(mn);
    }
    V<int> final(N);
    while(!maxh.empty()) {
        auto cur = maxh.top(); maxh.pop();
        if(gt[-cur.ss]==1) final[-cur.ss] = cur.ff;
    }
    while(!minh.empty()) {
        auto cur = minh.top(); minh.pop();
        if(!gt[-cur.ss]) final[-cur.ss] = cur.ff;
    }
    unordered_set<int> takers;
    FOR0(i, n) {
        if(!gt[i] && a[i] != final[i]) takers.insert(i);
        for(int t : b[ind[i]]) {
            if(gt[i]==1) toy[t].push_back(i);
             toyset[t].insert(i);
        }
    }
    V<P<P<int, int>, int>> output;
    FOR(i, 1, m + 1) {
        int l = 0;
        V<int> rem;
        for(int t: takers) {
            int box;
            while(l < toy[i].size()) {
                box = toy[i][l]; // giver
                if(a[box] != final[box]) break;
                l++;
            }
            if(l == toy[i].size()) break;
            if(toyset[i].find(t) != toyset[i].end()) continue;
            a[t]++; a[box]--;
            if(a[t] == final[t]) rem.push_back(t);
            output.push_back({{box, t}, i});
            l++;
        }
        for(int x : rem) takers.erase(x);
    }
    cout << output.size() << endl;
    for(auto cur : output) {
        cout << ind[cur.ff.ff]+1 << " " << ind[cur.ff.ss]+1 << " " << cur.ss << endl;
    }
}