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
	int n, N, x, t, y, s1, s2;
	scanf("%d", &t);
	while(t--) {
		scanf("%d", &N);
		s1 = s2 = 0;
		FOR0(i ,2) {
			n = N;
			while(n > 2) {
				scanf("%d%d",&x,&y);
				s1 += x;
				s2 += y;
				n -= 2;
			}
			scanf("%d",&x);
			s1 += x;
			if(n == 2) {
				scanf("%d",&x);
				s2 += x;
			}
			swap(s1,s2);
		}		
		printf("%d\n", min(s1,s2));
	}
}