/*
reality, be rent!
synapse, break!
Van!shment Th!s World !!
*/
#include <bits/stdc++.h>
using namespace std;

const int MN = 26;

bool edge[MN][MN], vst[MN], have[MN], memo[MN][MN][MN];
int clr[MN];

string A = "";
string V = "AEIUO";
string C = "";

int get_num(char c) {
	return c - 'A';
}

bool dfs(int node, bool b, vector<int> &a, vector<int> &c) {
	if (clr[node] == -1) clr[node] = b;
	else if (clr[node] != b) return false;
	if (vst[node]) return true;
	vst[node] = true;

	if (b) a.push_back(node);
	else c.push_back(node);

	int i;
	for (i = 0; i < 26; ++i) {
		if (edge[node][i]) {
			if (!dfs(i, !b, a, c)) return false;
		}
	}
	return true;
}

bool is_good(int i, int c1, int c2, vector<vector<int> > &A, vector<vector<int> > &B, vector<char> &vow, vector<char> &con) {
	if (i == A.size()) return c1 <= V.size() && c2 <= C.size();
	if(memo[i][c1][c2]) return false;
	memo[i][c1][c2] = true;
	if (is_good(i + 1, c1 + A[i].size(), c2 + B[i].size(), A, B, vow, con)) {
		for (auto &x : A[i]) vow.push_back(x + 'A');
		for (auto &x : B[i]) con.push_back(x + 'A');
		return true;
	}
	if (is_good(i + 1, c1 + B[i].size(), c2 + A[i].size(), A, B, vow, con)) {
		for (auto &x : B[i]) vow.push_back(x + 'A');
		for (auto &x : A[i]) con.push_back(x + 'A');
		return true;
	}
	return false;
}

int main() {
	freopen("javanese.in", "r", stdin);
	freopen("javanese.out", "w", stdout);
	string s, text;
	while (getline(cin, s)) {
//		if (s.size() == 0) break;
		text += s + "\n";
		string word;
		stringstream ss(s);
		while (ss >> word) {
			for (auto &c : word) have[get_num(c)] = true;
			int sz = word.size(), i;
			for (i = 1; i < sz; ++i) {
				edge[get_num(word[i - 1])][get_num(word[i])] = true;
				edge[get_num(word[i])][get_num(word[i - 1])] = true;
			}
		}
	}

	memset(clr, -1, sizeof clr);

	int i, j;
	vector<char> vow, con;
	vector<vector<int> > aa, bb;
	memset(vst, 0, sizeof vst);
	for (i = 0; i < 26; ++i) {
		if (vst[i] || !have[i]) continue;
		vector<int> a, b;
		if (!dfs(i, 0, a, b)) {
			puts("impossible");
			return 0;
		}
		aa.push_back(a), bb.push_back(b);
	}

	for (i = 0; i < 26; ++i) A += i + 'A';
	for (i = 0; i < 26; ++i) {
		for (j = 0; j < 5; ++j) {
			if (A[i] == V[j]) break;
		}
		if (j == 5) C += A[i];
	}

	if (!is_good(0, 0, 0, aa, bb, vow, con)) {
		puts("impossible");
		return 0;
	}

	map<char, char> cm;
	int sz = vow.size();
	for (i = 0; i < sz; ++i) {
		cm[vow[i]] = V[i];
	}

	sz = con.size();
	for (i = 0; i < sz; ++i) {
		cm[con[i]] = C[i];
	}

	sz = text.size();
	for (i = 0; i < sz; ++i) {
		if (cm.count(text[i])) text[i] = cm[text[i]];
	}

	cout << text;
	return 0;
}
