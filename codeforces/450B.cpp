#include <iostream>
using namespace std;

int main() {
  long int a[3],n;
  scanf("%ld%ld%ld", &a[0], &a[1], &n);
  long int p = 1000000007;
  a[0] = (a[0]+p)%p;
  a[1] = (a[1]+p)%p;
  a[2] = (a[1] - a[0] + p) % p ;
  n = (n-1)%6;
  if(n < 3) cout << a[n] << endl;
  else cout << (p-a[n%3])%p << endl;
  return 0;
}
