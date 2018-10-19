#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int MX = 100 * 100;

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);

    int N;
    cin >> N;
    vi A(N), B(N);
    rep(i,0,N) cin >> A[i];
    reverse(all(A));
    rep(i,0,N) cin >> B[i];
    reverse(all(B));

    vector<vector<bool>> reach(N+1, vector<bool>(2 * MX + 1, false));
    reach[0][MX] = true;
    rep(i,0,N) {
        rep(j,0,2*MX+1) {
            if (reach[i][j]) {
                reach[i+1][j + A[i]] =
                    reach[i+1][j - B[i]] = true;
            }
        }
    }
    vector<int> starts;
    rep(i,0,MX+1) {
        if (reach[N][MX + i]) {
            starts.push_back(MX + i);
        }
        if (reach[N][MX - i]) {
            starts.push_back(MX - i);
        }
        if (!starts.empty()) break;
    }
    set<string> answers;
    trav(s, starts) {
        int start = s;
        string res;
        rep(i,0,N) {
            if (reach[N - i - 1][start - A[N - i - 1]]) {
                res += 'A';
                start -= A[N - i - 1];
            }
            else if (reach[N - i - 1][start + B[N - i - 1]]) {
                res += 'B';
                start += B[N - i - 1];
            }
        }
        answers.insert(res);
    }
    cout << *answers.begin() << endl;
}
