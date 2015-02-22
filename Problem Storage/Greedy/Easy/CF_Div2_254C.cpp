#include <bits/stdc++.h>
using namespace std;


int bad[26];
int have[26];
string s, t;


int number(char c) {
	return c - 'A';
}

char character(int x) {
	return x + 'A';
}

bool solve(int bound, int i) {
	bool fixed = 0;
	for (int j = 0; j < bound; ++j) {
		if (bad[j] < 0) {
			++bad[j];
			--bad[number(s[i])];
			s[i] = character(j);
			fixed = 1;
			break;
		}
	}
	return fixed;
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	cin >> s >> t;

	int n = s.size();

	for (int i = 0; i < n; ++i) {
		bad[number(s[i])]++;
		bad[number(t[i])]--;
		have[number(s[i])]++;
	}

	int changed = 0;
	for (int i = 0; i < n; ++i) {
		char temp = s[i];
		if (bad[number(s[i])] > 0) {
			if (solve(number(s[i]), i)) {
				++changed;
			}
			else if (have[number(s[i])] == bad[number(s[i])]) {
				solve(26, i);
				++changed;
			}
		}
		--have[number(temp)];
	}

	cout << changed << endl;
	cout << s << endl;
	return 0;
}




