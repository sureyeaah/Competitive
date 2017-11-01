// http://codeforces.com/problemset/problem/4/A
#include <iostream>

int main(){
  int x;
  std::cin >> x;
  if(x%2 == 0 && x!=2){
    std::cout << "YES";
  } else {
    std::cout << "NO";
  }
  return 0;
}
