#include <iostream>
using namespace std;
int main() {
  int n, posMin, posMax, Min, Max, x;
  cin >> n;
  cin >> x;
  posMin = posMax = 0;
  Min = Max = x;
  for(int i = 1; i < n; i++){
    cin >> x;
    if (x <= Min) {
      Min = x;
      posMin = i;
    } else if(x > Max) {
      Max = x;
      posMax = i;
    }
  }
  if (posMax > posMin) {
    cout << posMax + n - posMin - 2<< endl;
  } else {
    cout << posMax + n - posMin - 1<< endl;
  }
  return 0;
}
