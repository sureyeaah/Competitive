#include <iostream>
using namespace std;
int main() {
  int n, x, y, z;
  cin >> n;
  int sumCoords[3] = {};
  for (int i = 0; i < n; i++) {
    cin >> x >> y >> z;
    sumCoords[0] += x;
    sumCoords[1] += y;
    sumCoords[2] += z;
  }
  if(sumCoords[0] == 0 && sumCoords[1] == 0 && sumCoords[2] == 0) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
    return 0;
}
