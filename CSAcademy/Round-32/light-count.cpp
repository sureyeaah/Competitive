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
#define LEN 64
#define maxn 50000000
bitset<LEN> bs[(maxn/LEN) + 5];
int ft[(maxn/LEN) + 5];
struct RandGen {
    int x, y, z;
    int nextInt() {
        int t = x ^ (x << 11);
        x = y;
        y = z;
        z ^= (z >> 19) ^ t ^ (t >> 8);
        return z;
    }
    int random(int N) {
        return nextInt() % N;
    }
};

void init(int N, int M) {	
	return;
}

void flipPosition(int i, int N) {
	int poz = i/LEN + 1;
	int val = bs[poz][i%LEN]? -1: 1;
	bs[poz][i%LEN].flip();
	while(poz <= N/LEN + 1) {
		ft[poz] += val;
		poz += (poz & (-poz));
	}
}

int query(int i) {
	int ret = 0;
	while(i > 0) {
		ret += ft[i];
		i -= i&(-i);
	}
	return ret;
}

int getCount(int st, int fn) {
	int ret = 0, stpos = st/LEN + 1, fnpos = fn/LEN + 1;
	ret += -query(stpos - 1) + query(fnpos);
	FOR0(i, st%LEN) ret -= (int)bs[stpos][i];
	FOR(i, (fn%LEN) + 1, LEN) ret -= (int)bs[fnpos][i];
	return ret;
}

int main() {
    int N, M;
    RandGen rng;
    cin >> N >> M >> rng.x >> rng.y >> rng.z;

    init(N, M);

    long long hashSol = 0;

    for (long long i = 0; i < M; i++) {
        /*
        int type, st, fn;
        cin >> type >> st;
        if(type) {
        	cin >> fn;
        	cout << getCount(st, fn) << endl;
        }
        else flipPosition(st, N);
        */
        if (rng.random(2) == 0) {
            const int poz = rng.random(N);
            flipPosition(poz, N);
        }
        else {
            int st = rng.random(N), fn = rng.random(N);
            if (st > fn) {
                swap(st, fn);
            }
            hashSol ^= i * getCount(st, fn);
        }
    }
    cout << hashSol << "\n";
}