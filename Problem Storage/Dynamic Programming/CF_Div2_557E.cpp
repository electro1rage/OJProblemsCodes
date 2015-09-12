#include <bits/stdc++.h>
using namespace std;

const int MN = 5050;

bool dp[MN][MN];
char s[MN];
char ans[MN];

int get_num(char c) {
	return c - 'a';
}

struct trie {
	trie *c[2];
	int cnt, treecnt;
	trie () {
		memset(c, 0, sizeof c);
		cnt = treecnt = 0;
	}

	void add(char i) {
		if (c[get_num(i)] == NULL) c[get_num(i)] = new trie();
	}
	int process() {
		treecnt = cnt;
		if (c[0] != NULL) treecnt += c[0]->process();
		if (c[1] != NULL) treecnt += c[1]->process();
		return treecnt;
	}
	void get_ans(int k, int i) {
		if (k <= cnt) {
			ans[i] = 0;
			return ;
		}
		k -= cnt;
		if (c[0] == NULL) c[1]->get_ans(k, i + 1), ans[i] = 'b';
		else if (c[1] == NULL) c[0]->get_ans(k, i + 1), ans[i] = 'a';
		else {
			if (c[0]->treecnt >= k) c[0]->get_ans(k, i + 1), ans[i] = 'a';
			else c[1]->get_ans(k - c[0]->treecnt, i + 1), ans[i] = 'b';
		}
	}
};

int main() {
	int n, i, j, k, p;
	scanf("%s", s);
	scanf("%d", &p);

	n = strlen(s);
	for (i = n - 1; i >= 0; --i) {
		for (j = i; j < n; ++j) {
			dp[i][j] = (s[i] == s[j]) && ((i + 2 > j - 2) || dp[i + 2][j - 2]);
		}
	}

	trie *root = new trie();
	for (i = 0; i < n; ++i) {
		k = i;
		trie *temp;
		temp = root;
		for (j = i; j < n; ++j) {
			if (dp[i][j]) {
				for (; k <= j; ++k) temp->add(s[k]), temp = temp->c[get_num(s[k])];
				++temp->cnt;
			}
		}
	}

	root->process();
	root->get_ans(p, 0);
	printf("%s\n", ans);
	return 0;
}
