#include <bits/stdc++.h>
using namespace std;

class RunningLetters {
public:
	vector<int> getLongestPrefixarr(string &message) {
		int m = message.size();
		vector<int> longestprefix(m);

		for (int i = 1, k = 0; i < m; ++i) {
			while (k > 0 && message[k] != message[i])
				k = longestprefix[k - 1];

			if (message[k] == message[i])
				++k;

			longestprefix[i] = k;
		}

		return longestprefix;
	}
	int newsLength(vector <string> running) {
		string algo;
		for (auto &x : running)
			algo += x;
		string message;
		int x;
		string text;

		stringstream ss(algo);
		while (ss >> x >> text) {
			for (int i = 0; i < x; ++i)
				message += text;
		}

		vector<int> longestprefix = getLongestPrefixarr(message);
		int n = message.size();

		return n - longestprefix[n - 1];
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"3 abc 1 ab"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(0, Arg1, newsLength(Arg0)); }
	void test_case_1() { string Arr0[] = {"1 babaaba"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 5; verify_case(1, Arg1, newsLength(Arg0)); }
	void test_case_2() { string Arr0[] = {"1 ba 1 c 1 bacba 3 cba"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(2, Arg1, newsLength(Arg0)); }
	void test_case_3() { string Arr0[] = {"42 runningletters 42 runningletters 1 running"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 14; verify_case(3, Arg1, newsLength(Arg0)); }
	void test_case_4() { string Arr0[] = {"1 b ", "1 a ", "1 b ", "1 a", " 1 b"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(4, Arg1, newsLength(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	RunningLetters ___test;
	___test.run_test(-1);
}
// END CUT HERE
