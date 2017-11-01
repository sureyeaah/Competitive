#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define FOR0(i,n) for(int i=0, _##i=(n); i<_##i; ++i)
#define FOR(i,l,r) for(int i=(l), _##i=(r); i<_##i; ++i)
#define FORD(i,l,r) for(int i=(r), _##i=(l); --i>=_##i; )
#define repi(i,a) for(__typeof((a).begin()) i=(a).begin(), _##i=(a).end(); i!=_##i; ++i)
#define dwni(i,a) for(__typeof((a).rbegin()) i=(a).rbegin(), _##i=(a).rend(); i!=_##i; ++i)
#define SZ(a) ((int)((a).size()))
#define printCase() "Case #" << caseNum << ": "
#define pb push_back
#define mp make_pair
#define INF ((int)1e9)
#define SYNC std::ios::sync_with_stdio(false)
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<vi> vvi;
struct TCPhoneHome
{
    int digits; 
    vector<string> specialPrefixes; 
    bool isPre(string a, string b) {
        if(a.length() < b.length()) return 0;
        FOR0(i, b.length()) if(a[i] != b[i]) return 0;
        return 1;
    }
    long long validNumbers(int digits, vector<string> specialPrefixes)
    {
        this->digits = digits; 
        this->specialPrefixes = specialPrefixes; 
        long long ans = 1;
        FOR0(i, digits) ans = ans * 10;
        int arr[100] = {};
        FOR0(i, specialPrefixes.size()) {
            int x = 1;
            FOR0(j, specialPrefixes.size()) {
                if(j == i) continue;
                if(isPre(specialPrefixes[i], specialPrefixes[j])) {
                    x = 0;
                } 
            }
            if(x) {
                arr[i] = 1;
                ll v = 1;
                FOR0(t, digits - specialPrefixes[i].length()) v *= 10;
                DEBUG(v);
                ans -= v;
            }
        }
        // FOR0(i, specialPrefixes.size()) { 
        //     FOR0(j, specialPrefixes.size()) {
        //         if(i!= j && isPre(specialPrefixes[i], specialPrefixes[j]) && arr[j]) ans++;
        //     }
        // }
        return ans;
    }
};

// CUT begin
ifstream data("TCPhoneHome.sample");

string next_line() {
    string s;
    getline(data, s);
    return s;
}

template <typename T> void from_stream(T &t) {
    stringstream ss(next_line());
    ss >> t;
}

void from_stream(string &s) {
    s = next_line();
}

template <typename T> void from_stream(vector<T> &ts) {
    int len;
    from_stream(len);
    ts.clear();
    for (int i = 0; i < len; ++i) {
        T t;
        from_stream(t);
        ts.push_back(t);
    }
}

template <typename T>
string to_string(T t) {
    stringstream s;
    s << t;
    return s.str();
}

string to_string(string t) {
    return "\"" + t + "\"";
}

bool do_test(int digits, vector<string> specialPrefixes, long long __expected) {
    time_t startClock = clock();
    TCPhoneHome *instance = new TCPhoneHome();
    long long __result = instance->validNumbers(digits, specialPrefixes);
    double elapsed = (double)(clock() - startClock) / CLOCKS_PER_SEC;
    delete instance;

    if (__result == __expected) {
        cout << "PASSED!" << " (" << elapsed << " seconds)" << endl;
        return true;
    }
    else {
        cout << "FAILED!" << " (" << elapsed << " seconds)" << endl;
        cout << "           Expected: " << to_string(__expected) << endl;
        cout << "           Received: " << to_string(__result) << endl;
        return false;
    }
}

int run_test(bool mainProcess, const set<int> &case_set, const string command) {
    int cases = 0, passed = 0;
    while (true) {
        if (next_line().find("--") != 0)
            break;
        int digits;
        from_stream(digits);
        vector<string> specialPrefixes;
        from_stream(specialPrefixes);
        next_line();
        long long __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if ( do_test(digits, specialPrefixes, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1507806003;
        double PT = T / 60.0, TT = 75.0;
        cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
        cout << "Score  : " << 250 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
    }
    return 0;
}

int main(int argc, char *argv[]) {
    cout.setf(ios::fixed, ios::floatfield);
    cout.precision(2);
    set<int> cases;
    bool mainProcess = true;
    for (int i = 1; i < argc; ++i) {
        if ( string(argv[i]) == "-") {
            mainProcess = false;
        } else {
            cases.insert(atoi(argv[i]));
        }
    }
    if (mainProcess) {
        cout << "TCPhoneHome (250 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end
