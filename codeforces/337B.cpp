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
int gcd(int a, int b) {
	return (b) ? gcd(b,a%b): a;
}
int main() {
	int a,b,p,q;
	cin >> a >> b >> p >> q;
	double f1 = ((double)b*p)/(a*q);
	if(f1 <= 1.0) cout << ((a*q)-(b*p))/gcd(b*p,a*q) << "/" << (a*q)/gcd(b*p,a*q) << endl;
	else cout << (-(a*q)+(b*p))/gcd(b*p,a*q) << "/" << (b*p)/gcd(b*p,a*q) << endl;
}