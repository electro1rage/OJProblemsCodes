#include <bits/stdc++.h>
using namespace std;

class PiecewiseLinearFunction {
public:
	//write in ___test(5) to know the corner case
int maximumSolutions(vector <int> Y) {
	int res = 0;
	int n = Y.size();
	vector<double> Asuna;

	Asuna.push_back(Y[0]);
	Asuna.push_back(Y[0] - 0.5);
	Asuna.push_back(Y[0] + 0.5);
	for (int i = 1; i < n; ++i) {
		if (Y[i] == Y[i - 1]) {
			return -1;
		}
		Asuna.push_back(Y[i]);
		Asuna.push_back(Y[i] - 0.5);
		Asuna.push_back(Y[i] + 0.5);
	}

	int m = Asuna.size();

	for (int i = 0; i < m; ++i) {
		int ctr = 0;
		for (int j = 0; j < n - 1; ++j) {
			if (j != n - 2) {
				if (Y[j] < Y[j + 1]) {
					if (Asuna[i] >= Y[j] && Asuna[i] < Y[j + 1]) ++ctr;
				} else if (Y[j] > Y[j + 1]) {
					if (Asuna[i] <= Y[j] && Asuna[i] > Y[j + 1]) ++ctr;
				}
			}
			else {
				if (Y[j] < Y[j + 1]) {
					if (Asuna[i] >= Y[j] && Asuna[i] <= Y[j + 1]) ++ctr;
				} else if (Y[j] > Y[j + 1]) {
					if (Asuna[i] <= Y[j] && Asuna[i] >= Y[j + 1]) ++ctr;
				}
			}
		}
		res = max(res, ctr);
	}
	return res;
}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {3, 2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(0, Arg1, maximumSolutions(Arg0)); }
	void test_case_1() { int Arr0[] = {4, 4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = -1; verify_case(1, Arg1, maximumSolutions(Arg0)); }
	void test_case_2() { int Arr0[] = {1, 4, -1, 2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(2, Arg1, maximumSolutions(Arg0)); }
	void test_case_3() { int Arr0[] = {2, 1, 2, 1, 3, 2, 3, 2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 5; verify_case(3, Arg1, maximumSolutions(Arg0)); }
	void test_case_4() { int Arr0[] = {125612666, -991004227, 0, 6, 88023, -1000000000, 1000000000, -1000000000, 1000000000}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 6; verify_case(4, Arg1, maximumSolutions(Arg0)); }
	void test_case_5() { int Arr0[] = {1, 2, 1, 2, 1, 2, 1, 2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 7; verify_case(5, Arg1, maximumSolutions(Arg0)); }
// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	PiecewiseLinearFunction ___test;
	___test.run_test(-1);
}
// END CUT HERE
