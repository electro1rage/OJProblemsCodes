#include <bits/stdc++.h>
using namespace std;

int memo[55][55][55];
int dist[55][55];

class ShortestPathWithMagic {
public:
	int n;
	int get_cost(int i, int rem, int d) {
		if (d > 50) return 1000000000;
		if (i == 1) return 0;

		int &ret = memo[i][rem][d];

		if (ret == -1) {
			ret = 1000000000;

			int j;
			for (j = 0; j < n; ++j) {
				if (i == j) continue;
				ret = min(ret, get_cost(j, rem, d + 1) + dist[i][j]);
				if (rem) ret = min(ret, get_cost(j, rem - 1, d + 1) + (dist[i][j] / 2));
			}
		}

		return ret;
	}

	double getTime(vector <string> dist1, int k) {
		n = dist1.size();
		int i, j;
		for (i = 0; i < n; ++i) {
			for (j = 0; j < n; ++j) dist[i][j] = 2 * (dist1[i][j] - '0');
		}

		memset(memo, -1, sizeof memo);

		return get_cost(0, k, 0) / 2.0;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"094",
 "904",
 "440"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; double Arg2 = 4.5; verify_case(0, Arg2, getTime(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {"094",
 "904",
 "440"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; double Arg2 = 4.0; verify_case(1, Arg2, getTime(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"094",
 "904",
 "440"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 50; double Arg2 = 4.0; verify_case(2, Arg2, getTime(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {"094",
 "904",
 "440"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; double Arg2 = 8.0; verify_case(3, Arg2, getTime(Arg0, Arg1)); }
	void test_case_4() { string Arr0[] = {"076237",
 "708937",
 "680641",
 "296059",
 "334508",
 "771980"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; double Arg2 = 3.5; verify_case(4, Arg2, getTime(Arg0, Arg1)); }
	void test_case_5() { string Arr0[] = {"00",
 "00"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 50; double Arg2 = 0.0; verify_case(5, Arg2, getTime(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	ShortestPathWithMagic ___test;
	___test.run_test(-1);
}
// END CUT HERE
