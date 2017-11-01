#include <iostream>
using namespace std;

int main() {
  int n, h2;
  scanf("%d", &n);
  long long int seconds = 2*n-1;
  int h1 = 0;
  for(int i = 0; i < n; i++) {
    scanf("%d", &h2);
    if(h2 < h1) {
      seconds += h1 - h2;
    } else {
      seconds += h2 - h1;
    }
    h1 = h2;
  }
  cout << seconds << endl;
}
