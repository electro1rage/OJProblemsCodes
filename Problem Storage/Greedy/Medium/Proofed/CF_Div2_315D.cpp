#include <bits/stdc++.h>
using namespace std;

const int MAXN = 105;

pair<int, int> nextstate[MAXN];
char a[MAXN], c[MAXN];

int main() {
	int b, d;
	scanf("%d %d", &b, &d);

	scanf("%s %s", a, c);

	int n = strlen(a), m = strlen(c);

	for (int i = 0; i < m; ++i) {
		pair<int, int> temp;
		temp.second = i;
		for (int j = 0; j < n; ++j) {
			if (a[j] == c[temp.second]) {
				++temp.second;
				if (temp.second == m) {
					temp.second = 0;
					++temp.first;
				}
			}
		}
		nextstate[i] = temp;
	}

	int ans = 0, curchar = 0;
	for (int i = 0; i < b; ++i) {
		ans += nextstate[curchar].first;
		curchar = nextstate[curchar].second;
	}

	printf("%d\n", ans / d);
	return 0;
}





