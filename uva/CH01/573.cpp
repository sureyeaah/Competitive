#include <iostream>
using namespace std;
int main() {
	//h - height, u - distance it climbs in day, d - slides, f - fatigue factor %
	int f,h,u,d,H;
	cin >> H;
	while (H > 0) {
		int day = 0;
		cin >> u >> d >> f;
		int dec = f*u;
		H *= 100;
		u *= 100;
		d *= 100;
		h = H;
		while(d < u) {
			day++;
			h -= u;
			if(h < 0) {
				cout << "success on day " << day << endl;
				break;
			}
			h += d;
			u -= dec;
		}
		if(u < 0) {u = 0; dec = 0;}
		if(h >= 0) {
			h -= u;
			if(h<0)
				cout << "success on day " << day+1 << endl;
			else {
				h+=u;
				while(h <= H) {
					h += d-u;
					u -= dec;
					day++;
					if(u < 0) {u = 0; dec = 0;}
				}
				cout << "failure on day " << day << endl;
			}
		}
		cin >> H;
	}
}
