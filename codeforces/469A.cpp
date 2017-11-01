#include <iostream>
using namespace std;

int main(){
  int n, p, q, x;
  bool pLevels[100] = {};
  int common = 0;
  cin >> n;
  cin >> p;
  for(int i = 0; i < p; i++){
    cin >> x;
    pLevels[x-1] = true;
  }
  cin >> q;
  for(int i = 0; i < q; i++){
    cin >> x;
    if(pLevels[x-1]) {
      common++;
    }
  }
  if (p+q-common < n) {
    cout << "Oh, my keyboard!" <<endl;
  } else {
    cout << "I become the guy." << endl;
  }
  return 0;
}
