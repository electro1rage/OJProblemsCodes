#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;
const int SQRTN = 318;

int s[MAXN];
int maxi[SQRTN];
int n, sqrtn;

void process() {
	memset(maxi, 0, sizeof maxi);
	for (int i = 0; i < n; ++i) {
		int &cur = maxi[i / sqrtn];
		cur = max(cur, s[i]);
	}
}

int get_max_left(int i) {
	int ind = i;
	while ((i + 1) % sqrtn) {
		if (s[i] > s[ind]) return s[i];
		--i;
	}
	while (i >= 0) {
		if (maxi[i / sqrtn] > s[ind]) {
			while (true) {
				if (s[i] > s[ind]) return s[i];
				--i;
			}
		}
		i -= sqrtn;
	}

	return -1;
}

int get_ans() {
	process();
	int ans = 0;

	for (int i = 0; i < n; ++i) {
		int maxleft = get_max_left(i);
		ans = max(ans, s[i] ^ maxleft);
	}

	return ans;
}

int main() {
	scanf("%d", &n);

	for (int i = 0; i < n; ++i)
		scanf("%d", s + i);


	for (sqrtn = 1; sqrtn * sqrtn <= n; ++sqrtn);
	--sqrtn;

	int ans = get_ans();
	reverse(s, s + n);
	ans = max(ans, get_ans());

	printf("%d\n", ans);
	return 0;
}









