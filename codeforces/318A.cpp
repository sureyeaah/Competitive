#include <iostream>
using namespace std;

int main() {
  uint64_t n,k;
  cin >> n >> k;
  if(k <= n/2 || k<=(n+1)/2){
    cout << 2*k - 1<< endl;
  } else {
    if(n%2 == 0) {
        cout << 2*k - n<< endl;
    }
       else {
        cout << 2*k - n - 1<< endl;
      }
  }
}
