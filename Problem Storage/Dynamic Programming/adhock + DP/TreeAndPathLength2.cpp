#include <bits/stdc++.h>
using namespace std;

bool dp[55][1010][55];

class TreeAndPathLength2 {
public:
	string possible(int n, int s) {
		dp[2][0][2] = true;
		int i, j, k;
		for (i = 2; i < n; ++i) {
			for (j = 0; j < s; ++j) {
				for (k = n; k > 1; --k) {
					if (dp[i][j][k]) {
						dp[i][j][2] = true;
						if (j + k - 1 <= s) dp[i + 1][j + k - 1][k + 1] = true;
					}
				}
			}
		}

		string ans[] = {"Impossible", "Possible"};

		for (k = n; k > 1; --k) dp[n][s][2] |= dp[n][s][k];

		return ans[dp[n][s][2]];
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 4; int Arg1 = 3; string Arg2 = "Possible"; verify_case(0, Arg2, possible(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 4; int Arg1 = 2; string Arg2 = "Possible"; verify_case(1, Arg2, possible(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 3; int Arg1 = 2; string Arg2 = "Impossible"; verify_case(2, Arg2, possible(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 5; int Arg1 = 4; string Arg2 = "Possible"; verify_case(3, Arg2, possible(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 50; int Arg1 = 999; string Arg2 = "Impossible"; verify_case(4, Arg2, possible(Arg0, Arg1)); }
	void test_case_5() { int Arg0 = 50; int Arg1 = 1000; string Arg2 = "Possible"; verify_case(5, Arg2, possible(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	TreeAndPathLength2 ___test;
	___test.run_test(-1);
}
// END CUT HERE
