#include "validator.h"

void run() {
	int c = Int(1, 10000);
	Space();
	int p = Int(1, 100);
	Endl();

	for (int i = 0; i < p; i++) {
		Int(1, 1000000);
		Space();
		vector<int> perm = SpacedInts(c, 1, c);
		AssertUnique(perm);
	}
}
