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


int main(){
	ios::sync_with_stdio(0);
    int N;
    cin >> N;
    vector<map<int, string>> ans(N+1);
    vector<int> a(N);
    vector<int> b(N);
    rep(i,0,N)
        cin >> a[i];
    rep(i,0,N)
        cin >> b[i];
    ans[0][0] = "";
    rep(i,0,N) {
        for (auto it : ans[i]) {
            rep(j,0,2) {
                int newVal = it.first;
                string newString = it.second;
                if (j) {
                    newVal += b[i];
                    newString.push_back('B');
                }
                else {
                    newVal -= a[i];
                    newString.push_back('A');
                }
                if (!ans[i+1].count(newVal) || newString < ans[i+1][newVal]) {
                    ans[i+1][newVal] = newString;
                }
            }
        }
    }
    int bestVal = 1e9;
    string bestString;
    for (auto it : ans[N]) {
        int val = abs(it.first);
        if (val < bestVal || (val == bestVal && it.second < bestString)) {
            bestVal = val;
            bestString = it.second;
        }
    }
    cout << bestString << endl;
}
