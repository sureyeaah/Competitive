#include <iostream>
#include <algorithm>
using namespace std;

int main() {
  char s[1001];
  int k, l, a, w[26];
  l = a = 0;
  while(s[l] = getchar(), s[l] != '\n') {
    l++;
  }
  scanf("%d",&k);
  for(int i = 0; i < 26; i++) {
    scanf("%d", &w[i]);
  }
  for(int i = 0; i < l; i++) {
    a+= (i+1)*w[s[i] - 'a'];
  }
  long long int m = (long long int)*max_element(w,w+26);
  cout << (long long int)a + (m*k*(2*l+k+1))/2 << endl;
}
