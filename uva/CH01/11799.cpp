#include <iostream>
using namespace std;
int main() {
  int t, n, maxSpeed, x;
  cin >> t;
  for (int i = 0; i < t; i++) {
    cin >> n;
    cin >> maxSpeed;
    for (int k = 1; k < n; k++) {
      cin >> x;
      if (x > maxSpeed) {
        maxSpeed = x;
      }
    }
    cout << "Case " << i + 1 << ": " << maxSpeed << endl;
  }
  return 0;
}
