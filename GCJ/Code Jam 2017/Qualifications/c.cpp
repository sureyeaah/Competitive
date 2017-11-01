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
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<vi> vvi;

int main() {
	int t;
	ll n, k;
	scanf("%d", &t);
	FOR(caseNum, 1, t+1) {
		scanf("%lld%lld",&n,&k);
		ll ev = 0, od = 0, nod = -1, nev = -1;
		if(n&1) {
			od = 1;
			nod = n;
		}
		else {
			ev = 1;
			nev = n;
		}
		ll upper = 1;
		while(true) {
			if(upper >= k) {
				if((nod > nev && upper-ev >= k) || (nod < nev && upper-od < k && nod!=-1)) printf("Case #%d: %lld %lld\n", caseNum, nod>>1, nod>>1);
				else printf("Case #%d: %lld %lld\n", caseNum, max(nev>>1, nev-(nev>>1)-1) , min(nev>>1, nev-(nev>>1)-1));
				break;
			} else {
				ll nxtev = 0, nxtod = 0;
				if(nev != -1) {
					nxtev +=  ev;
					nxtod += ev;
				}
				if(nod != -1) {
					if(nod>>1&1) nxtod += 2*od;
					else nxtev += 2*od;
				}
				od = nxtod;
				ev = nxtev;
				upper += od + ev;
				if(nev != -1) {
					if(nev >> 1 & 1) {
						nod = nev >> 1;
						nev = nev - nod - 1;
					} else {
						nod = nev - (nev >> 1) - 1;
						nev = nev>>1;
					}
				} else {
					if(nod>>1 & 1) {
						nod >>= 1;
					} else {
						nev = nod >> 1;
						nod = -1;
					}
				}
			}
		}
	}
}


/*
k.log(k) approach for small input
int main() {
	int t;
	ll n, k;
	scanf("%d", &t);
	FOR(caseNum, 1, t+1) {
		scanf("%d%d",&n,&k);
		//int hsb = 63-__builtin_clzll(k);
		priority_queue<int> pq;
		pq.push(n);
		while(true) {
			int curr = pq.top(); pq.pop();
			if(k==1) {
				printf("Case #%d: %d %d\n", caseNum, curr>>1, (curr-1)>>1);
				break;
			}
			k--;
			pq.push(curr>>1); pq.push((curr-1)>>1);
		}
	}
}
*/