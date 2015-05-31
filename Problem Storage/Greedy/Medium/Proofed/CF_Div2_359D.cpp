#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for((i)=0;(i)<(int)(n);++(i))

const int MN = 301010;

int a[MN];
int ljump[MN], rjump[MN];
int n;

void get_jumps(int jump[]) {
	for (int i = n - 1; i >= 0; --i) jump[i] = 1;

	for (int i = n - 1; i >= 0; --i) {
		int curjump = jump[i];
		while (i + curjump < n && a[i + curjump] % a[i] == 0) {
			curjump += jump[i + curjump];
		}
		jump[i] = curjump;
	}
}

int main() {
	scanf("%d", &n);

	int i;
	REP(i, n) scanf("%d", a + i);

	get_jumps(rjump);
	reverse(a, a + n);
	get_jumps(ljump);
	reverse(ljump, ljump + n);

	int maxi = -5;
	REP(i, n) maxi = max(maxi, rjump[i] + ljump[i]);

	vector<int> temp;
	REP(i, n) if (rjump[i] + ljump[i] == maxi) temp.push_back(i - ljump[i] + 2);

	sort(temp.begin(), temp.end());

	vector<int> ans;
	int sz = temp.size();

	REP(i, sz) if (i == 0 || temp[i] != temp[i - 1]) ans.push_back(temp[i]);

	sz = ans.size();
	printf("%d %d\n", sz, maxi - 2);

	REP(i, sz) {
		if (i) printf(" ");
		printf("%d", ans[i]);
	}
	puts("");
	return 0;
}
