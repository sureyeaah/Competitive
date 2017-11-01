// learnt about swap function
#include <iostream>
using namespace std;

int main() {
  int n, t, len;
  cin >> n >> t;
  string input;
  cin >> input;
  len = input.length();
  for(int j = 0; j < t; j++) {
    for(int i = 0; i < len-1; i++) {
      if(input[i] == 'B' && input[i+1] == 'G') {
        input[i] = 'G';
        input[i+1] = 'B';
        i++;
      }
    }
  }
  cout << input << endl;
  return 0;
}
