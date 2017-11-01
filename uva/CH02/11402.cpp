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
#define BUC 1
#define BAR 0
#define left(x) ((x)<<1)
#define right(x) (((x)<<1)+1)
int m,n,T,t,a,b;
char type;
char pirates[1024000+10], buffer[55];
string lazyType[1048576*2];
int num[1048576*2];
int build(int p, int l, int r) {
	lazyType[p] = "";
	if(l == r) return num[p] = pirates[l] -'0';
	return (num[p] = build(left(p),l,(l+r)/2)+build(right(p),(l+r)/2+1,r));
}
int query(int p, int l, int r, int i, int j) {
	FOR0(i, lazyType[p].length()) {
		if(lazyType[p][i] == 'F') num[p] = r-l+1;
		else if(lazyType[p][i] == 'E') num[p] = 0;
		else num[p] = r-l+1-num[p];
		if(l!=r){
			lazyType[left(p)]+= lazyType[p][i];
			lazyType[right(p)]+= lazyType[p][i];
		}
	}
	lazyType[p] = "";
	if(l > j || r < i || l > r) return 0;
	if(l >= i && r <= j) return num[p];

	return query(left(p),l,(l+r)/2,i,j) + query(right(p), (l+r)/2 + 1, r, i, j);
}
int query(int i, int j) {
	return query(1,0,n-1,i,j);
}

void update(int p, int l, int r, int i, int j) {
	FOR0(i, lazyType[p].length()) {
		if(lazyType[p][i] == 'F') num[p] = r-l+1;
		else if(lazyType[p][i] == 'E') num[p] = 0;
		else num[p] = r-l+1-num[p];
		if(l!=r){
			lazyType[left(p)]+= lazyType[p][i];
			lazyType[right(p)]+= lazyType[p][i];
		}
	}
	lazyType[p] = "";
	if(l > j || r < i || l > r) return;
	if(l >= i && r <= j) {
		if(type == 'F') num[p] = r-l+1;
		else if(type == 'E') num[p] = 0;
		else num[p] = r-l+1-num[p];
		if(l!=r){
			lazyType[left(p)]+= type;
			lazyType[right(p)]+= type;
		}
		return;
	}
	update(left(p),l,(l+r)/2,i,j);
	update(right(p),(l+r)/2+1,r,i,j);
	num[p] = num[left(p)] + num[right(p)];
}
int main() {
	scanf("%d", &T);
	FOR(caseNumber,1,T+1) {
		scanf("%d", &m);
		n = 0;
		while(m--) {
			scanf("%d",&t);
			while(getchar()!='\n' ) {}
			scanf("%s",buffer);
			int len = strlen(buffer);
			while(t--) {
				strcpy(pirates+n,buffer);
				n+=len;
			}
		}
		build(1,0,n-1);
		printf("Case %d:\n",caseNumber);
		int q, qnum = 1;
		scanf("%d", &q);
		while(q--) {
			while(getchar() != '\n') {}
			scanf("%c%d%d",&type,&a,&b);
			if(type == 'S') {
				printf("Q%d: %d\n",qnum++,query(a,b));
			} else update(1,0,n-1,a,b);
		}
	}
}