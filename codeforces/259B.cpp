#include <iostream>
using namespace std;
int main() {
  int ms[3][3];
  int s = 0;
  for(int i = 0; i < 3; i++) {
    for (int j = 0; j < 3;j++) {
      scanf("%d", &ms[i][j]);
      s+=ms[i][j];
    }
  }
  s = s/2;
  ms[0][0] = s - ms[0][1] - ms[0][2];
  ms[1][1] = s - ms[1][0] - ms[1][2];
  ms[2][2] = s - ms[2][0] - ms[2][1];
  for(int i = 0; i < 3; i++) {
    cout << ms[i][0] << ' ' << ms[i][1] << ' ' << ms[i][2] << endl;
  }
}
