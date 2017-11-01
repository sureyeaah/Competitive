#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int p[168] = {2,3,5,7,11,13,17,19};
int numP = 8;
bool isPrime(int num) {
  if(num <= 1000) {
    if(find(p, p+numP,num) != p+numP)
      return true;
    else return false;
  }
  for(int j = 0; j < numP; j++) {
    if(num%p[j] == 0)
      return false;
  }
  return true;
}

int main() {
  int n, f;
  long long int x;
  scanf("%d", &n);
  for(int i = 23; i < 1000; i+=2) {
    int j = 0;
    for(; j < numP; j++) {
      if(i%p[j] == 0)
        break;
    }
    if(j == numP){
      p[numP] = i;
      numP++;}
  }

  for(int i = 0; i < n;i++) {
    cin >> x;
    f = sqrt(x);
    if((long long int)f*f == x && isPrime(f) && f!=1) {
        cout << "YES" << endl;
        continue;
    }
    cout << "NO" << endl;
  }
  return 0;
}
