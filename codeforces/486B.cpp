#include <iostream>
using namespace std;

int main() {
  int m,n;
  int a[100][100];
  int b[100][100];
  int one = 0;
  scanf("%d%d", &m, &n);
  for(int i = 0; i < m; i++) {
    for(int j = 0; j < n; j++) {
      scanf("%d", &b[i][j]);
      a[i][j] = 1;
      if(b[i][j] == 1) one++;
    }
  }
  if(one < n + m - 1 && one > 0) {cout << "NO" << endl; return 0;}
  else {
    for(int i = 0; i < m; i++) {
      for(int j = 0; j < n; j++) {
        if(b[i][j] == 0) {
          for(int x = 0; x < m; x++) {
            a[x][j] = 0;
          }
          for(int y = 0; y < n; y++) {
            a[i][y] = 0;
          }
        }
      }
    }
    for(int i = 0; i < m; i++) {
      for(int j = 0; j < n; j++) {
        if(b[i][j] == 1) {
          int x = 0;
          for(; x < m; x++) {
            if(a[x][j] == 1) break;
          }
          int y = 0;
          for(; y < n; y++) {
            if(a[i][y] == 1) break;
          }
          if(x == m && y == n) {cout << "NO" << endl; return 0;}
        }
      }
    }
  }

  printf("YES\n");
  for(int i = 0; i < m; i++) {
    printf("%d",a[i][0]);
    for(int j = 1; j < n; j++) {
      printf(" %d",a[i][j]);
    }
    printf("\n");
  }
}
