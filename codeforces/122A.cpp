#include <iostream>
using namespace std;

int main() {
  int input;
  cin >> input;
  if(input%4 == 0 || input%7 ==0) {
    cout << "YES" <<endl;
    return 0;
  }
  int lucky[14];
  lucky[0] = 4;
  lucky[1] = 7;
  int base = 2;
  int ten = 10;
  while(input%ten != input) {
    for(int i = 0; i < base; i++) {
      int num = 4*ten + lucky[base + i - 2];
      if (input % num == 0) {
        cout << "YES" <<endl;
        return 0;
      }
      lucky[2*base - 2 + i] = num;
    }
    for(int i = 0; i < base; i++) {
      int num = 7*ten + lucky[base + i - 2];
      if (input % num == 0) {
        cout << "YES" <<endl;
        return 0;
      }
      lucky[3*base - 2 + i] = num;
    }
    base = base*2;
    ten = ten*10;
  }
  cout << "NO" <<endl;
  return 0;
}
