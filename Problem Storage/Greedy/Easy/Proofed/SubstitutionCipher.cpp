#include <bits/stdc++.h>
using namespace std;

class SubstitutionCipher {
public:
	char sub[26];
	int get_num(char c) {
		return c - 'A';
	}
	string decode(string a, string b, string y) {
		int n = a.size(), i, j;
		for (i = 0; i < 26; ++i) sub[i] = 'x';
		for (i = 0; i < n; ++i) sub[get_num(b[i])] = a[i];
		sort(a.begin(), a.end());
		sort(b.begin(), b.end());
		a.erase(unique(a.begin(), a.end()), a.end());
		b.erase(unique(b.begin(), b.end()), b.end());
		n = a.size();
		if (n == 25) {
			for (i = 'A'; i <= 'Z'; ++i) {
				for (j = 0; j < n; ++j) if (a[j] == i) break;
				if (j == n) {
					for (j = 0; j < 26; ++j) if (sub[j] == 'x') {
						sub[j] = i;
						break;
					}
					break;
				}
			}
		}

		for (auto &o : y) if (sub[get_num(o)] == 'x') return string("");
		for (auto &o : y) o = sub[get_num(o)];
		return y;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "CAT"; string Arg1 = "DOG"; string Arg2 = "GOD"; string Arg3 = "TAC"; verify_case(0, Arg3, decode(Arg0, Arg1, Arg2)); }
	void test_case_1() { string Arg0 = "BANANA"; string Arg1 = "METETE"; string Arg2 = "TEMP"; string Arg3 = ""; verify_case(1, Arg3, decode(Arg0, Arg1, Arg2)); }
	void test_case_2() { string Arg0 = "THEQUICKBROWNFOXJUMPSOVERTHELAZYHOG"; string Arg1 = "UIFRVJDLCSPXOGPYKVNQTPWFSUIFMBAZIPH"; string Arg2 = "DIDYOUNOTICESKIPPEDLETTER"; string Arg3 = "CHCXNTMNSHBDRJHOODCKDSSDQ"; verify_case(2, Arg3, decode(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	SubstitutionCipher ___test;
	___test.run_test(-1);
}
// END CUT HERE
