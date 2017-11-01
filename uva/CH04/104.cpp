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
long double table[25][25][25];
int n, path[25][25][25];
void printSolution(int i, int j, int len) {
	if(!len) return;
	printSolution(i, path[i][j][len], len-1);	
	cout << path[i][j][len] << " ";
}
int main() {
	SYNC;
	while(cin >> n) {
		FOR(i, 1, n+1) {
			FOR(j, 1, n+1) {
				if(i == j) table[i][i][1] = 0.0;
				else cin >> table[i][j][1];
				path[i][j][1] = i;
			}
		}
		int ans = 0;
		FOR(len,2,n+1) {
			FOR0(k, n) {
				FOR0(i, n) {
					FOR0(j, n) {
						if(table[i][k][len-1]*table[k][j][1] > table[i][j][len]) {
							table[i][j][len] = table[i][k][len-1]*table[k][j][1];
							path[i][j][len] = k;
						}
					}
				}
			}
			FOR0(i, n) if(table[i][i][len] >= 1.01) {
				printSolution(i,i,len);
				cout << i << endl;
				ans = 1;
				break;
			}
			if(ans) break;
		}
		if(!ans) cout << "no arbitrage sequence exists" << endl;
	}
}