#include <iostream>
using namespace std;
int main() {
  int n, m, l[3000];
  string a[3000][2], word;
  cin >> n >> m;
  for(int i = 0; i < m ;i++) {
    cin >> a[i][0] >> a[i][1];
    if(a[i][0].length() <= a[i][1].length()) {
      l[i] = 0;
    } else {
      l[i] = 1;
    }
  }
  cin >> word;
  for(int j = 0; j < m; j++) {
    if(a[j][0] == word || a[j][1] == word) {
      cout << a[j][l[j]];
    }
  }

  for(int i = 1; i < n; i++) {
    cin >> word;
    for(int j = 0; j < m; j++) {
      if(a[j][0] == word || a[j][1]== word) {
        cout << ' ' << a[j][l[j]];
      }
    }
  }
  return 0;
}
