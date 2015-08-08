#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for((i)=0;(i)<(int)(n);++(i))

int prime[] = {2, 3, 5, 7, 11, 13, 17};
double memo[19][19][19];

class PrimeSoccer {
public:
	int skilla, skillb;
	double get_ans(int i, int a, int b) {
		if (i == 18) {
			int j;
			REP(j, 7) if (prime[j] == a || prime[j] == b) return 1;
			return 0;
		}

		double &ret = memo[i][a][b];
		if (ret == ret) return ret;

		ret = 0;
		ret += get_ans(i + 1, a + 1, b) * (skilla / 100.0) * (1 - skillb / 100.0);
		ret += get_ans(i + 1, a, b + 1) * (1 - skilla / 100.0) * (skillb / 100.0);
		ret += get_ans(i + 1, a + 1, b + 1) * (skilla / 100.0) * (skillb / 100.0);
		ret += get_ans(i + 1, a, b) * (1 - skilla / 100.0) * (1 - skillb / 100.0);

		return ret;
	}
	double getProbability(int skillOfTeamA, int skillOfTeamB) {
		memset(memo, -1, sizeof memo);
		skilla = skillOfTeamA, skillb = skillOfTeamB;
		return get_ans(0, 0, 0);
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 50; int Arg1 = 50; double Arg2 = 0.5265618908306351; verify_case(0, Arg2, getProbability(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 100; int Arg1 = 100; double Arg2 = 0.0; verify_case(1, Arg2, getProbability(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 12; int Arg1 = 89; double Arg2 = 0.6772047168840167; verify_case(2, Arg2, getProbability(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	PrimeSoccer ___test;
	___test.run_test(-1);
}
// END CUT HERE
