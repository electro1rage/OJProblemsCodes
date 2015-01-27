#include <bits/stdc++.h>
using namespace std;

class TheAlmostLuckyNumbersDivOne {
public:
	long long res;
	long long a, b;
	void cnt(long long num, bool done) {
		if (num > b) return;
		if (a <= num) ++res;

		cnt(num * 10 + 7, done);
		cnt(num * 10 + 4, done);

		if (!done) {
			int start = 0;
			if (!num) start = 1;
			for (int i = start; i < 10; ++i) {
				if (i == 4 || i == 7) continue;
				cnt(num * 10 + i, 1);
			}
		}
	}
	long long find(long long a, long long b) {
		res = 0;
		this->a = a;
		this->b = b;

		cnt(0, 0);

		return res;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { long long Arg0 = 4LL; long long Arg1 = 7LL; long long Arg2 = 4LL; verify_case(0, Arg2, find(Arg0, Arg1)); }
	void test_case_1() { long long Arg0 = 8LL; long long Arg1 = 19LL; long long Arg2 = 4LL; verify_case(1, Arg2, find(Arg0, Arg1)); }
	void test_case_2() { long long Arg0 = 28LL; long long Arg1 = 33LL; long long Arg2 = 0LL; verify_case(2, Arg2, find(Arg0, Arg1)); }
	void test_case_3() { long long Arg0 = 12345678900LL; long long Arg1 = 98765432100LL; long long Arg2 = 91136LL; verify_case(3, Arg2, find(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	TheAlmostLuckyNumbersDivOne ___test;
	___test.run_test(-1);
}
// END CUT HERE
