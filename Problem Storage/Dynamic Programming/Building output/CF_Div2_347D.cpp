#include <bits/stdc++.h>
using namespace std;

const int MN = 105;

int memo[MN][MN][MN];
char s1[MN], s2[MN];
char virus[MN];
int n, m, k;

vector<int> properprefix;

void get_failurefunction() {
	for (int i = 1, l = 0; i < k; ++i) {
		while (l > 0 && virus[l] != virus[i]) l = properprefix[l - 1];
		if (virus[l] == virus[i]) ++l;
		properprefix[i] = l;
	}
}

int get_max(int i, int j, int l) {
	if (l == k) return -10000000;
	if (i == n || j == m) return 0;

	int &ret = memo[i][j][l];
	if (ret == -1) {
		ret = get_max(i + 1, j, l);
		ret = max(ret, get_max(i, j + 1, l));
		if (s1[i] == s2[j]) {
			int nl = l;
			while (nl > 0 && s1[i] != virus[nl]) nl = properprefix[nl - 1];
			if (s1[i] == virus[nl]) ++nl;
			ret = max(ret, get_max(i + 1, j + 1, nl) + 1);
		}
	}
	return ret;
}

void get_ans(int i, int j, int l) {
	if (i == n || j == m) return;

	int ret1 = get_max(i + 1, j, l);
	int ret2 = get_max(i, j + 1, l);
	int ret3 = -1;
	if (s1[i] == s2[j]) {
		int nl = l;
		while (nl > 0 && s1[i] != virus[nl]) nl = properprefix[nl - 1];
		if (s1[i] == virus[nl]) ++nl;
		ret3 = get_max(i + 1, j + 1, nl) + 1;
		if (ret3 >= ret1 && ret3 >= ret2) {
			printf("%c", s1[i]);
			get_ans(i + 1, j + 1, nl);
			return;
		}
	}

	if (ret1 >= ret2 && ret1 >= ret3) get_ans(i + 1, j, l);
	else get_ans(i, j + 1, l);
}

int main() {
	scanf("%s", s1);
	scanf("%s", s2);
	scanf("%s", virus);

	n = strlen(s1), m = strlen(s2), k = strlen(virus);

	properprefix.resize(k);
	get_failurefunction();

	memset(memo, -1, sizeof memo);
	if (get_max(0, 0, 0) == 0) {
		printf("0\n");
		return 0;
	}

	get_ans(0, 0, 0); puts("");
	return 0;
}
