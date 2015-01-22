#include <bits/stdc++.h>
using namespace std;

long long dp[1 << 15][100];
int ten[55];
int mod[55];

class WickedTeacher {
public:
	string cheatProbability(vector <string> numbers, int k) {
		int n = numbers.size();
		memset(dp, 0, sizeof dp);


		//10^i % k = ten[i]
		for (int i = 1; i <= 50; ++i) {
			ten[i] = 1;
			for (int j = 0; j < i; ++j) {
				ten[i] = (ten[i] * 10) % k;
			}
		}

		//numbers[i] % k = mod[i]
		for (int i = 0; i < n; ++i) {
			mod[i] = 0;
			for (auto &x : numbers[i])
				mod[i] = ((mod[i] * 10) + x - '0') % k;
		}


		//the number of all the possible combinations = n!
		long long all = 1;
		for (int i = 1; i <= n; ++i) {
			all *= i;
		}

		//If we didn't use any number and the remainder is 0 then we have one way to do it.
		dp[0][0] = 1;

		//Try each possible combination of numbers;
		for (int mask = 1; mask < (1 << n); ++mask) {
			for (int i = 0; i < n; ++i) {
				//What if numbers[i] is the last number we concatenated in this set so far?
				if ((mask >> i) & 1) {
					//Get the last set that we added numbers[i] to.
					int pre = mask ^ (1 << i);
					for (int rem = 0; rem < k; ++rem) {
						//For each remainder the previous set has,
						//		What is the remainder that i can get to by adding numbers[i]?
						int nrem = ((rem * ten[numbers[i].size()]) + mod[i]) % k;
						//I can get to this new remainder
						//		by the same number of ways i can get to the old remainder from the previous set.
						dp[mask][nrem] += dp[pre][rem];
					}
				}
			}
		}

		//dp[(1 << n) - 1][0] represents the state where i took every number and the remainder is 0.

		//get the greatest common divisor to make the fraction irreducible.
		long long gcd = __gcd(all, dp[(1 << n) - 1][0]);
		return to_string(dp[(1 << n) - 1][0] / gcd) + "/" + to_string(all / gcd);
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"3","2","1"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; string Arg2 = "1/3"; verify_case(0, Arg2, cheatProbability(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {"10","100","1000","10000","100000"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 10; string Arg2 = "1/1"; verify_case(1, Arg2, cheatProbability(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"11","101","1001","10001","100001"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 10; string Arg2 = "0/1"; verify_case(2, Arg2, cheatProbability(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {"13","10129414190271203","102","102666818896","1216","1217","1218","101278001","1000021412678412681"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 21; string Arg2 = "5183/36288"; verify_case(3, Arg2, cheatProbability(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	WickedTeacher ___test;
	___test.run_test(-1);
}
// END CUT HERE
