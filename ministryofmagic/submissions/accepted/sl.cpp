// Slow O(C^2 + CP)
#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) x.begin(), x.end()
typedef vector<int> vi;

// BumpAllocator reduces 0.9s -> 0.7
static char buf[450 << 20];
void* operator new(size_t s) {
	static size_t i = sizeof buf;
	assert(s < i);
	return (void*)&buf[i -= s];
}
void operator delete(void*) {}

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	int C, P;
	cin >> C >> P;
	vector<list<int>> votes(P);
	vector<vector<pair<list<int>::iterator, int>>> votesFor(C);
	vi voteCount(C), power(P);
	rep(i,0,P) {
		cin >> power[i];
		rep(j,0,C) {
			int v;
			cin >> v;
			--v;
			votes[i].push_back(v);
			auto it = votes[i].end(); --it;
			votesFor[v].emplace_back(it, i);
			if (j == 0) voteCount[v] += power[i];
		}
	}

	rep(i,0,C-1) {
		int removed = (int)(min_element(all(voteCount)) - voteCount.begin());
		voteCount[removed] = INT_MAX;
		for (auto pa : votesFor[removed]) {
			auto it = pa.first;
			int p = pa.second;
			bool first = (it == votes[p].begin());
			votes[p].erase(it);
			if (first) {
				int v = *votes[p].begin();
				assert(voteCount[v] != INT_MAX);
				voteCount[v] += power[p];
			}
		}
	}
	int remaining = (int)(min_element(all(voteCount)) - voteCount.begin());
	cout << remaining + 1 << endl;
}
