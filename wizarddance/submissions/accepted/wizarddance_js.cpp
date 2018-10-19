#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

struct Ed {
    int label;
    int to;
    bool left;

    Ed(int label, int to, bool left) : label(label), to(to), left(left) {}

    bool operator<(const Ed& ot) const {
        if (label != ot.label) return label < ot.label;
        return left;
    }
};

vector<vector<Ed>> eds;
vector<bool> seenPos, seenWiz, res;

void dfs(int at, bool cyclesOk, int start) {
    cerr << "dfs at " << at << endl;
    if (sz(eds[at]) > 2 && !cyclesOk) return;
    seenPos[at] = true;
    vector<Ed> tr;
    trav(it, eds[at]) {
        if (seenWiz[it.label]) continue;
        if (it.to != start && seenPos[it.to]) continue;
        tr.push_back(it);
    }
    assert(sz(tr) <= 2);
    if (sz(tr) == 2) {
        if (tr[1] < tr[0]) swap(tr[1], tr[0]);
        tr.pop_back();
    }
    if (!tr.empty()) {
        Ed it = tr[0];
        seenWiz[it.label] = true;
        res[it.label] = it.left;
        dfs(it.to, cyclesOk, start);
    }
}

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);

    int N;
    cin >> N;
    seenPos.resize(N);
    seenWiz.resize(N);
    res.resize(N);
    eds.resize(N);
    vector<int> poses;
    rep(i,0,N) {
        int p;
        cin >> p;
        int l = (i + p) % N;
        int r = (i - p + N) % N;
        eds[l].emplace_back(i, r, true);
        eds[r].emplace_back(i, l, l == r);
        poses.push_back(l);
    }

    trav(it, eds) {
        if (it.empty()) {
            cout << "no dance" << endl;
            return 0;
        }
    }
    rep(i,0,N) {
        if (eds[i].size() == 1) {
            dfs(i, false, -1);
        }
    }
    rep(i,0,N) {
        if (!seenWiz[i]) {
            dfs(poses[i], true, poses[i]);
        }
    }
    rep(i,0,N) cout << "RL"[res[i]];
    cout << endl;
}
