#include <iostream>
#include <cmath>
using namespace std;

int main() {
  long long int n, m, d;
  cin >> n >> m;
  d = n - m + 1;
  long long int q = n/m;
  cout << (q*(m*(q-1) + 2*(n%m)))/2 << ' ' ;
  cout << d*(d-1)/2 << endl;
}
