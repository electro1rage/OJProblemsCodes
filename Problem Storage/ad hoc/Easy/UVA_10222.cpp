#include <bits/stdc++.h>
using namespace std;

string s = "qwertyuiop[]asdfghjkl;'zxcvbnm,./!@#$%^&*()_+1234567890";

int main() {
	string in;
	int n = s.size(), m;
	while (getline(cin, in)) {
		m = in.size();
		int i, j;
		for (i = 0; i < m; ++i) {
			bool found = false;
			if (isupper(in[i])) in[i] = tolower(in[i]);
			for (j = 0; j < n; ++j) {
				if (in[i] == s[j]) {
					found = true, putchar(s[j - 2]);
					break;
				}
			}
			if (!found) putchar(in[i]);
		}
		puts("");
	}
	return 0;
}
