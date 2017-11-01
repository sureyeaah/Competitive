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

int p, r, u, v, matrix[51][51], num;
map<string, int> names;
string s;
char c;
int network = 1;
void input() {
	cin >> s;
	if(!names.count(s)) names[s] = num++;
}

int main() {
	
	while(scanf("%d%d", &p, &r) && p && r) {
		num = 0;
		names.clear();
		FOR0(i, p) FOR0(j, p) matrix[i][j] = INF;
		FOR0(i, r) {
			input();
			u = names[s];
			input();
			v = names[s];
			matrix[u][v] = matrix[v][u] = 1;
		}
		FOR0(k, p) {
			FOR0(i, p) {
				FOR0(j, p) {
					matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j]);
				}
			}
		}
		int ans = 0;
		FOR0(i, p) {
			FOR0(j, p) {
				if(i != j) ans = max(ans, matrix[i][j]);
			}
		}
		if(ans < INF) printf("Network %d: %d\n\n", network++, ans);
		else printf("Network %d: DISCONNECTED\n\n", network++);
	}
}