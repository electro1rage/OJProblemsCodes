#include <bits/stdc++.h>
using namespace std;

string rotate_right(string a) {
	string ret = "";
	int b[] = { 1, 5, 2, 0, 4, 3 }, i;
	for (i = 0; i < 6; ++i) ret += a[b[i]];
	return ret;
}

string rotate_back(string a) {
	string ret = "";
	int b[] = { 2, 1, 5, 3, 0, 4 }, i;
	for (i = 0; i < 6; ++i) ret += a[b[i]];
	return ret;
}

string rotate_side(string a) {
	string ret = "";
	int b[] = { 0, 4, 1, 2, 3, 5 }, i;
	for (i = 0; i < 6; ++i) ret += a[b[i]];
	return ret;
}

bool same_cube(string a, string b) {
	int i, j, k;
	for (i = 0; i < 4; ++i) {
		a = rotate_right(a);
		for (j = 0; j < 4; ++j) {
			a = rotate_back(a);
			for (k = 0; k < 4; ++k) {
				a = rotate_side(a);
				if (a == b) return true;
			}
		}
	}
	return false;
}

int main() {
	freopen("cube.in", "r", stdin);
	freopen("cube.out", "w", stdout);

	map<int, int> op;
	op[0] = 5, op[1] = 3, op[2] = 4, op[3] = 1, op[4] = 2, op[5] = 0;

	string s[6];
	int i, j;
	vector<char> v;
	for (i = 0; i < 6; ++i) cin >> s[i], v.push_back(s[i][0]), sort(s[i].begin() + 1, s[i].end());
	sort(v.begin(), v.end()), sort(s, s + 6);
	vector<string> ans;

	do {
		string b[6];
		for (i = 0; i < 6; ++i) {
			string temp = "";
			temp += v[i];
			for (j = 0; j < 6; ++j) if (j != i && op[j] != i) temp += v[j];
			sort(temp.begin() + 1, temp.end());
			b[i] = temp;
		}
		sort(b, b + 6);
		bool good = true;
		for (i = 0; i < 6; ++i) good &= b[i] == s[i];
		if (!good) continue;

		string temp = "";
		for (i = 0; i < 6; ++i) temp += v[i];

		if (ans.empty()) {
			ans.push_back(temp);
		} else {
			if (!same_cube(ans.back(), temp)) ans.push_back(temp);
		}
	} while (next_permutation(v.begin(), v.end()));

	int sz = ans.size();
	if (sz == 0) {
		puts("Impossible");
		return 0;
	}


	for (i = 0; i < min(sz, 2); ++i) {
		for (j = 0; j < 6; ++j) putchar(ans[i][j]);puts("");
	}
	return 0;
}
