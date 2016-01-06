/*
reality, be rent!
synapse, break!
Van!shment Th!s World !!
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, x, sum = 0, maxi = -1, i;
	scanf("%d", &n);
	for (i = 0; i < n; ++i) scanf("%d", &x), sum += x, maxi = max(maxi, x);
	if (n <= 2) puts("0");
	else printf("%d\n", min(sum / 3, sum - maxi));
	return 0;
}
