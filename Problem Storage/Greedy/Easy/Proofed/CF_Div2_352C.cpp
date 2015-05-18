#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for((i)=0;(i)<(int)(n);(i)++)

const int MN = 4010;

int a[MN];

int main() {
	int n;
	scanf("%d", &n);

	int i;
	int sum = 0, zero = 0;
	REP(i, 2 * n) scanf("%d.%d", a + i, a + i), sum += a[i], zero += a[i] == 0;

	int rem = max(0, n - zero);
	sum -= 1000 * rem;

	if (zero >= n) rem = 2 * n - zero;
	else rem = zero;

	while (abs(sum - 1000) <= abs(sum) && rem) {
		--rem, sum -= 1000;
	}

	sum = abs(sum);

	printf("%d.%d%d%d\n", sum / 1000, (sum / 100) % 10, (sum / 10) % 10, sum % 10);
	return 0;
}
