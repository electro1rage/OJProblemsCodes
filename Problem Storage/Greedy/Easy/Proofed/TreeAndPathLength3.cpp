#include <bits/stdc++.h>
using namespace std;

class TreeAndPathLength3 {
public:
	vector <int> construct(int s) {
		int i, j, k = 0, l = 0;
		for (i = 1; i <= 200; ++i) {
			for (j = 1; j <= 200; ++j) {
				if (i * j == s) {
					vector<int> ret{0, 1};
					for (k = 0; k < i; ++k) ret.push_back(0), ret.push_back(k + 2);
					for (k = 0; k < j; ++k) ret.push_back(1), ret.push_back(i + k + 2);
					return ret;
				}
			}
		}
		for (i = 1; i <= 100; ++i) {
			for (j = 1; j <= 100; ++j) {
				if (i * j > s) continue;
				if (s - i * j > j) {
					if (k * l < i * j) k = i, l = j;
				}
			}
		}
		vector<int> ret{0, 1};
		for (i = 0; i < k; ++i) ret.push_back(0), ret.push_back(i + 2);
		for (i = 0; i < l; ++i) ret.push_back(1), ret.push_back(k + i + 2);
		i = k + i + 1;

		s = s - k * l - l;
		ret.push_back(i), ret.push_back(i + 1), ++i;
		while (s) {
			--s, ret.push_back(i), ret.push_back(i + 1), ++i;
		}
		return ret;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { int Arg0 = 1; int Arr1[] = {0, 1, 1, 2, 2, 3 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, construct(Arg0)); }
	void test_case_1() { int Arg0 = 2; int Arr1[] = {0, 1, 1, 2, 2, 3, 3, 4 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, construct(Arg0)); }
	void test_case_2() { int Arg0 = 6; int Arr1[] = {0, 1, 1, 2, 0, 3, 3, 4, 0, 5, 5, 6 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, construct(Arg0)); }
	void test_case_3() { int Arg0 = 8; int Arr1[] = {0, 1, 1, 2, 1, 3, 3, 4, 3, 5, 5, 6, 5, 7 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(3, Arg1, construct(Arg0)); }

// END CUT HERE

};

//1583

// BEGIN CUT HERE
int main() {
	TreeAndPathLength3 ___test;
	___test.run_test(0);
}
// END CUT HERE
