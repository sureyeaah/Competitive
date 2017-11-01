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
int n,t;
char num[25],ans[25];
bool carry(int pos) {
	if(pos == 0) return false;
	if(num[pos] > num[pos-1]) {
		num[pos]--;
		return true;
	}
	if(carry(pos-1)) {
		num[pos] = '9';
		return true;
	} else return false;
}
int main() {
	scanf("%d%*c", &t);
	FOR(caseNum,1,t+1) {
		scanf("%s", num+1);
		n = strlen(num+1);
		num[0] = '0';
		FOR(i,1,n+1) {
			if(num[i]<num[i-1]) {
				num[i] = carry(i-1) ? '9' : '0';
				FOR(j,i+1,n+1) num[j] = '9';
			}
		}
		int index = 0;
		while(num[index] == '0') index++;
		if (index == n+1) index--;
		printf("Case #%d: %s\n", caseNum, num+index);
	}
}