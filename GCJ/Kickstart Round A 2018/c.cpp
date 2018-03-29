#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define sd(x) scanf("%d", &(x))
 
const int N = 1000006;
const int base = 541;
const int mod = 1e9 + 7;
 
map<int, int> hashes[30][30];
int pw[N];
int freq[26];
set<int> lengths;
int x[N];
int pwr[N];
 
int main(){
    int t, n, l;
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    cin >> t;
    pwr[0] = 1;
    for(int i = 1; i < N; i++) pwr[i] = (pwr[i - 1] * 1ll * base) % mod;
    for(int T =1; T <= t; T++){
        cerr << "T = " << T << endl;
        cin >> l;
        for(int i = 0; i < 30; i++)
            for(int j = 0; j < 30; j++) hashes[i][j].clear();
        lengths.clear();
        for(int i = 1; i <= l; i++){
            string s;
            cin >> s;
            memset(freq, 0, sizeof freq);
            for(int j = 0; j < s.length(); j++) freq[s[j] - 'a']++;
            int h = 0;
            for(int j = 25; j >= 0; j--) h = (h * 1ll * base + freq[j] + 1) % mod;
            hashes[s[0] - 'a'][s[s.length() - 1] - 'a'][h]++;
            lengths.insert(s.length());
        }
        char s1, s2;
        int a, b, c, d;
        cin >> s1 >> s2 >> n >> a >> b >> c >> d;
        x[0] = s1;
        x[1] = s2;
        for(int i = 2; i < n; i++) x[i] = (a * 1ll * x[i - 1] + b * 1ll * x[i - 2] + c) % d;
        x[0] -= 'a';
        x[1] -= 'a';
        for(int i = 2; i < n; i++){
            x[i] %= 26;
        }
 
        int ans = 0;
        int cntr = 0;
        for(int len : lengths){
            memset(freq, 0, sizeof freq);
            for(int i = 0; i < len; i++) freq[x[i]]++;
            int h = 0;
            for(int j = 25; j >= 0; j--) h = (h * 1ll * base + freq[j] + 1) % mod;
            for(int i = 0; i + len - 1 < n; i++){
                if(hashes[x[i]][x[i + len - 1]].find(h) != hashes[x[i]][x[i + len - 1]].end()){
                    ans += hashes[x[i]][x[i + len - 1]][h];
                    hashes[x[i]][x[i + len - 1]][h] = 0;
                }
                h += pwr[x[i + len]];
                h -= pwr[x[i]];
                if(h >= mod) h -= mod;
                if(h < 0) h += mod;
            }
        }
        cout << "Case #" << T << ": " << ans << endl;
    }
}