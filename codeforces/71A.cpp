#include <iostream>
using namespace std;
int main() {
  int number;
  string word;
  cin >> number;

  for(int i = 0; i < number; i++) {
    cin >> word;
    int len = word.length();
    if(len > 10) {
      cout << word[0] << len-2 << word[len-1] << endl;
    } else {
      cout << word << endl;
    }
  }
}
