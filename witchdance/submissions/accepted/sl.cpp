// untested
#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

struct Witch {
	double x, y, r;
};

bool crash(const Witch& a, const Witch& b) {
	double x = b.x - a.x;
	double y = b.y - a.y;
	double dx2 = x*x + y*y;
	if (dx2 > 4) return false;
	if (dx2 <= 1) return true;
	double dx = sqrt(dx2);
	double ang = atan2(y, x);
	double ar = a.r - ang;
	double br = b.r - ang;
	// ar - time is to the right
	// br - time is to the left
	// ar - time = pi - (br - time)
	// ar + br - pi = 2 time
	double time = (ar + br - M_PI) / 2;
	double ar2 = fmod(ar - time, 2*M_PI);
	if (ar2 > M_PI) ar2 -= 2*M_PI;
	if (ar2 < -M_PI) ar2 += 2*M_PI;
	if (fabs(ar2) > M_PI/2) {
		ar += M_PI;
		br += M_PI;
	}
	double t = cos(ar);
	assert(t >= -1e-6);
	assert(fabs(cos(br) + t) < 1e-6);
	return 2*t >= dx;
}

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	int N;
	cin >> N;
	map<pii, vector<Witch>> buckets;
	rep(i,0,N) {
		double x, y, r;
		cin >> x >> y >> r;
		int ix = (int)floor(x);
		int iy = (int)floor(y);
		rep(di,-1,2) rep(dj,-1,2)
			buckets[pii(ix + di, iy + dj)].push_back({x, y, r});
	}

	trav(pa, buckets) {
		vector<Witch>& nearby = pa.second;
		if (sz(nearby) > 15) {
			// (I think 15 is the most points you can fit in a 3x3 square
			// without having any distance < 1. Put 3x3 points regularly spaced
			// in the top left, then 3 below them at a slight angle, and 3 to
			// the right.)
			cout << "crash" << endl;
			return 0;
		}
		rep(i,0,sz(nearby)) rep(j,i+1,sz(nearby)) {
			if (crash(nearby[i], nearby[j])) {
				cout << "crash" << endl;
				return 0;
			}
		}
	}
	cout << "ok" << endl;
}
