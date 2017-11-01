#include <iostream>
using namespace std;
int main() {
  string output;
  int i = 0;
  int wub = 0;
  getline(cin,output);
  while(i < output.length()) {
    if(output[i] == 'W' && output[i+1] == 'U' && output[i+2] == 'B') {
      i+=3;
    }
    else {
      break;
    }
  }
  while(i < output.length()) {
    if(output[i] == 'W' && output[i+1] == 'U' && output[i+2] == 'B') {
      wub++;
      i+=3;
      continue;
    } else if(wub > 0) {
      cout << ' ';
      wub = 0;
    }
    cout << output[i];
    i++;
  }
  cout << endl;
  return 0;
}
