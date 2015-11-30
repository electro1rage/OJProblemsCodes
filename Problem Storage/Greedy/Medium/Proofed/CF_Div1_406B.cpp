/*
reality, be rent!
synapse, break!
Van!shment Th!s World !!
*/
#include <bits/stdc++.h>
using namespace std;


const int MN = 1000000;

int main() {
	int n, x, i;
	set<int> st;
	vector<int> a, ans;
	scanf("%d", &n);

	long long sum = 0;
	for (i = 0; i < n; ++i) {
		scanf("%d", &x);
		sum += x - 1;
		st.insert(x);
	}

	for (i = 1; i <= MN; ++i) {
		if (st.find(i) == st.end() && st.find(MN - i + 1) != st.end()) {
			sum -= MN - i, st.insert(i), ans.push_back(i);
		}
	}

	for (i = 1; i <= MN; ++i) {
		if (st.find(i) == st.end() && st.find(MN - i + 1) == st.end()) {
			a.push_back(i), a.push_back(MN - i + 1);
		}
	}

	while (sum) sum -= MN - 1, ans.push_back(a.back()), a.pop_back(), ans.push_back(a.back()), a.pop_back();

	int sz = ans.size();
	printf("%d\n", sz);
	for (i = 0; i < sz; ++i) {
		if (i) putchar (' ');
		printf("%d", ans[i]);
	}
	puts("");
	return 0;
}
