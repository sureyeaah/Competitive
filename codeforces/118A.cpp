#include <iostream>
#include <algorithm>
using namespace std;

int main() {
  string input;
  cin >> input;
  char vowels[6] = {'a','o','y','e','u','i'};
  for (int i =0; i < input.length();i++) {
    if (input[i] < 97) {
      input[i] += 'a' - 'A';
    }
    if(find(vowels, vowels+6, input[i]) == vowels+6) {
      cout << '.' << input[i];
    }
  }
  cout << endl;
  return 0;
}
