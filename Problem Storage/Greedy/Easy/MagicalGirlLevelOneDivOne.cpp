#include <bits/stdc++.h>
using namespace std;

class MagicalGirlLevelOneDivOne {
public:
	string isReachable(vector <int> jumpTypes, int x, int y) {
		string res[] = {"YES", "NO"};
		bool even = 0;

		for (auto &x : jumpTypes)
			even |= x % 2 == 0;

		if (even) return res[0];

		x = abs(x);
		y = abs(y);

		if (x % 2 == y % 2) return res[0];
		return res[1];
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 5; int Arg2 = 4; string Arg3 = "YES"; verify_case(0, Arg3, isReachable(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arr0[] = {3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 5; int Arg2 = 4; string Arg3 = "NO"; verify_case(1, Arg3, isReachable(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arr0[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1000000000; int Arg2 = -999999999; string Arg3 = "YES"; verify_case(2, Arg3, isReachable(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arr0[] = {999999999}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 999999999; int Arg2 = 0; string Arg3 = "NO"; verify_case(3, Arg3, isReachable(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	MagicalGirlLevelOneDivOne ___test;
	___test.run_test(-1);
}
// END CUT HERE
