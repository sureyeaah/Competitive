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
#define N 100005
int toNum(string& s) {
    int ret = 0;
    FOR0(i, s.length()) {
        if(s[i] < '0' || s[i] > '9') return -1;
        ret = ret*10 + s[i] - '0';
        if(!ret) return -1;
    }
    return ret;
}
int main() {
    SYNC
    int n, e = 0, type[N], num[N];
    string s[n];
    bitset<N> done, occ;
    cin >> n;
    FOR0(i,n) {
        cin >> s[i] >> type[i];
        e += type[i];
        num[i] = toNum(s[i]);
    }
    set<int> avail[2];
    set<ii> other;
    vector<pair<string, string>> out;
    FOR0(i, n) {
        if(type[i]) {
            if(num[i] == -1 || num[i] > n) continue;
            if(num[i] <= e) done[num[i]] = 1;
            else {
                other.insert(mp(1, i));
                occ[num[i]] = 1;
            }
        } else {
            if(num[i] == -1 || num[i] > n) continue;
            if(num[i] > e) done[num[i]] = 1;
            else {
                other.insert(mp(0, i));
                occ[num[i]] = 1;
            }
        }
    }
    FOR(i,1,e+1) if(!done[i] && !occ[i]) avail[1].insert(i);
    FOR(i,e+1,n+1) if(!done[i] && !occ[i]) avail[0].insert(i);
    int change = true;
    while(other.size() && change) {
        change = false;
        ii cur;
        cur = *(other.begin());
        if(avail[!cur.ff].size()) {
            out.pb(mp(to_string(num[cur.ss]),to_string(*avail[!cur.ff].begin())));
            change = true;
            done[*avail[!cur.ff].begin()] = 1;
            avail[!cur.ff].erase(avail[!cur.ff].begin());
            other.erase(other.begin());
        }
    }
    change = true;
    while(other.size() && change) {
        change = false;
        ii cur;
        cur = *(other.rbegin());
        if(avail[!cur.ff].size()) {
            out.pb(mp(to_string(num[cur.ss]),to_string(*avail[!cur.ff].begin())));
            change = true;
            done[*avail[!cur.ff].begin()] = 1;
            avail[!cur.ff].erase(avail[!cur.ff].begin());
            other.erase(*other.rbegin());
        }
    }
    if(other.size()) {
        while(other.size() && change) {
            while(other.size() && change) {
                change = false;
                ii cur;
                cur = *(other.begin());
                if(avail[!cur.ff].size()) {
                    out.pb(mp(to_string(num[cur.ss]),to_string(*avail[!cur.ff].begin())));
                    change = true;
                    done[*avail[!cur.ff].begin()] = 1;
                    avail[!cur.ff].erase(avail[!cur.ff].begin());
                    other.erase(other.begin());
                }
            }
            if(change) continue;
            change = true;
            while(other.size() && change) {
                change = false;
                ii cur;
                cur = *(other.rbegin());
                if(avail[!cur.ff].size()) {
                    out.pb(mp(to_string(num[cur.ss]),to_string(*avail[!cur.ff].begin())));
                    change = true;
                    done[*avail[!cur.ff].begin()] = 1;
                    avail[!cur.ff].erase(avail[!cur.ff].begin());
                    other.erase(*other.rbegin());
                }
            }
        }
    }
    cout << out.size() << '\n';
    for(auto& cur : out) cout << "move " << cur.ff << " " << cur.ss << '\n';
}