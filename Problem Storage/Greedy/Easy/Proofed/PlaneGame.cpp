#include <bits/stdc++.h>
using namespace std;

class PlaneGame {
public:
	int bestShot(vector <int> x, vector <int> y) {
		int n = x.size(), cnt, ans, i, j, k, l, m;
		bool vst1[55], vst2[55];
		if (n == 1) return 1;
		if (n == 2) return 2;

		ans = 0;
		for (i = 0; i < n; ++i) {
			for (j = i + 1; j < n; ++j) {
				memset(vst1, 0, sizeof vst1);
				for (m = 0; m < n; ++m) {
					if (1LL * (x[i] - x[j]) * (y[i] - y[m]) == 1LL * (x[i] - x[m]) * (y[i] - y[j])) vst1[m] = true;
				}

				cnt = count(vst1, vst1 + 55, true);
				ans = max(ans, cnt);
				if (cnt != n) ans = max(ans, cnt + 1);
				for (k = 0; k < n; ++k) {
					for (l = k + 1; l < n; ++l) {
						if (-1LL * (y[i] - y[j]) * (y[k] - y[l]) == 1LL * (x[k] - x[l]) * (x[i] - x[j])) {
							memcpy(vst2, vst1, sizeof vst1);
							for (m = 0; m < n; ++m) {
								if (1LL * (x[k] - x[l]) * (y[k] - y[m]) == 1LL * (x[k] - x[m]) * (y[k] - y[l])) vst2[m] = true;
							}
							cnt = count(vst2, vst2 + 55, true);
							ans = max(ans, cnt);
						}
					}
				}
			}
		}
		return ans;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {0, 5}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0, 5}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2; verify_case(0, Arg2, bestShot(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {0, -1, 1, 1, -1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0, -1, -1, 1, 1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 5; verify_case(1, Arg2, bestShot(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {0, 0, 0, 1, -1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0, 1, -1, 0, 0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 5; verify_case(2, Arg2, bestShot(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {0, -3, 3, 3, -3, 0, 0, 3, -3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0, -3, -3, 3, 3, 3, -3, 0, 0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 5; verify_case(3, Arg2, bestShot(Arg0, Arg1)); }
	void test_case_4() { int Arr0[] = {0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1; verify_case(4, Arg2, bestShot(Arg0, Arg1)); }
	void test_case_5() { int Arr0[] = {-1000000, -1, 999998, 1, -1001, 1000000, -999999, 999999, 0, 0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1000000, 1, 1000000, -1, -999, 1000000, 0, 0, -999999, 999999}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 5; verify_case(5, Arg2, bestShot(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	PlaneGame ___test;
	___test.run_test(-1);
}
// END CUT HERE
