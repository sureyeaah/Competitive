#include <bits/stdc++.h>
using namespace std;
#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define FOR0(i,n) for(int i=0, _##i=(n); i<_##i; ++i)
#define FOR(i,l,r) for(int i=(l), _##i=(r); i<_##i; ++i)
#define FORD(i,l,r) for(int i=(r), _##i=(l); --i>=_##i; )
#define repi(i,a) for(__typeof((a).begin()) i=(a).begin(), _##i=(a).end(); i!=_##i; ++i)
#define dwni(i,a) for(__typeof((a).rbegin()) i=(a).rbegin(), _##i=(a).rend(); i!=_##i; ++i)
#define pb push_back
#define mp make_pair
#define INF (int)1e9
#define EPS 1e-9
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<vi> vvi;

int n, m, b1, b2, caseNumber = 1, indeg[101];
vvi graph(101);
map<string, int> btoi;
string itob[101], name;

int main() {
    while(cin >> n) {
        btoi.clear();
        getline(cin, name); // stray newline
        FOR0(i, n) {
            getline(cin, name);
            btoi[name] = i;
            itob[i] = name;
            graph[i].clear();
        }
        cin >> m; getchar();
        memset(indeg, 0, sizeof indeg);
        FOR0(i, m) {
            getline(cin, name, ' ');
            b1 = btoi[name];
            getline(cin, name);
            b2 = btoi[name];
            graph[b1].pb(b2);
            indeg[b2]++;
        }
        getline(cin, name); // stray newline
        printf("Case #%d: Dilbert should drink beverages in this order:", caseNumber);
        int done = 0;
        while(done < n) {
            FOR0(u, n) {
                if(!indeg[u]) {
                    cout << " " << itob[u];
                    done++;
                    indeg[u]--;
                    repi(v, graph[u]) {
                        indeg[*v]--;
                    }
                    break;
                }
            }
        } 
        cout << '.' << endl << endl;
        caseNumber++;
    }   
}