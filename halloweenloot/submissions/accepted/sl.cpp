#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
typedef pair<int, int> pii;
typedef vector<int> vi;

vi a, b;
int N;
map<pii, pii> mem;
string ans;
int rec(int ind, int val, bool reconstruct = false) {
	if (ind == N) return val;
	pii& out = mem[pii(ind, val)];
	if (out.second && !reconstruct) return out.first;
	int left = rec(ind + 1, val + a[ind]);
	int right = rec(ind + 1, val - b[ind]);
	if (abs(left) > abs(right)) {
		if (reconstruct) {
			ans += 'B';
			rec(ind + 1, val - b[ind], true);
		}
		out.first = right;
	} else {
		if (reconstruct) {
			ans += 'A';
			rec(ind + 1, val + a[ind], true);
		}
		out.first = left;
	}
	out.second = 1;
	return out.first;
}

int main() {
	cin >> N;
	a.resize(N);
	b.resize(N);
	rep(i,0,N) cin >> a[i];
	rep(i,0,N) cin >> b[i];
	rec(0, 0, true);
	cout << ans << endl;
}
