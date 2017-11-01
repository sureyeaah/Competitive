#include <iostream>
#define FOR0(i, n) for (int i = 0; i < n; i++)
#define FOR(i, j, n) for (int i = j; i < n; i++)
#define MAX(a, b) ((a > b) ? (a) : (b))
#define MIN(a, b) ((a < b) ? (a) : (b))
#define ABS(a) ((a < 0) ? ((-1) * (a)) : (a))
using namespace std;
int t, c, r, n, ca;
string grid[2][100];
int xd[4] = {1,0,-1,0};
int yd[4] = {0,1,0,-1};
bool compare(char x, char y) {
  if (x == 'P')
    return y == 'S';
  else if (x == 'R')
    return y == 'P';
  else
    return y == 'R';
}
char fight(int x, int y, char ic)
{
  for(int i = 0; i < 4; i++) {
    int X = x+xd[i];
    int Y = y+yd[i];
    if(X >= 0 && X < r && Y >=0 && Y < c && compare(ic,grid[ca][X][Y])) return grid[ca][X][Y];
  }
  return ic;
}
int main()
{
  ios::sync_with_stdio(false);
  cin >> t;
  while (t--)
  {
    ca = 0;
    cin >> r >> c >> n;
    cin.ignore();
    FOR0(i, r)
    {
      getline(cin, grid[0][i]);
    }
    while (n--)
    {
      FOR0(i,r) {
        grid[1-ca][i] = "";
        FOR0(j,c) {
          grid[1-ca][i] += fight(i,j,grid[ca][i][j]);
        }
      }
      ca = 1-ca;
    }
      FOR0(i, r)
    {
      cout << grid[ca][i] << endl;
    }
    if(t) cout << endl;
  }
}
