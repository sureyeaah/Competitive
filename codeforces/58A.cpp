#include <iostream>
using namespace std;

int main() {
  string input;
  int index = 0;
  char hello[5] = {'h','e','l','l','o'};
  cin >> input;
  int len = input.length();
  if(len >= 5) {
      for(int i = 0; i < len; i++) {
        if(hello[index] == input[i]) {
          index++;
          if(index == 5){
            cout << "YES" << endl;
            return 0;
          }
        }
      }
    }
    cout << "NO" << endl;
    return 0;
  }
