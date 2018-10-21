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

struct Witch {
    double x, y, r;
};

bool intersect(Witch w1, Witch w2) {
    double dx = w1.x - w2.x;
    double dy = w1.y - w2.y;
    double dis = sqrt(dx*dx + dy*dy);
    if (dis <= 1) {
        return true;
    }
    double rdiff = w1.r - w2.r;
    if (rdiff < 0)
        rdiff += 2*M_PI;
    rdiff = abs(rdiff);
    double u = abs((M_PI - rdiff) / 2);
    if (u < M_PI/3) {
        double minDis = dis / (2 * cos(u));
        if (minDis <= 1)
            return true;
    }
    return false;
}

map<pair<int, int>, vector<Witch>> M;
int main(){
	ios::sync_with_stdio(0);
    int N;
    cin >> N;
    rep(i,0,N) {
        Witch w;
        cin >> w.x >> w.y >> w.r;
        rep(j,((int)floor(w.x))-2,((int)ceil(w.x))+3)
            rep(k,((int)floor(w.y))-2,((int)ceil(w.y))+3) {
                M[make_pair(j, k)].push_back(w);
            }
    }
    for (auto it : M) {
        rep(i,0,sz(it.second))
            rep(j,i+1,sz(it.second)) {
                if (intersect(it.second[i], it.second[j])) {
                    cout << "crash" << endl;
                    return 0;
                }
            }
    }
    cout << "ok" << endl;
}
