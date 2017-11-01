#include <iostream>
using namespace std;

int main() {
	int n, s, d;
	cin >> n;
	while (n--) {
		cin >> s >> d;
		if (s >= d && s % 2 == d % 2) {
			cout << (s + d) / 2 << ' ' << (s - d) / 2 << endl;
		} else {
			cout << "impossible" << endl;
		}
	}
	return 0;
}