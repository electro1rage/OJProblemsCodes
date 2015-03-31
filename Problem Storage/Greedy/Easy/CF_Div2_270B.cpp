#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;
const int MAXVAL = 2e9 + 5;

int arr[MAXN];

int main() {
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; ++i)
		scanf("%d", arr + i);

	arr[n] = MAXVAL;

	int i;
	for (i = n - 1; i >= 0; --i)
		if (arr[i] > arr[i + 1]) break;

	printf("%d\n", i + 1);
	return 0;
}
