#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = (a); i < int(b); ++i)
#define rrep(i, a, b) for(int i = (a) - 1; i >= int(b); --i)
#define trav(it, v) for(auto &it : (v))
#define all(v) (v).begin(), (v).end()
#define what_is(x) cerr << #x << " is " << x << endl;
#define sz(x) (int)(x).size()

typedef double fl;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpi;

struct Party {
    int votes;
    vector<int> preference;
};

int main(){
	ios::sync_with_stdio(0);
    int C, P;
    cin >> C >> P;
    vector<Party> parties(P);
    unordered_set<int> remaining;
    rep(i,0,P) {
        cin >> parties[i].votes;
        parties[i].preference.resize(C);
        rep(j,0,C)
            cin >> parties[i].preference[j];
        reverse(all(parties[i].preference));
        remaining.insert(parties[i].preference.back());
    }
    while (sz(remaining) > 1) {
        map<int, int> votes;
        rep(i,0,P) {
            while (!remaining.count(parties[i].preference.back()))
                parties[i].preference.pop_back();
            votes[parties[i].preference.back()] += parties[i].votes;
        }
        int minVal = 1e9;
        int minInd;
        for (auto it : votes) {
            if (it.second < minVal) {
                minVal = it.second;
                minInd = it.first;
            }
        }
        remaining.clear();
        for (auto it : votes) {
            if (it.first != minInd) {
                remaining.insert(it.first);
            }
        }
    }
    cout << *remaining.begin() << endl;
}
