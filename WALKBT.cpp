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
bitset<2005> bs;
int t, n, q, c, trie[2005*2005][2], tot = 0; char x; 
/*bool search() {
    if(!tot) return false;
    int p = 0;
    FORD(i,0,n) {
        p = trie[p][bs[i]];
        if(!p)retur false;
    }
    return true;
}*/
void add() {
    int p = 0;
    FORD(i,0, n) {
        if(!trie[p][bs[i]])
            trie[p][bs[i]] = ++tot;
        p = trie[p][bs[i]];
    }
}
int main() {
    SYNC
    
    cin >> t;
    while(t--) {
        bs.reset();
        cin >> n >> q;
        memset(trie, 0, sizeof trie);
        tot = 1;
        while(q--) {
            cin >> x;
            if(x == '!') {
                cin >> c;
                int carry = 1;
                while(carry) {
                    carry = bs[c];
                    bs[c] = !bs[c];
                    c++;
                }
                bs[n] = 0;
                add();
            } else
                cout << tot << '\n';
        }
    }
}