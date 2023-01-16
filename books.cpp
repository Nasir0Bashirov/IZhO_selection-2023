#include <cstdio>
#include <vector>
#include "books.h"
using namespace std;

void Solve(int N) {
	vector<int> S(N);

	for (int i = 0; i < N; ++i) {
		S[i] = 1;
	}

	int M = Query(S);

	vector<int> R(N);

	for (int i = 0; i < N; ++i) {
		R[i] = i + 1;
	}

	Answer(R);
}
