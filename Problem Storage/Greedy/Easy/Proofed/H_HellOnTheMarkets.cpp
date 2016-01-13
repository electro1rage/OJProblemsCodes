/*
reality, be rent!
synapse, break!
Van!shment Th!s World !!
*/
#include <bits/stdc++.h>
using namespace std;

const int MN = 101010;

pair<int, int> a[MN];
bool take[MN];

int main() {
	freopen("hell.in", "r", stdin);
	freopen("hell.out", "w", stdout);
	int n, i;
	long long sum = 0;
	scanf("%d", &n);
	for (i = 0; i < n; ++i) {
		scanf("%d", &a[i].first);
		a[i].second = i;
		sum += a[i].first;
	}
	if (sum % 2) {
		puts("No");
		return 0;
	}

	puts("Yes");

	sum /= 2;
	sort(a, a + n);
	for (i = n - 1; i >= 0; --i) {
		if (sum >= a[i].first) {
			sum -= a[i].first, take[a[i].second] = true;
		}
	}

	for (i = 0; i < n; ++i) {
		if (i) putchar (' ');
		if (take[i]) printf("1");
		else printf("-1");
	}
	puts("");
	return 0;
}
