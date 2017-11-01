#include <iostream>
using namespace std;

int main(){
  char c;
  int num = 0;
  bool chars[26] = {};
  scanf("%c", &c);
  while(c != '}') {
    scanf("%c", &c);
    int distance = c - 'a';
    if(distance >= 0 && distance< 26) {
      if(!chars[distance]){
        num++;
        chars[distance] = true;
      }
    }
  }
  cout << num << endl;
  return 0;
}
