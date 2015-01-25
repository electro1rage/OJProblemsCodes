#include <bits/stdc++.h>
using namespace std;

int arr[26];

class FoxAndHandle {
public:
	string solve(int rem, string s) {
		if (!rem) return "";

		for (int i = 0; i < 26; ++i) {
			if (!arr[i]) continue;
			int ind = -1;
			int left[26] = {};
			for (int j = 0; j < s.size(); ++j) {
				if (ind != -1) ++left[s[j] - 'a'];
				else if (s[j] == i + 'a') {
					ind = j;
					++left[i];
				}
			}
			bool bad = 0;
			for (int j = 0; j < 26; ++j)
				bad |= left[j] < arr[j];

			if (!bad) {
				--arr[i];
				return (char)(i + 'a') + solve(rem - 1, s.substr(ind + 1));
			}
		}
	}
	string lexSmallestName(string S) {
		for (auto &x : S)
			++arr[x - 'a'];

		for (auto &x : arr)
			x /= 2;

		int sz = 0;
		for (auto &x : arr)
			sz += x;

		return solve(sz, S);
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "foxfox"; string Arg1 = "fox"; verify_case(0, Arg1, lexSmallestName(Arg0)); }
	void test_case_1() { string Arg0 = "ccieliel"; string Arg1 = "ceil"; verify_case(1, Arg1, lexSmallestName(Arg0)); }
	void test_case_2() { string Arg0 = "abaabbab"; string Arg1 = "aabb"; verify_case(2, Arg1, lexSmallestName(Arg0)); }
	void test_case_3() { string Arg0 = "bbbbaaaa"; string Arg1 = "bbaa"; verify_case(3, Arg1, lexSmallestName(Arg0)); }
	void test_case_4() { string Arg0 = "fedcbafedcba"; string Arg1 = "afedcb"; verify_case(4, Arg1, lexSmallestName(Arg0)); }
	void test_case_5() { string Arg0 = "nodevillivedon"; string Arg1 = "deilvon"; verify_case(5, Arg1, lexSmallestName(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	FoxAndHandle ___test;
	___test.run_test(-1);
}
// END CUT HERE
