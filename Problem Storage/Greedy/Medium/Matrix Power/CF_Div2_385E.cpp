/*
reality, be rent!
synapse, break!
Van!shment Th!s World !!
*/
#include <bits/stdc++.h>
using namespace std;

const int MN = 6;

int n, sx, sy, dx, dy;
long long t;

vector<vector<int> > get_i() {
	vector<vector<int> > ret(MN, vector<int> (MN));
	int i;
	for (i = 0; i < MN; ++i) ret[i][i] = 1;
	return ret;
}

vector<vector<int> > multiply(vector<vector<int> > a, vector<vector<int> > b) {
	vector<vector<int> > ret(MN, vector<int> (MN));
	int i, j, k;
	for (i = 0; i < MN; ++i) {
		for (j = 0; j < MN; ++j) {
			for (k = 0; k < MN; ++k) ret[i][j] = (ret[i][j] + (1LL * a[i][k] * b[k][j]) % n) % n;
		}
	}
	ret[0][0] = (ret[0][0] - 1 + n) % n + 1;
	ret[0][1] = (ret[0][1] - 1 + n) % n + 1;
	return ret;
}

vector<vector<int> > get_power(vector<vector<int> > a, long long p) {
	if (p == 0) return get_i();
	if (p % 2) return multiply(a, get_power(a, p - 1));
	return get_power(multiply(a, a), p / 2);
}

int main() {
	scanf("%d %d %d %d %d %I64d", &n, &sx, &sy, &dx, &dy, &t);

	if (t == 0) {
		printf("%d %d\n", sx, sy);
		return 0;
	}

	vector<vector<int> > A(MN, vector<int> (MN)), B = A;
	A[0] = {sx, sy, dx, dy, 0, 1};

	B[0] = {2, 1, 1, 1, 0, 0};
	B[1] = {1, 2, 1, 1, 0, 0};
	B[2] = {1, 0, 1, 0, 0, 0};
	B[3] = {0, 1, 0, 1, 0, 0};
	B[4] = {1, 1, 1, 1, 1, 0};
	B[5] = {0, 0, 0, 0, 1, 1};

	B = get_power(B, t);
	B = multiply(A, B);
	printf("%d %d\n", B[0][0], B[0][1]);
	return 0;
}
