#include <bits/stdc++.h>
using namespace std;

class TheDevice {
public:
	int minimumAdditional(vector <string> plates) {
		int res = 0;
		int n = plates.size(), m = plates[0].size();

		for (int i = 0; i < m; ++i) {
			int one = 0, zero = 0;
			for (int j = 0; j < n; ++j) {
				if (plates[j][i] == '0') ++zero;
				else ++one;
			}

			zero = max(0, 1 - zero);
			one = max(0, 2 - one);
			res = max(res, one + zero);
		}
		return res;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"010",
 "011",
 "101"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(0, Arg1, minimumAdditional(Arg0)); }
	void test_case_1() { string Arr0[] = {"0",
 "1",
 "0",
 "1"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(1, Arg1, minimumAdditional(Arg0)); }
	void test_case_2() { string Arr0[] = {"01010101",
 "10101010"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(2, Arg1, minimumAdditional(Arg0)); }
	void test_case_3() { string Arr0[] = {"10010101011",
 "00010101001",
 "00100010111",
 "00101010101",
 "01010111101"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(3, Arg1, minimumAdditional(Arg0)); }
	void test_case_4() { string Arr0[] = {"1101001011010",
 "0010000010101",
 "1010101011110",
 "1101010100111",
 "1011111110111"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(4, Arg1, minimumAdditional(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	TheDevice ___test;
	___test.run_test(-1);
}
// END CUT HERE
