/*
reality, be rent!
synapse, break!
Van!shment Th!s World !!
*/
#include <bits/stdc++.h>
using namespace std;

const int MN = 68;

long long len[MN], num[MN];

long long get_fst(long long n, int i = 0) {
	if (n <= 0) return 0;
	if (len[i] <= n) {
		n -= len[i];
		return num[i] + get_fst(n, i + 1);
	}
	return n + get_fst(n - 1, 0);
}

void get_num(string &ret, int sz, long long rem) {
	if (rem == 0) return ;
	int i;
	for (i = 1; i <= sz; ++i) {
		if (len[i] >= rem) {
			ret[i - 1] = '1';
			get_num(ret, sz - 2, rem - 1);
			return ;
		} else rem -= len[i];
	}
}


int main() {
	freopen("fibonacci.in", "r", stdin);
	freopen("fibonacci.out", "w", stdout);

	int i, j;
	len[1] = len[2] = num[1] = num[2] = 1;
	for (i = 3; i < MN; ++i) {
		len[i] = len[i - 1] + len[i - 2];
		for (j = 1; j < i - 1; ++j) num[i] += num[j];
		num[i] += len[i];
	}

	long long n, ans;
	cin >> n;

	if (n == 0) {
		puts("0");
		return 0;
	}

	ans = 0;

	for (i = 0; i < MN; ++i) {
		if (len[i] * i <= n) {
			n -= len[i] * i;
			ans += num[i];
		} else break;
	}

	ans += n / i + get_fst(n / i - 1);

	string s(i, '0');
	s[i - 1] = '1';
	get_num(s, i, n / i);
	reverse(s.begin(), s.end());
	for (j = 0; j < n % i; ++j) if (s[j] == '1') ++ans;

	cout << ans << endl;
	return 0;
}
