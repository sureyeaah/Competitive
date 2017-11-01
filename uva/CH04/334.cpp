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

int caseNum, nc, ne, v, u, num, nm, matrix[201][201], lastNum;
string s;
map<string, int> names;
vector<string> iToName;
vii output;
void input() {
	cin >> s;
	if(!names.count(s)) {names[s] = num++; iToName.pb(s);}
}

int main() {
	caseNum = 1;
	lastNum = 201;
	while(scanf("%d", &nc) && nc) {
		num = 0;
		names.clear();
		iToName.clear();
		FOR0(i, lastNum) FOR0(j, lastNum) matrix[i][j] = INF;
		while(nc--) {
			cin >> ne;
			input();
			u = names[s];
			while(--ne) {
				input();
				v = names[s];
				matrix[u][v] = 1;
				u = v;
			}
		}
		cin >> nm;
		while(nm--) {
			input();
			u = names[s];
			input();
			v = names[s];
			matrix[u][v] = 1;
		}
		lastNum = num;
		FOR0(k, num)
			FOR0(i, num)
				FOR0(j, num) 
					matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j]);
		output.clear();
		FOR0(i, num)
			FOR0(j, i)
				if(matrix[i][j] == INF && matrix[j][i] == INF) { output.pb(ii(i, j)); }
		if(output.empty()) printf("Case %d, no concurrent events.\n", caseNum++);
		else {
			printf("Case %d, %d concurrent events:\n", caseNum++, (int)output.size());
			FOR0(i,min(2,(int)output.size()))cout << "(" << iToName[output[i].first]<< "," << iToName[output[i].second] << ") ";
			cout << endl;
		}
	}
}