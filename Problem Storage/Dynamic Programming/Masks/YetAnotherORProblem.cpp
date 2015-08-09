#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000009;

int memo[61][1 << 10], n;
vector<long long> a;

class YetAnotherORProblem {
public:
	int get_count(int i, int mask) {
		if (i == -1) return 1;
		int &ret = memo[i][mask], j, k;
		if (ret == -1) {
			ret = 0;
			int zmask = mask;
			for (k = 0; k < n; ++k) {
				if (!((mask >> k) & 1) && ((a[k] >> i) & 1)) {
					zmask |= 1 << k;
				}
			}
			ret = (ret + get_count(i - 1, zmask)) % MOD;

			for (j = 0; j < n; ++j) {
				if (((mask >> j) & 1) || ((a[j] >> i) & 1)) {
					int nmask = mask;
					for (k = 0; k < n; ++k) {
						if (j == k) continue;
						if (!((mask >> k) & 1) && ((a[k] >> i) & 1)) nmask |= 1 << k;
					}
					ret = (ret + get_count(i - 1, nmask)) % MOD;
				}
			}
		}
		return ret;
	}
	int countSequences(vector<long long> R) {
		memset(memo, -1, sizeof memo), a = R, n = a.size();
		return get_count(60, 0);
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { long Arr0[] = {3,5}; vector<long long> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 15; verify_case(0, Arg1, countSequences(Arg0)); }
	void test_case_1() { long Arr0[] = {3,3,3}; vector<long long> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 16; verify_case(1, Arg1, countSequences(Arg0)); }
	void test_case_2() { long Arr0[] = {1,128}; vector<long long> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 194; verify_case(2, Arg1, countSequences(Arg0)); }
	void test_case_3() { long Arr0[] = {26,74,25,30}; vector<long long> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 8409; verify_case(3, Arg1, countSequences(Arg0)); }
	void test_case_4() { long Arr0[] = {1000000000,1000000000}; vector<long long> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 420352509; verify_case(4, Arg1, countSequences(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	YetAnotherORProblem ___test;
	___test.run_test(-1);
}
// END CUT HERE
