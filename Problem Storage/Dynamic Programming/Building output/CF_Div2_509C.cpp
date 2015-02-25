#include <bits/stdc++.h>
using namespace std;

#define LESS 0
#define EQUAL 1
#define MORE 2

const int MAXD = 350;
const int MAXS = 300;

int wantedsum;
int memo[MAXD + 5][MAXS + 5][3];

char ans[MAXD + 5];
int cur[MAXD + 5];
int pre[MAXD + 5];

int get_state(int state, int predigit, int curdigit) {
	if (state != EQUAL) return state;
	if (curdigit > predigit) return MORE;
	if (curdigit < predigit) return LESS;
	return EQUAL;
}

bool get_next(int i, int sum, int state) {
	if (sum < 0) return false;
	if (state == LESS) return false;
	if (i == MAXD) {
		return sum == 0 && state == MORE;
	}

	int &ret = memo[i][sum][state];
	if (ret == -1) {
		for (int j = 0; j < 10; ++j) {
			if (get_next(i + 1, sum - j, get_state(state, pre[i], j))) {
				cur[i] = j;
				return ret = true;
			}
		}
	}
	return ret = false;
}

int main() {
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; ++i) {
		scanf("%d", &wantedsum);
		memset(memo, -1, sizeof memo);
		if (!get_next(0, wantedsum, EQUAL)) printf("kawaii");
		int nonzero = 0;
		while (!cur[nonzero]) {
			++nonzero;
		}
		int cnt, j;
		for (cnt = 0, j = nonzero; j < MAXD; ++j, ++cnt)
			ans[cnt] = cur[j] + '0';
		ans[cnt] = 0;
		printf("%s\n", ans);
		memcpy(pre, cur, sizeof cur);
	}
	return 0;
}

