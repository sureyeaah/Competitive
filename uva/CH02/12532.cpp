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
#define Sgn(x) ((x>0)?(1):((x<0)?(-1):(0)))
#define left(x) (x << 1)
#define right(x) ((x << 1) + 1)
int st[300000+10], a[100000+10];
int n,k,x;
void build(int p, int l, int r) {
	if(l == r)
		st[p]=a[l];
	else {
		build(left(p),l,(l+r)/2);
		build(right(p),(l+r)/2 + 1, r);
		int p1 = st[left(p)], p2 = st[right(p)];
		st[p] = p1 * p2;
	}
}

int rpq(int p, int l, int r, int i, int j) {
	if(i > r || j < l) return 1;
	if(l >= i && r <= j) return st[p];
	int p1 = rpq(left(p),l,(l+r)/2,i,j);
	int p2 = rpq(right(p),(l+r)/2 + 1,r,i,j);
	return p1*p2;
}

void update(int p, int l, int r, int i) {
	if(i < l || i > r) return;
	if(l == r) st[p] = a[i];
	else if(i >= l && i <= r) {
		update(left(p),l,(l+r)/2,i);
		update(right(p),(l+r)/2+1,r,i);
		st[p] = st[left(p)]*st[right(p)];
	}
}

int main() {
	while(scanf("%d%d", &n, &k)!=EOF) {
		FOR(i,1,n+1) {
			scanf("%d",&x);
			a[i] = Sgn(x);
		}
		build(1,1,n);
		while(k--) {
			while(getchar()!='\n') {}
			if(getchar() == 'C') {
				int i, v;
				scanf("%d%d",&i, &v);
				a[i] = Sgn(v);
				update(1,1,n,i);
			} else {
				int i, j;
				scanf("%d%d", &i, &j);
				int val = rpq(1,1,n,i,j);
				printf("%c", ((val==0)?'0':((val==1)?'+':'-')));
			}
		}
		printf("\n");
	}	
}