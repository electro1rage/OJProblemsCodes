#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for((i)=0;(i)<(int)(n);++(i))

const int MN = 1000010;

bool vst[MN];
char s[MN];
int n;

bool is_in(int node) {
	return s[node] == '1' && s[(node - 1 + n) % n] == '0';
}

bool is_out(int node) {
	return s[node] == '0' && s[(node - 1 + n) % n] == '1';
}

void DFS_left(int node) {
	vst[node] = true;
	if (is_in(node) || is_out(node)) return;
	DFS_left((node - 1 + n) % n);
}

void DFS_right(int node) {
	vst[node] = true;
	if (is_in(node) || is_out(node)) return;
	DFS_right((node + 1) % n);
}

void DFS(int node) {
	vst[node] = true;
	DFS_left((node - 1 + n) % n);
	DFS_right((node + 1) % n);
}

int get_left(int node) {
	return (node - 1 + n) % n;
}

int get_right(int node) {
	return (node + 1) % n;
}

int main() {
	scanf("%s", s);
	n = strlen(s);

	int ans = 0, i;
	REP(i, n) {
		if (is_out(i)) {
			int l = get_left(i), r = get_right(i);
			if (is_in(l) && is_in(r) && !vst[i]) ++ans, DFS(i);
			else {
				if (!vst[r]) ++ans, DFS(r);
				if (!vst[l]) ++ans, DFS(l);
			}
		}
	}

	printf("%d\n", ans);
	return 0;
}
