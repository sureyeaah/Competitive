#include <iostream>
using namespace std;
int main(){
  int n, x, sum;
  sum = 0;
  int home[100] = {};
  int guest[100] = {};
  cin >> n;
  for (int i = 0; i < n; i++){
    cin >> x;
    home[x-1]++;
    cin >> x;
    guest[x-1]++;
  }
  for (int i = 0; i < 100; i++){
    sum += home[i]*guest[i];
  }
  cout << sum << endl;
  return 0;
}
