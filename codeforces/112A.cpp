#include <iostream>
#include <cctype>
using namespace std;

int main(){
  string a,b;
  cin >> a;
  cin >> b;
  for (int i = 0; i < a.length(); i++) {
    if(tolower(a[i]) < tolower(b[i])) {
      cout << -1 << endl;
      return 0;
    } else if(tolower(a[i]) > tolower(b[i])) {
      cout << 1 << endl;
      return 0;
    }
  }
  cout << 0 << endl;
  return 0;
}
