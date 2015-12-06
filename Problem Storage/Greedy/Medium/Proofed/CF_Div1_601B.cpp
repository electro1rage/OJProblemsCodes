/*
reality, be rent!
synapse, break!
Van!shment Th!s World !!
*/
#include <bits/stdc++.h>
using namespace std;

struct data {
	int val, i;
	long long sum;
};

long long get_lipschitz(vector<int> a) {
	int n = a.size(), i;
	long long ret = 0;
	stack<data> st;
	st.push({1010101010, 0, 0LL});

	for (i = 1; i < n; ++i) {
		data l = {abs(a[i] - a[i - 1]), i, 0};
		while (l.val >= st.top().val) st.pop();
		l.sum += 1LL * l.val * (l.i - st.top().i) + st.top().sum;
		ret += l.sum;
		st.push(l);
	}

	return ret;
}

int main() {
	int n, q, l, r, i;
	scanf("%d %d", &n, &q);
	vector<int> a(n);
	for (auto &x : a) scanf("%d", &x);

	for (i = 0; i < q; ++i) {
		scanf("%d %d", &l, &r);
		printf("%I64d\n", get_lipschitz(vector<int> (a.begin() + l - 1, a.begin() + r)));
	}
	return 0;
}
