// http://codeforces.com/problemset/problem/451/A

#include <iostream>
#include <algorithm>
using namespace std;

int main() {
  int a, b;
  cin >> a >> b;
  int x = min(a,b);
  if(x%2 == 0) {
    cout << "Malvika" << endl;
  } else {
    cout << "Akshat" << endl;
  }
  return 0;
}
