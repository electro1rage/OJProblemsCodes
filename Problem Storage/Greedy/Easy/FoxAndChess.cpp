#include <bits/stdc++.h>
using namespace std;

class FoxAndChess {
public:
string ableToMove(string begin, string target) {
	string res[] = {"Impossible" , "Possible"};
	vector<int> Rb , Rt , Lb , Lt;

	int sz = begin.size();

	for(int i = 0 ; i < sz ; ++i) {
		if(begin[i] == 'R')Rb.push_back(i);
		if(begin[i] == 'L')Lb.push_back(i);
		if(target[i] == 'R')Rt.push_back(i);
		if(target[i] == 'L')Lt.push_back(i);
	}

	if(Rb.size() != Rt.size() || Lb.size() != Lt.size())return res[0];

	int rsz = Rb.size() , lsz = Lb.size();
	for(int i = 0 ; i < rsz ; ++i) {
		if(Rb[i] > Rt[i])return res[0];
	}

	for(int i = 0 ; i < lsz ; ++i) {
		if(Lb[i] < Lt[i])return res[0];
	}

	for(int i = 0 ; i < rsz ; ++i) {
		int smlb = 0 , smlt = 0;
		for(int j = 0 ; j < lsz ; ++j) {
			if(Lb[j] < Rb[i])++smlb;
			if(Lt[j] < Rt[i])++smlt;
		}

		if(smlb != smlt)return res[0];
	}

	return res[1];
}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "R..."; string Arg1 = "..R."; string Arg2 = "Possible"; verify_case(0, Arg2, ableToMove(Arg0, Arg1)); }
	void test_case_1() { string Arg0 = "..R."; string Arg1 = "R..."; string Arg2 = "Impossible"; verify_case(1, Arg2, ableToMove(Arg0, Arg1)); }
	void test_case_2() { string Arg0 = ".L.R.R."; string Arg1 = "L...R.R"; string Arg2 = "Possible"; verify_case(2, Arg2, ableToMove(Arg0, Arg1)); }
	void test_case_3() { string Arg0 = ".L.R."; string Arg1 = ".R.L."; string Arg2 = "Impossible"; verify_case(3, Arg2, ableToMove(Arg0, Arg1)); }
	void test_case_4() { string Arg0 = "LRLLRLRLLRLLRLRLRL"; string Arg1 = "LRLLRLRLLRLLRLRLRL"; string Arg2 = "Possible"; verify_case(4, Arg2, ableToMove(Arg0, Arg1)); }
	void test_case_5() { string Arg0 = "L"; string Arg1 = "."; string Arg2 = "Impossible"; verify_case(5, Arg2, ableToMove(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	FoxAndChess ___test;
	___test.run_test(-1);
}
// END CUT HERE
