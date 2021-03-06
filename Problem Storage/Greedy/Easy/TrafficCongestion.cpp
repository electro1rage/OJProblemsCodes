#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;

class TrafficCongestion {
public:
int theMinCars(int treeHeight) {
	int res = 0;

	int two[1000005] = {};
	int p = 1;
	for (int i = 0; i < 1000005; ++i) {
		two[i] = p;
		p = (p * 2LL) % MOD;
	}

	for (int i = treeHeight - 1; i >= 0; i -= 2) {
		res = ((long long)res + two[i]) % MOD;
	}

	return ((long long)res + !(treeHeight % 2)) % MOD;
}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 1; int Arg1 = 1; verify_case(0, Arg1, theMinCars(Arg0)); }
	void test_case_1() { int Arg0 = 2; int Arg1 = 3; verify_case(1, Arg1, theMinCars(Arg0)); }
	void test_case_2() { int Arg0 = 3; int Arg1 = 5; verify_case(2, Arg1, theMinCars(Arg0)); }
	void test_case_3() { int Arg0 = 585858; int Arg1 = 548973404; verify_case(3, Arg1, theMinCars(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	TrafficCongestion ___test;
	___test.run_test(-1);
}
// END CUT HERE
