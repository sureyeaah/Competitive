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
	string s1, s2;
	char output[300000 + 5];
	cin >> s1 >> s2;
	int n = s1.length(), r2 = n/2 - 1, r1 = (n-1)/2, i = 0, l1 = 0, l2 = 0, l= 0, r = n-1;
	sort(s1.begin(), s1.end()); sort(s2.begin(), s2.end(), greater<char>());
	//cout << s1 << endl; cout << s2 << endl;
	while(i++ < n) {
		if(i%2) {
			if(s1[l1] < s2[l2]) output[l++]= s1[l1++]; 
			else /*if(s1[r1] > s2[l2])*/ output[r--] = s1[r1--];
		} else {
			if(s1[l1] < s2[l2]) output[l++]= s2[l2++]; 
			else /*if(s2[r2] < s1[l1])*/ output[r--] = s2[r2--];
			
		}
	}
	FOR0(i, n) cout << output[i];
}