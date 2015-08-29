#include <bits/stdc++.h>
using namespace std;

const int MC = 27;

int get_num(char c) {
	if (c == ' ') return 26;
	return c - 'a';
}

struct trie {
	trie *nx[MC];
	bool cnt;
	trie () {
		memset(nx, 0, sizeof nx);
		cnt = false;
	}

	bool get_word(string &s, int ind) {
		int sz = s.size();
		if (ind == sz) return cnt;
		if (nx[get_num(s[ind])] == NULL) return false;
		return nx[get_num(s[ind])]->get_word(s, ind + 1);
	}

	void insert(string &s, int ind) {
		int sz = s.size();
		if (ind == sz) {
			cnt = true;
			return ;
		}
		if (nx[get_num(s[ind])] == NULL) nx[get_num(s[ind])] = new trie();
		nx[get_num(s[ind])]->insert(s, ind + 1);
	}
};

inline long long get_hash(string s) {
	int sz = s.size(), i;
	long long ret = 0;
	for (i = 0; i < sz; ++i) ret = 173 * ret + s[i];
	return ret;
}

map<long long, int> p, P;

int main() {
	int n, k, q, i;
	cin >> n;
	string s;
	string ts;
	getline(cin, s);
	for (i = 0; i < n; ++i) {
		getline(cin, s);
		ts += s + ' ';
	}
	vector<string> x, y;
	int sz = ts.size();
	for (i = 0; i < sz; ++i) {
		if (!isalpha(ts[i])) ts[i] = ' ';
		else ts[i] = tolower(ts[i]);
	}
	s.clear();
	for (i = 0; i < sz; ++i) {
		if (ts[i] == ' ') {
			if (!s.empty()) x.push_back(s), s = "";
			continue;
		}
		s += ts[i];
	}

	trie *root = new trie();
	cin >> k;
	for (i = 0; i < k; ++i) {
		cin >> s;
		root->insert(s, 0);
	}

	sz = x.size();
	for (i = 0; i < sz; ++i) {
		if (root->get_word(x[i], 0)) continue;
		y.push_back(x[i]);
	}

	sz = y.size();
	for (i = 0; i < sz; ++i) {
		++p[get_hash(y[i])];
		if (i + 1 < sz) {
			string s1 = y[i], s2 = y[i + 1];
			if (s2 < s1) swap(s1, s2);
			string s3 = s1 + ' ' + s2;
			++P[get_hash(s3)];
		}
	}

	cin >> q;
	for (i = 0; i < q; ++i) {
		string s1, s2;
		cin >> s1 >> s2;
		if (s2 < s1) swap(s1, s2);
		string s3 = s1 + ' ' + s2;
		int p1 = p[get_hash(s1)], p2 = p[get_hash(s2)], p3 = P[get_hash(s3)];
		if (!p1 || !p2) assert(false);
		printf("%.7lf\n", double(sz) * (double)sz * (double)p3 / ((double)(sz - 1) * (double)p1 * (double)p2));
	}
	return 0;
}
