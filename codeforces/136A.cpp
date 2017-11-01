#include <iostream>
#include <vector>

using namespace std;
int main() {
  int n, a;
  vector<int> output(n);
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a;
    output[a-1] = i+1;
  }
  cout << output[0];
  for (int i = 1; i < n; i++) {
    cout << ' ' << output[i];
  }
  cout << endl;
  return 0;
}
