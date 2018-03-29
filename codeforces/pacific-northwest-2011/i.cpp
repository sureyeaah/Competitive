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
int h, w, n;
char w1, w2, c;
string s;
int loc[4] = {};
inline bool edge(int n, char c) {
    n--; int x = n/w, y = n%w;
    if ((x==0 || x==h-1) || (y==0 || y==w-1)) {
        int t = (c-'A')/2;
        if(t==0 && x==0) return 1;
        if(t==1 && y==w-1) return 1;
        if(t==2 && x==h-1) return 1;
        if(t==3 && y==0) return 1;
    }
    return 0;
}
int main() {
    SYNC
    unordered_map<char, char> opp;
    opp['A'] = 'F';
    opp['B'] = 'E';
    opp['C'] = 'H';
    opp['D'] = 'G';
    opp['E'] = 'B';
    opp['F'] = 'A';
    opp['H'] = 'C';
    opp['G'] = 'D';
    int curr = 0;
    while(cin >> h >> w && h > 0 && w > 0) {
        curr++;
        cin.get();
        vector<unordered_map<char, char>> g(h*w+1);
        while(1) {
            getline(cin, s);
            if(s[0] == '0') break;
            istringstream iss(s);
            iss >> n;
            while(iss >> w1 >> w2) {
                g[n][w1] = w2;
                g[n][w2] = w1;
            }
        }
        string x;
        getline(cin, s);
        istringstream iss(s);
        if(curr > 1) cout << endl;
        cout << "Board " << curr << ":" << endl;
        while(iss >> x) {
            int nn; char cc;
            c = cc = x.back(); x.pop_back();
            nn = n = stoi(x, nullptr, 10);
            int pre = 0;
            // cerr << nn << cc << endl;
            while(!edge(n, c) || !pre) {
                if(pre == n) {
                    int t = (c-'A')/2;
                    if(t==0) {
                        n -= w;
                    } else if(t==1) {
                        n++;
                    } else if(t==2) {
                        n += w;
                    } else {
                        n --;
                    }
                    c = opp[c];
                } else {
                    pre = n;
                    c = g[n][c];
                }
                // cerr << n << c << endl; 
            }
            cout << nn << cc << " is connected to " << n << c << endl;
        }
    }
}