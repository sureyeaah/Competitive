#include <iostream>
using namespace std;
int main() {
  int m, n, mn[102][102], game=0;
  char c;
  bool started = false;
  cin >> n >> m;
  while (n != 0 || m != 0) {
    if(started)
      cout << endl;
    game++;
    for (int i = 0; i < n + 2; i++) {
      for (int j = 0; j < m + 2; j++) {
        mn[i][j] = 0;
      }
    }
    for (int i = 1; i < n + 1; i++) {
      for (int j = 1; j < m + 1; j++) {
        cin >> c;
        if (c == '*') {
          mn[i][j] = -1;
          for (int l = i - 1; l < i + 2; l++) {
            for (int k = j - 1; k < j + 2; k++) {
              if (mn[l][k] != -1)
                mn[l][k]++;
            }
          }
        }
      }
    }
    cout << "Field #" << game << ":" << endl;
    for (int i = 1; i < n + 1; i++) {
      for (int j = 1; j < m + 1; j++) {
        if (mn[i][j] == -1) cout << '*';
        else cout << mn[i][j];
      }
      cout << endl;
    }
    cin >> n >> m;
    started = true;
  }
}