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
int main() {
	SYNC;
	int n, q, a[100000 + 5], type, ind, s, a1[100000 + 5] = {};
	cin >> n >> q;
	FOR0(i, n) cin >> a[i];
	int cnt = 0, tot=0;
	while(q--) {
		cin >> type >> ind;
		ind--;
		if(!type) {
			cin >> s;
			a1[ind] += s; tot+=s;
		} else {
			cout << setprecision(6) << fixed << a[ind]+a1[ind] - ((tot-a1[ind])/(double(n-1)))<< endl;
		}
	}
}