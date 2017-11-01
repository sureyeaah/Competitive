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
#define SYNC std::ios::sync_with_stdio(false)
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<vi> vvi;
template <typename T,typename U>                                                   
std::pair<T,U> operator-(const std::pair<T,U> & l,const std::pair<T,U> & r) {   
    return {l.first-r.first,l.second-r.second};                                    
}

int n, m, k;
ii st[60000 + 5]; 
ii combine(ii l, ii r) {
	return mp(l.first + max(r.first-l.second,0),r.second + max(l.second-r.first,0));
}
void build() {
	for(int i = n-1; i > 0; i--) {
		st[i] = combine(st[i<<1],st[i<<1|1]);
	}
}
void update() {
	int p;
	for(p=k+n, st[p]=mp(1,1)-st[k+n]; p>1; p>>=1) {
		if(p & 1) st[p>>1] = combine(st[p^1],st[p]);
		else st[p>>1] = combine(st[p],st[p^1]);
	}
}
ii query() {
	ii resl = mp(0,0), resr = mp(0,0);
	for(int l = n, r = 2*n-1; l <= r; l >>= 1, r >>= 1) {
		if(l&1) resl = combine(resl, st[l++]);
		if(!(r&1)) resr = combine(st[r--], resr);
	}
	return combine(resl, resr);
}
int main() {
	char c;
	FOR(cases,1,11) {
		scanf("%d", &n);
		while(getchar() != '\n') {}
		FOR0(i, n) {
			scanf("%c", &c);
			st[i+n] = ((c == '(') ? mp(0,1) : mp(1,0));
		}
		build();
		scanf("%d", &m);
		printf("Test %d:\n", cases);
		while(m--) {
			scanf("%d", &k);
			if(k--) {
				update();
			}
			else if(query()==mp(0,0))
				printf("YES\n");
			else printf("NO\n");
		}
	}
}