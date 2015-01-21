#include <bits/stdc++.h>
using namespace std;

class TeamContest {
public:
	int worstRank(vector <int> strength) {
		int res = 0;
		int myTeam = max(strength[0], max(strength[1], strength[2])) + min(strength[0], min(strength[1], strength[2]));

		strength.erase(strength.begin(), strength.begin() + 3);

		sort(strength.begin(), strength.end());

		while (!strength.empty()) {
			int ind = -1;
			int a = strength.back();
			strength.pop_back();

			for (int i = 0; i < strength.size() - 1; ++i) {
				if (strength[i] + a > myTeam) {
					ind = i;
					break;
				}
			}

			if (ind == -1) {
				break;
			} else {
				strength.erase(strength.begin() + ind, strength.begin() + ind + 2);
				++res;
			}
		}

		return res + 1;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {5, 7, 3, 5, 7, 3, 5, 7, 3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(0, Arg1, worstRank(Arg0)); }
	void test_case_1() { int Arr0[] = {5, 7, 3}
; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(1, Arg1, worstRank(Arg0)); }
	void test_case_2() { int Arr0[] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(2, Arg1, worstRank(Arg0)); }
	void test_case_3() { int Arr0[] = {3,9,4,6,2,6,1,6,9,1,4,1,3,8,5}
; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(3, Arg1, worstRank(Arg0)); }
	void test_case_4() { int Arr0[] = {53,47,88,79,99,75,28,54,65,14,22,13,11,31,43}
; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(4, Arg1, worstRank(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	TeamContest ___test;
	___test.run_test(-1);
}
// END CUT HERE
