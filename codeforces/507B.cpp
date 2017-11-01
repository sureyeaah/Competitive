#include <cmath>
#include <iostream>
using namespace std;

bool isIntg(double n){if(ceil(n) == n) return true; else return false;}
int main() {
  long long int r,x1,y1,x2,y2;
  long long int steps = 0;
  cin >> r >> x1 >> y1 >> x2 >> y2;
  x1 -= x2;
  y1 -= y2;
  x2 = y2 = 0;
  double d = sqrt(x1*x1 + y1*y1);
  steps+= (long long int)(d/(2*r));
  d -= 2*r*((long long int)(d/(2*r)));
  if(!isIntg(d/(2*r)))
    steps+=1;
  cout << steps << endl;
}
