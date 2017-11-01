#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int numbers[50];
    int i = 0;
    string input;
    getline(cin,input);
    for(; i < input.length(); i+=2) {
      numbers[i/2] = input[i] - '0';
    }
    sort(numbers, numbers+i/2);
    for(int j = 0;j < i/2 - 1; j++) {
      cout << numbers[j] << "+";
    }
    cout << numbers[i/2 - 1] << endl;
    return 0;
}
