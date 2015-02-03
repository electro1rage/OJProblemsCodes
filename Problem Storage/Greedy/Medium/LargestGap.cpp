#include <bits/stdc++.h>
using namespace std;


class LargestGap {
public:
	int getLargest(vector <string> board) {
		string s = accumulate(board.begin(), board.end(), string(""));

		vector<int> best;
		int res = -1;
		for (int i = 0; i < s.size(); ++i) {
			if (s[i] == 'X') {
				string s2 = s.substr(i) + s.substr(0, i) + 'X';
				vector<int> v;
				int len = 0;
				for (int j = 0; j < s2.size(); ++j) {
					if (s2[j] == '.') ++len;
					else if (len) {
						v.push_back(len);
						len = 0;
					}
				}
				if (v.size() > 1) v[0] += v.back(), v.pop_back();
				sort(v.rbegin(), v.rend());
				if (v > best) best = v, res = i;
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
	void test_case_0() { string Arr0[] = {".....X.X......."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 5; verify_case(0, Arg1, getLargest(Arg0)); }
	void test_case_1() { string Arr0[] = {"XXXX","....","XXXX","....","XXXX","...."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(1, Arg1, getLargest(Arg0)); }
	void test_case_2() { string Arr0[] = {"XXX.........XX...........XX..X"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 12; verify_case(2, Arg1, getLargest(Arg0)); }
	void test_case_3() { string Arr0[] = {"XXX","X.....","....XX..XXXXXX","X........X..",".XXX."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 32; verify_case(3, Arg1, getLargest(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	LargestGap ___test;
	___test.run_test(-1);
}
// END CUT HERE
