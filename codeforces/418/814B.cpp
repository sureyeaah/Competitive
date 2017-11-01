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
#define SYNC std::ios::sync_with_stdio(false)
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<vi> vvi;
#define maxn 1005

int n, m;
vi a,b,p;
void print() {
	FOR0(i, n) cout << p[i] << " ";
}
int main() {
	SYNC;
	cin >> n;
	FOR0(i, n) {cin >> m; a.pb(m);}
	FOR0(i, n) {cin >> m; b.pb(m);}
	FOR0(i, n) {
		bitset<maxn> bs;
		int cnt = 0;
		bs.reset();
		p = a;
		FOR0(j, n) {
			if(i == j) {continue;}
			bs[p[j]] = 1;
			if(p[j] != b[j]) cnt++;
		}
		if(!cnt) {
			FOR(j, 1, n+1) if(j != a[i] && j!= b[i] && !bs[j] && bs.count() == n-1) {
				p[i] = j; print(); return 0;
			}
		} else if(cnt == 1) {
			if(b[i] != a[i] && !bs[b[i]] && bs.count() == n-1) {p[i] = b[i]; print(); return 0;}
		}
	}
}