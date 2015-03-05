#include <bits/stdc++.h>
using namespace std;

class RelativelyPrimeSubset {
public:
	bool is_prime(int x) {
		for (int i = 2; i < x; ++i)
			if (x % i == 0) return false;
		return true;
	}
	int findSize(vector <int> S) {
		vector<int> prime;
		for (int i = 2; i < 100; ++i)
			if (is_prime(i)) prime.push_back(i);

		int primesz = prime.size();

		int primes = 0;
		for (int i = 0; i < S.size(); ++i) {
			for (int j = 15; j < prime.size(); ++j) {
				if (prime[j] == S[i] || S[i] == 1) {
					++primes;
					S.erase(S.begin() + i);
					--i;
					break;
				}
			}
		}

		int dp[1 << 15] = {};

		vector<int> mask;
		for (auto &x : S) {
			int have = 0;
			for (int i = 0; i < primesz; ++i) {
				if (x % prime[i] == 0) have |= 1 << i;
			}
			mask.push_back(have);
			dp[have] = 1;
		}

		int ans = 0;
		for (int i = 1; i < (1 << 15); ++i) {
			if (!dp[i]) continue;
			ans = max(ans, dp[i]);
			for (int j = 0; j < S.size(); ++j) {
				if (!(i & mask[j])) {
					dp[i | mask[j]] = max(dp[i | mask[j]], dp[i] + 1);
				}
			}
		}

		return ans + primes;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {2,3,7,11,4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; verify_case(0, Arg1, findSize(Arg0)); }
	void test_case_1() { int Arr0[] = {4,8,12,16}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(1, Arg1, findSize(Arg0)); }
	void test_case_2() { int Arr0[] = {100,17,81,82}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(2, Arg1, findSize(Arg0)); }
	void test_case_3() { int Arr0[] = {2,3,4,5,6}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(3, Arg1, findSize(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	RelativelyPrimeSubset ___test;
	___test.run_test(-1);
}
// END CUT HERE
