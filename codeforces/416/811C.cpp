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
int n, a[5005], score[5005], endsAt[5005];
ii borders[5005];
int best(int, int);
int solve(int, int);
int best(int l, int r) {
	if(score[l]==-1) return solve(l+1, r);
	int mid = min(endsAt[l+1], r);
	return max(score[l], solve(l+1,mid)+solve(mid+1,r));
}
int solve(int l, int r) {
	if(r < l) return 0;
	if(score[l] <= 0) return solve(l+1, r);
	return best(l, endsAt[l]) + solve(endsAt[l]+1,r);
}

int main() {
	SYNC;	
	cin >> n; FOR0(i, n) cin >> a[i];
	FOR0(i, 5001) borders[i] = mp(INF,0);
	FOR0(i, n) borders[a[i]] = mp(min(borders[a[i]].ff, i), i);
	FOR0(i, n+1) endsAt[i] = INF;
	a[n] = n+1;
	int ans = 0;
	FOR(start,0,n) {
		if(borders[a[start]].ff != start) continue;
		int last = start, curr = 0;
		FOR(i, start, n+1) {
			if(last < i) {score[start] = curr; endsAt[start] = last; break;}
			if(borders[a[i]].ff < start) {score[start] = -1; break;}
			last = max(last, borders[a[i]].ss);
			if(i == borders[a[i]].ff) curr^=a[i];
		}
	}
	cout << solve(0,n-1);	
}