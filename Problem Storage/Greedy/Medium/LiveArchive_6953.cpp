/*
reality, be rent!
synapse, break!
Van!shment Th!s World !!
*/
#include <bits/stdc++.h>
using namespace std;

int b[500101][3];
int st[501001], X;
bool vst[501001];
long long cnt[500101];
stack<pair<bool, int> > sk;

void dfs(int n) {
	sk.push({false, n});
	int node;
	bool p;
	while (!sk.empty()) {
		node = sk.top().second, p = sk.top().first, sk.pop();
		if (node == 0) continue;
		if (p == true) {
			st[X] = node, ++X;
			continue;
		}
		if (vst[node]) continue;
		vst[node] = true;
		sk.push({true, node});
		if (!vst[b[node][0]]) sk.push({false, b[node][0]});
		if (!vst[b[node][1]]) sk.push({false, b[node][1]});
	}
}

void pre_process() {
	for (X = X - 1; X >= 0; --X) {
		int node = st[X];
		cnt[b[node][b[node][2]]] += (cnt[node] + 1) / 2;
		cnt[b[node][b[node][2] ^ 1]] += cnt[node] - (cnt[node] + 1) / 2;
	}
}


int main() {
	int m;
	long long n;
	while (~scanf("%lld %d", &n, &m)) {
		int i;
		if (m > 500000) return 0;
		for (i = 1; i <= m; ++i) {
			char c;
			scanf(" %c %d %d", &c, &b[i][0], &b[i][1]);
			b[i][2] = string("LR").find(c);
		}
		X = 0;
		memset(vst, 0, sizeof vst);
		memset(cnt, 0, sizeof cnt);
		dfs(1);
		cnt[1] = n;
		pre_process();

		for (i = 1; i <= m; ++i) printf("%c", "LR"[b[i][2] ^ (cnt[i] & 1)]);puts("");
	}
	return 0;
}
