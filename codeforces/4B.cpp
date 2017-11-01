#include <iostream>
using namespace std;
int main() {
	
	int d, sumt, t[30][2], minsum, maxsum, left;
	minsum = maxsum = 0;
	cin >> d >> sumt;
	for(int i = 0 ; i < d; i++) {
		cin >> t[i][0] >> t[i][1];
		minsum += t[i][0];
		maxsum += t[i][1];
	}
	if(sumt < minsum || sumt > maxsum)
		cout << "NO" << endl;
	else {
		left = sumt - minsum;
		int i = 0;
		cout << "YES" << endl;
		for(; i < d; i++) {
			if(left < t[i][1] - t[i][0]) {
				t[i][0] += left;
				break;
			} else {
				left -= t[i][1] - t[i][0];
				t[i][0] = t[i][1];
			}
			cout << t[i][0] << ' ';
		}
		for(; i < d; i++) {
			cout << t[i][0] << ' ';
		}
	}
}