#include <iostream>
#include <algorithm>
using namespace std;

int main() {
  int n;
  long int l, lants[1000];
  scanf("%d%ld", &n, &l);
  for(int i = 0; i < n; i++) {
    scanf("%ld", &lants[i]);
  }
  sort(lants, lants+n);
  double d = max(lants[0], l - lants[n-1]);
  for(int i = 0; i < n-1; i++) {
    d = max(d, (double)(lants[i+1] - lants[i])/2);
  }
  printf("%.10f", d);
}
