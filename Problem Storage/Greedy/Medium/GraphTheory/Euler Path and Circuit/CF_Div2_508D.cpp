#include <bits/stdc++.h>
using namespace std;

const int MN = 3851;

map<string, int> mx;
string xm[MN];

pair<int, int> p[MN];
int edge[MN][MN];
char s[4];
string ans = "";

void get_ans(int node) {
	int sz = MN, i;
	for (i = 0; i < sz; ++i) {
		if (edge[node][i]) {
			--edge[node][i], get_ans(i);
		}
	}
	ans += xm[node][1];
}

int main() {
	int n, X = 0, sz, i, j;
	scanf("%d", &n);
	for (i = 0; i < n; ++i) {
		scanf("%s", s);
		string temp1 = string("") + s[0] + s[1], temp2 = string("") + s[1] + s[2];
		if (!mx.count(temp1)) mx[temp1] = X, xm[X] = temp1, ++X;
		if (!mx.count(temp2)) mx[temp2] = X, xm[X] = temp2, ++X;
		++p[mx[temp1]].first, ++p[mx[temp2]].second;
		++edge[mx[temp1]][mx[temp2]];
	}

	int node = 0;
	sz = 0;
	for (i = 0; i < X; ++i) {
		if (abs(p[i].first - p[i].second) > 1) {
			puts("NO");
			return 0;
		}
		if (p[i].first > p[i].second) node = i;
		if (abs(p[i].first - p[i].second) == 1) ++sz;
	}

	if (sz >= 3) {
		puts("NO");
		return 0;
	}

	get_ans(node);
	ans += xm[node][0];

	sz = ans.size();
	if (sz != n + 2) {
		puts("NO");
		return 0;
	}

	reverse(ans.begin(), ans.end());

	puts("YES");
	puts(ans.c_str());

	return 0;
}
