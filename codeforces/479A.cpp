#include <iostream>
#include <algorithm>
using namespace std;

int main() {
  int a, b, c;
  cin >> a >> b >> c;
  int cases[6] = {a*b*c, a+b+c, a*b+c, a+b*c, (a+b)*c, a*(b+c)};
  cout << *max_element(cases, cases+6) << endl;
  return 0;
}
