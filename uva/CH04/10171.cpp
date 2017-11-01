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

void fm(int matrix[26][26]) {
	FOR0(k, 26) {
		FOR0(i, 26) {
			FOR0(j, 26) {
				matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j]);
			}
		}
	}
}

int main() {
	int n, matrix[2][26][26], type, dir, u, v, w, me, miguel;
	char typec, dirc, uc, vc, mec, miguelc;
	while(scanf("%d", &n) && n) {
		while(getchar() != '\n') {}
		// reset
		FOR0(i, 26) {
			FOR0(j, 26) {
				matrix[0][i][j] = matrix[1][i][j] = INF;
			}
		}
		// input
		FOR0(i, n){
			scanf("%c%*c%c%*c%c%*c%c%d", &typec, &dirc, &uc, &vc, &w);
			while(getchar() != '\n') {}
			if(typec == 'Y') type = 0; else type = 1;
			if(dirc == 'B') dir = 1; else dir = 0;
			u = uc - 'A';
			v = vc - 'A';
			matrix[type][u][v] = w;
			if(dir) matrix[type][v][u] = w;
		}
		scanf("%c%*c%c", &mec, &miguelc);
		while(getchar() != '\n') {}
		me = mec - 'A';
		miguel = miguelc - 'A';
		FOR0(i, 26) matrix[0][i][i] = matrix[1][i][i] = 0;
		fm(matrix[0]);
		fm(matrix[1]);
		int ans = INF;
		vi place;
		FOR0(i, 26) {
			if (ans > matrix[0][me][i] + matrix[1][miguel][i]) {
				place.clear();
				place.pb(i);
				ans = matrix[0][me][i] + matrix[1][miguel][i];
			} else if (ans == matrix[0][me][i] + matrix[1][miguel][i])
				place.pb(i);
		}
		if(ans < INF) {
			printf("%d", ans);
			repi(i, place)
				printf(" %c", 'A' + (int)(*i));
		}
		else printf("You will never meet.");
		cout << endl;
	}
}