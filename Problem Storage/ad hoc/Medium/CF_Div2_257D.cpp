#include <bits/stdc++.h>
using namespace std;

#define NEGATIVE 0
#define POSITIVE 1

bool flip[100005];
bool sign[100005];
int a[100005];

int main() {
	int n;
	scanf("%d", &n);

	for (int i = 1; i <= n; ++i)
		scanf("%d", a + i);

	sign[n] = POSITIVE;
	int sum = a[n];

	for (int i = n - 1; i > 0; --i) {
		if (sum >= a[i]) {
			sign[i] = NEGATIVE;
			sum -= a[i];
		} else {
			flip[i + 1] = true;
			sign[i] = POSITIVE;
			sum = a[i] - sum;
		}
	}

	char ans[2];
	ans[NEGATIVE] = '-';
	ans[POSITIVE] = '+';
	int x = 0;
	for (int i = 1; i <= n; ++i) {
		x ^= flip[i];
		printf("%c", ans[sign[i] ^ x]);
	}
	return 0;
}




