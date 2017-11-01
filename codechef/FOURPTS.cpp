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
// ax+by=c
struct line{
	int a,b,c;
	line() {}
	line(int _a, int _b, int _c): a(_a), b(_b), c(_c) {}
};
ii pts[4];
line getLine(ii p1, ii p2) {
	int a = p1.ss - p2.ss;
	int b = p2.ff - p1.ff;
	return line(a, b, p1.ss*b + p1.ff*a);
}
/*
pair<double, double> meet(line l1, line l2) {
	if(l1.a == l2.a && l1.b == l2.b && l1.c != l2.c) return mp(INF, INF);
	else if(l1.a == l2.a && l1.b == l2.b && l1.c == l2.c) return mp(200, 200);
} */
void solve() {

}
int main() {
	SYNC;
	int x, y;
	FOR0(i, 4) {
		`cin >>x >> y;
		FOR0(i, 4) pts[i] = mp(x, y);
		FOR0(i, 24) {
			next_permutation(pts, pts+4);
		}
	}
}