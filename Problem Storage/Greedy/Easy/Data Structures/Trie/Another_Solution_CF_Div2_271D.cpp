#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1505;
const int CHAR = 26;
const char BAD = '0';
const long long SHIFT = 1000000000;

char s[MAXN];
char state[CHAR];

struct trie {
	trie *child[CHAR];
	trie *parent;
	trie() {
		memset(child, 0, sizeof child);
		parent = 0;
	}
	bool insert(int i) {
		if (child[i] == 0) {
			child[i] = new trie;
			return true;
		}
		return false;
	}
};

int main() {
	int k;
	scanf("%s", s);
	scanf("%s", state);
	scanf("%d", &k);

	int ans = 0;

	trie *tree = new trie;

	int n = strlen(s);
	for (int i = 0; i < n; ++i) {
		int bad = 0;
		for (int j = i; j < n; ++j) {
			if (state[s[j] - 'a'] == BAD) ++bad;
			if (bad > k) break;

			if (tree->insert(s[j] - 'a')) ++ans;

			tree->child[s[j] - 'a']->parent = tree;
			tree = tree->child[s[j] - 'a'];
		}
		while (tree->parent != 0) {
			tree = tree->parent;
		}
	}

	printf("%d\n", ans);
	return 0;
}





