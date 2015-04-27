#include <bits/stdc++.h>
using namespace std;

string get_string(int n) {
	stringstream ss;
	ss << n;
	return ss.str();
}

int get_int(string s) {
	int ret;
	stringstream (s) >> ret;
	return ret;
}

int get_quasbinary(int n) {
	string s = get_string(n);
	string ret;
	int sz = s.size();
	for (int i = 0; i < sz; ++i) {
		if (s[i] != '0') ret += '1';
		else ret += '0';
	}
	return get_int(ret);
}

int main() {
	int n;
	cin >> n;

	vector<int> ans;
	while (n) {
		ans.push_back(get_quasbinary(n));
		n -= ans.back();
	}

	cout << ans.size() << endl;
	for (int i = 0; i < ans.size(); ++i) cout << ans[i] << ' ';cout << endl;
	return 0;
}




