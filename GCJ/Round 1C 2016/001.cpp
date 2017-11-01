#include <bits/stdc++.h>
using namespace std;
#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define FOR0(i,n) for(int i=0, _##i=(n); i<_##i; ++i)
#define FOR(i,l,r) for(int i=(l), _##i=(r); i<_##i; ++i)
#define FORD(i,l,r) for(int i=(r), _##i=(l); --i>=_##i; )
#define repi(i,a) for(__typeof((a).begin()) i=(a).begin(), _##i=(a).end(); i!=_##i; ++i)
#define dwni(i,a) for(__typeof((a).rbegin()) i=(a).rbegin(), _##i=(a).rend(); i!=_##i; ++i)
#define printCase() "Case #" << caseNum << ":"
#define pb push_back
#define mp make_pair
#define INF (int)1e9
#define EPS 1e-9
#define SYNC std::ios::sync_with_stdio(false)
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<vi> vvi;

int main() {
	int t, n, p[26];
	scanf("%d", &t);
	FOR(caseNum,1,t+1) {
		scanf("%d", &n);
		FOR0(i, n) scanf("%d", p+i);
		cout << printCase();
		priority_queue<ii> pq;
		FOR0(i, n) pq.push(mp(p[i], i));
		while(pq.size() > 2) {
			printf(" ");
			ii curr = pq.top(); pq.pop();
			printf("%c",curr.ss+'A');
			if(curr.ff > 1) pq.push(mp(curr.ff-1, curr.ss));
		}
		if(!pq.empty()) {
			ii a = pq.top(); pq.pop();
			ii b = pq.top(); pq.pop();
			FOR0(i, a.ff) printf(" %c%c",a.ss+'A',b.ss+'A');
		}
		printf("\n");
	}
}