#include <bits/stdc++.h>
using namespace std;

char s[100005];

int main() {
	scanf("%s", s);

	stack<char> ans;
	for (int i = 0; s[i]; ++i) {
		if (!ans.empty() && s[i] == ans.top()) {
			ans.pop();
			continue;
		}
		ans.push(s[i]);
	}

	if (ans.empty()) {
		puts("Yes");
	} else {
		puts("No");
	}
	return 0;
}
