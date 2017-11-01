// Learnt about bitset
#include <iostream>
#include <bitset>
using namespace std;

int main() {
  int n, m, k, t[1001];
  int ans = 0;
  string bin, f;
  scanf("%d%d%d", &n,&m,&k);
  for(int i = 0; i < m; i++) {
    scanf("%d", &t[i]);
  }
  scanf("%d", &t[m]);
  f = bitset<20>(t[m]).to_string();
  for (int i = 0; i < m; i++) {
    bin = bitset<20>(t[i]).to_string();
    int diff = 0;
    for(int j = 0; j < 20; j++) {
      if(bin[j] != f[j]) {
        diff++;
      }
    }
    if(diff <= k) {
      ans++;
    }
  }
  cout << ans << endl;
}
