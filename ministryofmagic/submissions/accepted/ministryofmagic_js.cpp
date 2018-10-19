#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

struct Cvotes {
    int vlim;
    vi cvotes;
    vector<bool> removed;
    set<pair<int, int>> rev;

    Cvotes(int C) : vlim(0), cvotes(C), removed(C) {
        rep(i,0,C) rev.emplace(0, i);
    }

    bool add(int who, int delta) {
        rev.erase(pii(cvotes[who], who)); 
        cvotes[who] += delta;
        rev.emplace(cvotes[who], who);
        return hasmaj(who);
    }

    bool hasmaj(int who) {
        if (who < 0 || who >= sz(cvotes) || removed[who]) return false;
        return cvotes[who] >= vlim;
    }

    bool eliminate() {
        int elim = rev.begin()->second;
        rev.erase(rev.begin());
        removed[elim] = true;
        return cvotes[elim] == 0;
    }
};

struct Party {
    int votes;
    int ridx;
    vi rankings;

    Party(int N) : votes(0), ridx(-1), rankings(N) {}

    int who() { 
        assert(0 <= ridx && ridx < sz(rankings));
        return rankings[ridx] - 1;
    }

    bool isrem(const Cvotes& c) {
        if (ridx == -1) return true;
        if (ridx == sz(rankings)) return false;
        return c.removed[who()];
    }

    int advance(Cvotes& c) {
        int ret = -1;
        if (ridx >= 0) if (!isrem(c) && c.add(who(), -votes)) ret = who();
        ridx++;
        if (ridx < sz(rankings)) if (!isrem(c) && c.add(who(), votes)) ret = who();
        return ret;
    }
};

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);

    int C, P;
    cin >> C >> P;
    Cvotes c(C);
    vector<Party> parties(P, Party(C));
    rep(i,0,P) {
        cin >> parties[i].votes;
        c.vlim += parties[i].votes;
        rep(j,0,C) cin >> parties[i].rankings[j];
    }
    c.vlim = c.vlim / 2 + 1;
    while (true) {
        int hasmaj = -1;
        rep(j,0,P) {
            while (parties[j].isrem(c)) {
                hasmaj = parties[j].advance(c);
            }
        }
        if (c.hasmaj(hasmaj)) {
            cout << (hasmaj + 1) << endl;
            return 0;
        }
        while (c.eliminate());
    }
}
