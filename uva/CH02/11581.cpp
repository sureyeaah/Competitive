#include <iostream>
using namespace std;
#define FOR(i,n,m) for(int i = n; i < m; i++)
int main() {
	int n, grid[2][5][5] = {}, ones = 0, index, ca;
	cin >> n;
	cin.ignore(); 
	while(n--) {
		ones = 0; index = -1, ca = 0;
		cin.ignore();
		FOR(i,1,4) {
			FOR(j,1,4) {
				grid[0][i][j] = getchar() - '0';
				ones += grid[0][i][j];
			}
			cin.ignore();
		}
		while(ones != 0) {
			ones = 0;
			FOR(i,1,4) {
				FOR(j,1,4) {
					grid[1-ca][i][j] = grid[ca][i+1][j] ^ grid[ca][i-1][j] ^ grid[ca][i][j + 1] ^ grid[ca][i][j-1];
					ones += grid[1-ca][i][j];
				}
			}
			index++;
			ca = 1 - ca;
		}
		cout << index << endl;
	} 
	return 0;
}