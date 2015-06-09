#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for((i)=0;(i)<(int)(n);++(i))

string ans[] = {"Daenerys", "Stannis"};

void get_ans(int odd, int even, int parity, bool last, bool p, int turns) {
	if (turns == 0) {
		cout << ans[parity] << endl;
		return ;
	}
	int a[2] = {turns / 2, (turns + 1) / 2};
	if (a[!last] < odd && a[!last] < even) {
		cout << ans[last] << endl;
		return ;
	}

	int mini = min(even, odd);

	int i;
	REP(i, turns) {
		if (p == last) {
			if (odd > even) --odd, parity = !parity;
			else if (even > odd) --even;
			else printf("kawaii");
		} else {
			if (mini == 0) {
				if (odd) --odd, parity = !parity;
				if (even) --even;
			} else if (even == mini) --even, --mini;
			else if (odd == mini) --odd, --mini, parity = !parity;
		}
		p = !p;
	}

	cout << ans[parity] << endl;
}

int main() {
	int n, k, i;
	scanf("%d %d", &n, &k);

	int parity = 0, odd = 0, x;
	REP(i, n) scanf("%d", &x), odd += x % 2, parity = (parity + x) % 2;

	get_ans(odd, n - odd, parity, (n - k) % 2, 1, (n - k));
	return 0;
}
