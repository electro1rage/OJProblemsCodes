#include <bits/stdc++.h>
using namespace std;

map<vector<int>, double> memo;

class RandomSort {
public:
	double solve(vector<int> v) {
		if (memo.count(v)) return memo[v];
		double &ret = memo[v];
		ret = 0;

		int num = 0;

		for (int i = 0; i < v.size(); ++i)
			for (int j = i + 1; j < v.size(); ++j)
				if (v[j] < v[i]) ++num;

		for (int i = 0; i < v.size(); ++i)
			for (int j = i + 1; j < v.size(); ++j) {
				if (v[j] < v[i]) {
					swap(v[i], v[j]);
					ret += (1.0 / num) * (1 + solve(v));
					swap(v[i], v[j]);
				}
			}

		return ret;
	}
	double getExpected(vector <int> permutation) {
		return solve(permutation);
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1,3,2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 1.0; verify_case(0, Arg1, getExpected(Arg0)); }
	void test_case_1() { int Arr0[] = {4,3,2,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 4.066666666666666; verify_case(1, Arg1, getExpected(Arg0)); }
	void test_case_2() { int Arr0[] = {1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 0.0; verify_case(2, Arg1, getExpected(Arg0)); }
	void test_case_3() { int Arr0[] = {2,5,1,6,3,4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 5.666666666666666; verify_case(3, Arg1, getExpected(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	RandomSort ___test;
	___test.run_test(-1);
}
// END CUT HERE
