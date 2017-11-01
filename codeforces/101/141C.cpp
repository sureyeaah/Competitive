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
	int a[3001], h[3001];
	map<string, int> names; string s[3001];
	int n;
	int cnt[3005] = {};
	cin >> n;
	FOR0(i, n) {
		cin >> s[i] >> a[i];
		names[s[i]] = i;
		cnt[a[i]]++;
	}
	FOR0(i, n) h[i] = 100000;
	FORD(i,1,n) {
		if(!cnt[i]) continue;
		int curr = 0, index = 0;
		while(index < n) {
			if (h[index] < 100000-i) {index++; continue;}
			if (curr == i) break;
			curr++;
			index++;
		}
		if(curr!=i) {cout<< "-1" << endl; return 0;}
		while(cnt[i] && index < n) {
			if(h[index] < 100000-i) {index++; continue;}
			h[index] -= i;
			cnt[i]--;
			index++;
		}
		if(cnt[i]) {cout<< "-1" << endl; return 0;}
	}
	FOR0(i, n) {
		repi(j,names) {
			if (j->ss == -1) continue;
			if (a[j->ss] == 100000-h[i]) {
				cout << j->ff << " " << h[i] << endl;
				j->ss = -1;
				break;
			}
		}
	}
}