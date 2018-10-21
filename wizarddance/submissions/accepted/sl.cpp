#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
typedef vector<int> vi;

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	int N;
	cin >> N;
	vi adj(N), deg(N);
	vi as(N), bs(N), alt(N);
	rep(i,0,N) {
		int p;
		cin >> p;
		int b = (i - p + N) % N;
		int a = (i + p) % N;
		deg[a]++;
		deg[b]++;
		adj[a] ^= i;
		adj[b] ^= i;
		as[i] = a;
		bs[i] = b;
		alt[i] = a ^ b;
	}

	vi deg1, target(N, -1);
	rep(i,0,N) if (deg[i] == 0) {
		cout << "no dance" << endl;
		return 0;
	}
	rep(i,0,N) if (deg[i] == 1) deg1.push_back(i);
	while (!deg1.empty()) {
		int x = deg1.back();
		deg1.pop_back();
		int i = adj[x];
		int y = alt[i] ^ x;
		target[i] = x;
		deg[x]--;
		deg[y]--;
		adj[x] ^= i;
		adj[y] ^= i;
		if (deg[y] == 0) {
			cout << "no dance" << endl;
			return 0;
		}
		if (deg[y] == 1) deg1.push_back(y);
	}

	rep(i,0,N) if (target[i] == -1) {
		int person = i, pos = as[i], mini = INT_MAX;
		do {
			mini = min(mini, person);
			pos ^= alt[person];
			person ^= adj[pos];
		} while (person != i);
		person = mini;
		pos = as[person];
		do {
			target[person] = pos;
			pos ^= alt[person];
			person ^= adj[pos];
		} while (person != mini);
	}

	rep(i,0,N) {
		assert(target[i] == as[i] || target[i] == bs[i]);
		if (target[i] == as[i]) cout << 'L';
		else cout << 'R';
	}
	cout << endl;
}
