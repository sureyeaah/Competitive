	#include <bits/stdc++.h>
	using namespace std;
	#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
	#define FOR0(i,n) for(int i=0, _##i=(n); i<_##i; ++i)
	#define FOR(i,l,r) for(int i=(l), _##i=(r); i<_##i; ++i)
	#define FORD(i,l,r) for(int i=(r), _##i=(l); --i>=_##i; )
	#define repi(i,a) for(__typeof((a).begin()) i=(a).begin(), _##i=(a).end(); i!=_##i; ++i)
	#define dwni(i,a) for(__typeof((a).rbegin()) i=(a).rbegin(), _##i=(a).rend(); i!=_##i; ++i)
	#define printCase() "Case #" << caseNum << ": "
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
		SYNC;
		int n,a,b;
		ii v[100000 + 5];
		ll l;
		cin >> n >> l; FOR0(i, n) {cin >> a >> b; v[i] = mp(a, b);}
		FOR0(i, n) l -= v[i].ff;
		sort(v, v+n);
		int low = 2*INF;
		v[n] = mp(2*INF, 2*INF);
		int len = 0, rt = -1;
		int curr = v[0].ff;
		priority_queue<int,vi,greater<int> > pq;
		while(l > 0) {
			if(len==0) {
				len = 1;
				pq.push(v[++rt].ss); 
				curr = v[rt].ff;
			}
			while(rt < n && v[rt+1].ff==curr) {len++; pq.push(v[rt+1].ss); rt++;}
			int nxt = min(pq.top(), v[rt+1].ff);
			if(l >= (ll)len*(ll)(nxt - curr)) {l -= (ll)len*(ll)(nxt - curr); curr = nxt;}
			else if(l >= (ll)len) {curr += l/(ll)len; l -= (l/(ll)len)*(ll)len;}
			else {
				if(nxt > curr) {
					low = min(low, curr); curr++;
					l = 0;
				} else {
					while(!pq.empty() && pq.top() == curr) {pq.pop(); len--; low = min(curr, low);}
					if(len) curr++;
					l -= len; 		
				}
			}
			while(!pq.empty() && pq.top() == curr && curr == nxt) {pq.pop(); len--; low = min(curr, low);} 
		}
		if(low == 2*INF) low = curr;
		cout << (max(v[n-1].ff, curr)) - low << endl;
	}