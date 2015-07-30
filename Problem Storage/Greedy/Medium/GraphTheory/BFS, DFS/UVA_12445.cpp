#include <bits/stdc++.h>
using namespace std;

const int MVAL = 1010101010;

int l[] = {2, 3, 4, 5, 6, 12, 7, 8, 9, 10, 11, 1};
int r[] = {1, 2, 3, 4, 5, 7, 8, 9, 10, 11, 12, 6};
int all[] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 1};

long long get_hash(vector<int> &a) {
	int i;
	long long ret = 0;
	for (i = 0; i < 12; ++i) ret = ret * 13 + a[i];
	return ret;
}

vector<int> get_unhash(long long a) {
	vector<int> ret;
	while (a) ret.push_back(a % 13), a /= 13;
	reverse(ret.begin(), ret.end());
	return ret;
}

long long get_next(int p[12], long long hashed, bool clockwise) {
	vector<int> a = get_unhash(hashed);
	vector<int> temp(12);
	int i;
	for (i = 0; i < 12; ++i) {
		if (clockwise) temp[i] = a[p[i] - 1];
		else temp[p[i] - 1] = a[i];
	}
	return get_hash(temp);
}

unordered_map<long long, int> dpth;
unordered_set<long long> vst;
int clr;

void bfs() {
	int level = 0, sz, i, j;
	vector<int> a(12);
	for (i = 1; i <= 12; ++i) a[i - 1] = i;
	long long s = get_hash(a);

	queue<long long> q; q.push(s);
	dpth[s] = 0;

	while (!q.empty()) {
		sz = q.size();
		for (i = 0; i < sz; ++i) {
			long long node = q.front(); q.pop();
			long long move[] = {get_next(l, node, true), get_next(r, node, true), get_next(all, node, true),
										get_next(l, node, false), get_next(r, node, false), get_next(all, node, false)};

			for (j = 0; j < 6; ++j) if (!dpth.count(move[j])) dpth[move[j]] = level + 1, q.push(move[j]);
		}
		++level;
		if (level == 10) break;
	}
}

int get_ans(long long s) {
	vst.clear();
	if (dpth.count(s)) return dpth[s];
	queue<long long> q; q.push(s);
	vst.insert(s);

	int level = 0, sz, i, j;
	while (!q.empty()) {
		sz = q.size();
		for (i = 0; i < sz; ++i) {
			long long node = q.front(); q.pop();
			long long move[] = {get_next(l, node, true), get_next(r, node, true), get_next(all, node, true),
										get_next(l, node, false), get_next(r, node, false), get_next(all, node, false)};

			for (j = 0; j < 6; ++j) if (dpth.count(move[j])) return level + 1 + dpth[move[j]];
			for (j = 0; j < 6; ++j) if (vst.find(move[j]) == vst.end()) vst.insert(move[j]), q.push(move[j]);

		}
		++level;
	}
}

int main() {
	bfs();
	int T, x, i;
	scanf("%d", &T);
	while (T--) {
		long long h = 0;
		for (i = 0; i < 12; ++i) scanf("%d", &x), h = h * 13 + x;

		printf("%d\n", get_ans(h));
	}
	return 0;
}
