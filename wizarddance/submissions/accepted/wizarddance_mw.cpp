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

set<int> S[300005];
int p[300005];
int N;
bool isAssigned[300005];
char ans[300005];
queue<int> q;
int numAssigned;

int getPos(int pos) {
    pos %= N;
    if (pos < 0)
        pos += N;
    return pos;
}

void add(int pos, int ind) {
    S[getPos(pos)].insert(ind);
}

void remove(int pos, int ind) {
    pos = getPos(pos);
    if (S[pos].count(ind)) {
        S[pos].erase(ind);
        if (sz(S[pos]) == 1) {
            q.push(pos);
        }
    }
}

void assign(int pos, int ind) {
    pos = getPos(pos);
    if(!isAssigned[pos]) {
        isAssigned[pos] = true;
        numAssigned++;
        if (getPos(ind+p[ind]) == pos) {
            ans[ind] = 'L';
        } else {
            ans[ind] = 'R';
        }
        remove(ind-p[ind], ind);
        remove(ind+p[ind], ind);
    }
}

int main(){
	ios::sync_with_stdio(0);
    cin >> N;
    rep(i,0,N) {
        cin >> p[i];
        add(i+p[i], i);
        add(i-p[i], i);
    }
    rep(i,0,N) {
        if (sz(S[i]) == 0) {
            cout << "no dance" << endl;
            return 0;
        }
        if (sz(S[i]) == 1) {
            q.push(i);
        }
    }
    int assigningPos = 0;
    while (numAssigned < N) {
        while (!q.empty()) {
            int pos = q.front();
            q.pop();
            if (isAssigned[pos]) {
                continue;
            }
            if (sz(S[pos]) == 0) {
                cout << "no dance" << endl;
                return 0;
            }
            assign(pos, *S[pos].begin());
        }
        if (!ans[assigningPos]) {
            assign(assigningPos+p[assigningPos], assigningPos);
        }
        assigningPos++;
    }
    ans[N] = 0;
    cout << string(ans) << endl;
}
