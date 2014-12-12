#include <bits/stdc++.h>
using namespace std;

class TheTree {
public:
int maximumDiameter(vector <int> cnt) {
	int res = 0;
	cnt.insert(cnt.begin() + 0 , 1);
	int sz = cnt.size();

	for(int i = 0 ; i < sz ; ++i) {
		if(cnt[i] == 1) {
			int ind = sz;
			for(int j = i + 1 ; j < sz ; ++j)
				if(cnt[j] == 1) {
					ind = j;
					break;
				}
			int lft = ind - i - 1;
			int rit = sz - i - 1;
			res = max(res , lft + rit);
		}
	}

	return res;
}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(0, Arg1, maximumDiameter(Arg0)); }
	void test_case_1() { int Arr0[] = {2, 2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; verify_case(1, Arg1, maximumDiameter(Arg0)); }
	void test_case_2() { int Arr0[] = {4, 1, 2, 4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 5; verify_case(2, Arg1, maximumDiameter(Arg0)); }
	void test_case_3() { int Arr0[] = {4, 2, 1, 3, 2, 5, 7, 2, 4, 5, 2, 3, 1, 13, 6}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 21; verify_case(3, Arg1, maximumDiameter(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	TheTree ___test;
	___test.run_test(-1);
}
// END CUT HERE
