#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	int N;
	cin >> N;
	map<string, int> counts;
	rep(i,0,N) {
		string line;
		cin >> line;
		counts[line]++;
	}
	int least = INT_MAX;
	trav(pa, counts) least = min(least, pa.second);
	trav(pa, counts) {
		if (pa.second == least) cout << pa.first << endl;
	}
}
