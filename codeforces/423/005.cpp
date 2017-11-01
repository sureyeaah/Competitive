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
#define POS(x) (!(n%len) || x%len <= n%len ? ((n-1)/len + 1)*(x%len) + x/len: ((n-1)/len)*(x%len+1)-1 + n%len)
#define N 100005
int n;
string s[11], e;
int ft[11][4][N] = {};
void update(int len, int i, int ch, int val) {
    i++;
    for(;i<=n;i+=i&(-i)) ft[len][ch][i] += val;
}
int query(int len, int i, int ch) {
    i++;
    int ans = 0;
    for(;i;i-=i&(-i)) ans += ft[len][ch][i];
    return ans;
}
int main() {
    map<char, char> gene;
    gene['A'] = 'A'; gene['G'] = 'B'; gene['C'] = 'C'; gene['T'] = 'D';
    SYNC
    cin >> s[1];
    n = s[1].length();
    FOR0(i, n) s[1][i] = gene[s[1][i]];
    FOR(i,2,11) {
        s[i] = "";
        FOR0(j,i) {
            for(int k = j; k < n; k+= i) s[i].pb(s[1][k]);
        }
    }
    FOR(len,1,11) {
        if(len > n) break;
        FOR0(i, n) update(len,i,s[len][i]-'A',1);
    }
    int q,type;
    cin >> q;
    while(q--) {
        cin >> type;
        if(type == 1) {
            int x; char c;
            cin >> x >> c;
            c = gene[c]; x--;
            FOR(len,1,11) {
                if(len > n) break;
                int pos = POS(x);
                update(len,pos,s[len][pos]-'A',-1);
                update(len,pos,c-'A',1);
                s[len][pos] = c;
            }
        } else {
            int l, r;
            cin >> l >> r >> e;
            l--; r--;
            int len = e.length();
            FOR0(i, len) e[i] = gene[e[i]];
            int ans = 0;
            cout << l << "-" << POS(l) << "-";
            len = min(len, n);
            FOR0(i, len) {
                if(l > r) break;
                int pos = POS(l);
                ans += query(len, pos+(r-l)/len,e[i]-'A') - query(len,pos-1,e[i]-'A');
                l++;
            }
            cout << ans << "\n";
        }
    }
}