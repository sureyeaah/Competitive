#include <iostream>
using namespace std;

int main() {
	int n;
	while (cin >> n) {
		int b, h, w, p, a, min;
		cin >> b >> h >> w;
		min = b + 1;
		for (int i = 0; i < h; i++) {
			cin >> p;
			for (int j = 0; j < w; j++) {
				cin >> a;
				if (a >= n) {
					if (p * n < min) min = p * n;
				}
			}
		}
		if (min <= b) {
			cout << min << endl;
		} else cout << "stay home" << endl;
	}
}