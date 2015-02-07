#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	scanf("%d", &n);

	vector<int> a(n);
	int avg = 0;
	for (auto &x : a) {
		scanf("%d", &x);
		avg += x;
	}

	if (avg % n)
		printf("%d\n", n - 1);
	else
		printf("%d\n", n);
	return 0;
}


