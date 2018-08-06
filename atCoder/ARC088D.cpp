#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    string s;
    cin >> s;
    int n = s.length();
    int cur = -1, ans = n/2;
    while(ans < n) {
        ans++;
        if (s[ans-1] == s[n-ans] && (cur == -1 || cur == s[ans-1]-'0')) {
            cur = s[ans-1] - '0';
        }
        else {
            ans--;
            break;
        }
    }
    cout << ans;
}
