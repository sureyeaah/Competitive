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

int main() {
	string input;
	int caseNum = 0;
	while(++caseNum) {
		int ans = 0;
		getline(cin, input);
		if(input[0] == 'e') break;
		stack<char> s[26];
		FOR0(i, input.length()) {
			char curr = input[i];
			FOR0(j,26) {
				if(s[j].empty()) {
					s[j].push(curr);
					ans++;
					break;
				} else {
					if(curr<=s[j].top()) {s[j].push(curr);break;}
				}
			}
		}
		printf("Case %d: %d\n",caseNum,ans);
	}
}