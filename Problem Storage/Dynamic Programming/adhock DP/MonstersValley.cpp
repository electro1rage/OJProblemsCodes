#include <bits/stdc++.h>
using namespace std;

class MonstersValley {
public:
	int minimumPrice(vector<long long> dread, vector <int> price) {
		long long dp[105][55];
		memset(dp, -1, sizeof dp);

		dp[price[0]][0] = dread[0];

		int n = price.size();

		for (int gold = price[0]; gold <= 100; ++gold) {
			for (int i = 1; i < n; ++i) {
				if (dp[gold][i - 1] >= dread[i]) {	//can defeat.
					dp[gold][i] = dp[gold][i - 1];
				}
				if (gold > price[i] && dp[gold - price[i]][i - 1] != -1) {	//can bribe
					dp[gold][i] = max(dp[gold][i], dp[gold - price[i]][i - 1] + dread[i]);
				}
			}
		}

		for (int gold = price[0]; gold <= 100; ++gold) {
			if (dp[gold][n - 1] != -1) return gold;
		}
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { long Arr0[] = {8, 5, 10}; vector<long long> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, 1, 2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2; verify_case(0, Arg2, minimumPrice(Arg0, Arg1)); }
	void test_case_1() { long Arr0[] = {1, 2, 4, 1000000000}; vector<long long> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, 1, 1, 2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 5; verify_case(1, Arg2, minimumPrice(Arg0, Arg1)); }
	void test_case_2() { long Arr0[] = {200, 107, 105, 206, 307, 400}; vector<long long> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, 2, 1, 1, 1, 2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2; verify_case(2, Arg2, minimumPrice(Arg0, Arg1)); }
	void test_case_3() { long Arr0[] = {5216, 12512, 613, 1256, 66, 17202, 30000, 23512, 2125, 33333}; vector<long long> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2, 2, 1, 1, 1, 1, 2, 1, 2, 1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 5; verify_case(3, Arg2, minimumPrice(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	MonstersValley ___test;
	___test.run_test(-1);
}
// END CUT HERE
