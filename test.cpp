#include <bits/stdc++.h>
using namespace std;

int main() {
    auto fac = [](auto self, int n) -> int {return n > 1 ? n*self(self, n-1):1;};
    cout << fac(5);