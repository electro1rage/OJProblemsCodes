#include <bits/stdc++.h>
using namespace std;

char digit[100005];

int main() {
	scanf("%s", digit);

	int sz = strlen(digit);
	if (count(digit, digit + sz, '1') == sz) {
		digit[sz - 1] = 0;
		printf("%s\n", digit);
		return 0;
	}

	bool foundzero = 0;
	for (int i = 0; i < sz; ++i) {
		if (digit[i] == '0' && !foundzero) {
			foundzero = 1;
			continue;
		}
		printf("%c", digit[i]);
	}
	return 0;
}
