#include <bits/stdc++.h>
using namespace std;

class RowAndCoins {
public:
	string getWinner(string cells) {
		string res[] = {"Alice", "Bob"};
		int n = cells.size();

		int dp[1 << 14][2] = {};
		int last = (1 << n) - 1;

		for (int i = 0; i < n; ++i) {
			int winner = cells[i] - 'A';
			dp[last ^ (1 << i)][0] = dp[last ^ (1 << i)][1] = winner;
		}

		for (int mask = last - 1; mask >= 0; --mask) {
			if (__builtin_popcount(mask) == n - 1) continue;
			for (int player = 0; player < 2; ++player) {
				dp[mask][player] = !player;
				for (int i = 0; i < n; ++i) {
					if (!((mask >> i) & 1)) {
						int tempMask = mask;
						for (int j = i; j < n; ++j) {
							tempMask |= 1 << j;
							if (__builtin_popcount(tempMask) == n) break;
							if (dp[tempMask][!player] == player) {
								dp[mask][player] = player;
							}
						}
					}
				}
			}
		}

		return res[dp[0][0]];
	}

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "ABBB"; string Arg1 = "Alice"; verify_case(0, Arg1, getWinner(Arg0)); }
	void test_case_1() { string Arg0 = "BBBB"; string Arg1 = "Bob"; verify_case(1, Arg1, getWinner(Arg0)); }
	void test_case_2() { string Arg0 = "BA"; string Arg1 = "Alice"; verify_case(2, Arg1, getWinner(Arg0)); }
	void test_case_3() { string Arg0 = "BABBABBB"; string Arg1 = "Bob"; verify_case(3, Arg1, getWinner(Arg0)); }
	void test_case_4() { string Arg0 = "ABABBBABAABBAA"; string Arg1 = "Alice"; verify_case(4, Arg1, getWinner(Arg0)); }
	void test_case_5() { string Arg0 = "BBBAAABBAAABBB"; string Arg1 = "Bob"; verify_case(5, Arg1, getWinner(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	RowAndCoins ___test;
	___test.run_test(-1);
}
// END CUT HERE
