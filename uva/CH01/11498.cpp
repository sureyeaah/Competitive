#include <iostream>
using namespace std;

int main() {
  int k, x, y, a, b;
  cin >> k;

  while (k > 0) {
    cin >> x >> y;
    for (int i = 0; i < k; i++) {
      cin >> a >> b;
      if (a == x || b == y) {
        cout << ("divisa") << endl;
      } else if (a < x) {
        if (b > y) {
          cout << ("NO") << endl;
        } else {
          cout << ("SO") << endl;
        }
      } else {
        if (b > y) {
          cout << ("NE") << endl;
        } else {
          cout << ("SE") << endl;
        }
      }
    }
    cin >> k;
  }

  return 0;
}
