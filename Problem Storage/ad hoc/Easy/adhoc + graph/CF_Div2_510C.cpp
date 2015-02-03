#include <bits/stdc++.h>
using namespace std;

vector<string> v;


bool graph[26][26];
bool vst[26];
int num[26];

bool cycle(int a, int g) {
	if (a == g && vst[a]) return 1;
	if (vst[a]) return 0;
	vst[a] = 1;

	for (int i = 0; i < 26; ++i)
		if (graph[a][i] && cycle(i, g)) return 1;

	return 0;
}

void DFS(int node, int dpth) {
	num[node] = max(num[node], dpth);

	for (int i = 0; i < 26; ++i)
		if (graph[node][i])
			DFS(i, dpth + 1);
}

int main() {
	int n;
	cin >> n;

	v.resize(n);
	for (auto &x : v)
		cin >> x;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < i; ++j) {
			if (v[i].size() < v[j].size() && v[j].substr(0, v[i].size()) == v[i]) {
				puts("Impossible");
				return 0;
			}
		}
	}

	for (int i = 0; i < n - 1; ++i) {
		for (int j = 0; j < n; ++j) {
			if (v[i].size() <= j || v[i + 1].size() <= j) break;
			if (v[i].substr(0, j) == v[i + 1].substr(0, j)) {
				if (v[i][j] != v[i + 1][j]) {
					graph[v[i][j] - 'a'][v[i + 1][j] - 'a'] = 1;
				}
			}
		}
	}

	for (int i = 0; i < 26; ++i) {
		memset(vst, 0, sizeof vst);
		if (cycle(i, i)) {
			puts("Impossible");
			return 0;
		}
	}

	for (int i = 0; i < 26; ++i)
		num[i] = -1;

	for (int i = 0; i < 26; ++i) {
		if (num[i] == -1) {
			DFS(i, 0);
		}
	}

	vector<char> res;

	for (int i = 0; i < 26; ++i)
		for (int j = 0; j < 26; ++j) {
			if (num[j] == i) {
				res.push_back(j + 'a');
			}
		}


	for (auto &x : res)
		cout << x;cout << endl;
	return 0;
}
