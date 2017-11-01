// learnt about different speeds of c++14 and c++11 or atleast I believe so.
#include <iostream>
using namespace std;

int main() {
  int n, m, x;
  int r = 0;
  long long int seconds = 0;
  scanf("%d%d", &n, &m);
  int prevHouse = 1;
  while(m--) {
    scanf("%d", &x);
    if(x < prevHouse) {
      r++;
    }
    prevHouse = x;
  }
  seconds = (long long int)r*(long long int)n + (long long int)prevHouse - 1;
  printf("%I64d", seconds);
  return 0;
}
