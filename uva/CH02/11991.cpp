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
int main() {
    int k,v,n,m,x;
    vi *curr;
    map<int, vi> index;
    while(scanf("%d%d", &n, &m)!=EOF) {
        FOR0(i, n) {
        	scanf("%d", &x);
        	index[x].pb(i+1);
        }
        while(m--) {
            scanf("%d%d", &k, &v);
            if(index.count(v)) {
            	curr = &index[v];
	            if((*curr).size() < k) printf("0\n");
            	else printf("%d\n",(*curr)[k-1]);
            }
       		else printf("0\n");
        }
        index.clear();
    }
}