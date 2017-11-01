#include <iostream>
using namespace std;
int main() {
  int n, b1, b2;
  long int x, y;
  long int a[100001];
  cin >> n;
  a[n] = 1000000001;
  for(int i = 0; i < n; i++) {
    cin >> a[i];
  }
  if(n == 1){
    printf("yes\n%ld %ld\n", 1, 1);
    return 0;
  }
  int i = 0;
  for(; i < n; i++) {
    if(a[i] > a[i+1]) {
      b1 = i;
      x = (i == 0) ? 0 :a[i-1];
      i++;
      break;
    }
  }
  if(i == n) {
    printf("yes\n%ld %ld\n", 1, 1);
    return 0;
  }
  for(; i < n; i++) {
    if(a[i] < a[i+1]){
      b2 = i;
      y = a[i+1];
      i++;
      break;
    }
  }
  for(;i < n; i++) {
    if(a[i] > a[i+1]) {
      printf("no\n");
      return 0;
    }
  }
  if((x <= a[b2]) && (y >= a[b1]))
    printf("yes\n%ld %ld\n", b1+1, b2+1);
  else printf("no\n");
  return 0;
}
