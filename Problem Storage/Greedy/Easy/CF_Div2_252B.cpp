#include <bits/stdc++.h>
using namespace std;

bool isGood(vector<int> &a) {
	vector<int> v1 = a, v2 = a;
	sort(v1.begin(), v1.end());
	sort(v2.rbegin(), v2.rend());

	if (v1 == a || v2 == a) {
		return 0;
	}
	return 1;
}

int main() {
	int n;
	scanf("%d", &n);

	vector<int> v(n);

	for (auto &x : v)
		scanf("%d", &x);

	if (n == 1 || n == 2) {
		printf("-1\n");
	} else if (n == 3 && v.back() == v.front()){
		printf("-1\n");
	} else {
		bool good = 0;
		for (auto &x : v)
			good |= x != v.front();
		if (!good) {
			printf("-1\n");
		} else {
			for (int i = 0; i < n; ++i)
				for (int j = i; j < n; ++j) {
					if (v[i] != v[j]) {
						swap(v[i], v[j]);
						if (isGood(v)) {
							printf("%d %d\n", i + 1, j + 1);
							return 0;
						}
						swap(v[i], v[j]);
					}
				}
			printf("electro__rage\n");
		}
	}
	return 0;
}



