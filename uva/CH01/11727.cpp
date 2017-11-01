#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int t, a, b, c, x;
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> a >> b >> c;
		cout << "Case " << i + 1 << ": " << a + b + c - max(max(a, b), c) - min(min(a, b), c) << endl;
	}
	return 0;
}
