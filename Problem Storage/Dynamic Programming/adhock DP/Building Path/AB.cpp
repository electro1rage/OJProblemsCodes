#include <bits/stdc++.h>
using namespace std;

string dp[2][51][1234];

class AB {
public:
	string createString(int N, int K) {
		for (int i = 0; i < 2; ++i)
			for (int j = 0; j <= N; ++j)
				for (int l = 0; l <= K; ++l)
					dp[i][j][l] = "NO";

		dp[0][0][0] = "";
		for (int i = 1; i <= N; ++i) {
			for (int j = 0; j <= N; ++j) {
				for (int l = 0; l <= K; ++l) {
					if (j && dp[(i + 1) & 1][j - 1][l] != "NO") {
						dp[i & 1][j][l] = dp[(i + 1) & 1][j - 1][l] + 'B';
					}
					if (l - j >= 0 && dp[(i + 1) & 1][j][l - j] != "NO") {
						dp[i & 1][j][l] = dp[(i + 1) & 1][j][l - j] + 'A';
					}
				}
			}
		}

		for (int i = 0; i <= N; ++i)
			if (dp[N & 1][i][K] != "NO") {
				reverse(dp[N & 1][i][K].begin(), dp[N & 1][i][K].end());
				return dp[N & 1][i][K];
			}

		return "";
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 3; int Arg1 = 2; string Arg2 = "ABB"; verify_case(0, Arg2, createString(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 2; int Arg1 = 0; string Arg2 = "BA"; verify_case(1, Arg2, createString(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 5; int Arg1 = 8; string Arg2 = ""; verify_case(2, Arg2, createString(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 10; int Arg1 = 12; string Arg2 = "BAABBABAAB"; verify_case(3, Arg2, createString(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	AB ___test;
	___test.run_test(2);
}
// END CUT HERE
