/*
reality, be rent!
synapse, break!
Van!shment Th!s World !!
*/
#include <bits/stdc++.h>
using namespace std;

#define next _next

vector<vector<string> > db;

bool is_valid(vector<string> s) {
	int have[7] = {}, n = s.size(), i;
	for (i = 0; i < n; ++i) ++have[s[i][0] - 'A'];
	for (i = 0; i < 7; ++i) if (have[i] != 1) return false;
	bool h = false, b = false;
	for (i = 0; i < n; ++i) {
		if (s[i].size() != 1) if (s[i][1] == '#') h = true;
		if (s[i].size() != 1) if (s[i][1] == 'b') b = true;
	}
	if (h && b) return false;
	return true;
}

vector<vector<string> > a = {{"C", "B#"}, {"C#", "Db"}, {"D"}, {"D#", "Eb"}, {"E", "Fb"}, {"F", "E#"}, {"F#", "Gb"}, {"G"}, {"G#", "Ab"}, {"A"}, {"A#", "Bb"}, {"B", "Cb"}};
int next[] = {2, 2, 1, 2, 2, 2, 1};

void generate(int i, int j, vector<string> s) {
	if (j == 7) {
		if (is_valid(s)) db.push_back(s);
		return ;
	}

	for (auto &x : a[i]) {
		vector<string> temp = s;
		temp.push_back(x);
		generate((i + next[j]) % 12, j + 1, temp);
	}
}

int main() {
	int i;
	for (i = 0; i < 12; ++i) {
		generate(i, 0, vector<string> ());
	}

	string from = "", to = "", s;
	vector<string> source, target;
	bool good = false;
	vector<string> v;
	while (true) {
		cin >> from;
		if (from == "*") break;
		if (to != "") puts("");
		cin >> to;
		v.clear();
		while (true) {
			cin >> s;
			if (s == "*") break;
			v.push_back(s);
		}
		good = false;
		for (auto &x : db) if (x[0] == from) source = x, good = true;
		if (!good) {
			printf("Key of %s is not a valid major key\n", from.c_str());
			continue;
		}
		good = false;
		for (auto &x : db) if (x[0] == to) target = x, good = true;
		if (!good) {
			printf("Key of %s is not a valid major key\n", to.c_str());
			continue;
		}

		printf("Transposing from %s to %s:\n", from.c_str(), to.c_str());
		for (auto &x : v) {
			for (i = 0; i < 7; ++i) if (source[i] == x) break;
			if (i != 7) {
				printf("  %s transposes to %s\n", x.c_str(), target[i].c_str());
			} else {
				printf("  %s is not a valid note in the %s major scale\n", x.c_str(), from.c_str());
			}
		}
	}
	return 0;
}
