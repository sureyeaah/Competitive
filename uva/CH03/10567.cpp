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
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<vi> vvi;
#define val(x) (x <= 'Z' ? x - 'A': x - 'a' + 26)
int main() {
	SYNC;
	char input[1000002], s[105];
	int q;
	vvi pos(52);
	cin >> input >> q;
	FOR0(i, strlen(input)) {
		pos[val(input[i])].pb(i);
	}
	while(q--) {
		cin >> s;
		int last = -1, len = strlen(s), start;
		int num = val(s[0]);
		if(pos[num].size()) {
			start = pos[num][0];
			last = start;
			FOR(i,1,len) {
				num = val(s[i]);
				int x = upper_bound(pos[num].begin(), pos[num].end(), last) - pos[num].begin();
				if(x == pos[num].size()) {last = -1; break;}
				else last = pos[num][x];
			}
		}
		if(last == -1) cout << "Not matched" << endl;
		else cout << "Matched " << start << " " << last << endl;
	}
}