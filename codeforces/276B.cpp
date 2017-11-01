#include <iostream>
#include <algorithm>
using namespace std;

int main() {
  char s[1001];
  int l = 0, odd = 0;
  while(s[l] = getchar(), s[l] != '\n') {
    l++;
  }
  sort(s, s+l);
  bool o[26] = {};
  for(int i = 0; i < l; i++) {
    o[s[i] - 'a'] = !o[s[i] - 'a'];
  }
  for(int i = 0; i < 26; i++) {
    odd += o[i] ? 1: 0;
  }
  if(odd == 0 || odd%2 ==1) cout << "First" << endl;
  else cout << "Second" << endl;
}
