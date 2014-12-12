#include <bits/stdc++.h>
using namespace std;

bool vst[27];
int kristina[26];

class GooseTattarrattatDiv1 {
public:
	int maxi;
	int all;
	vector<vector<int> > asuna;
void DFS(int node) {
	if (vst[node]) return;
	vst[node] = 1;

	all += kristina[node];
	maxi = max(maxi, kristina[node]);

	int n = asuna[node].size();
	for (int i = 0; i < n; ++i)
		DFS(asuna[node][i]);
}
int getmin(string S) {
	int n = S.size();
	int res = 0;

	asuna = vector<vector<int> > (26, vector<int>());

	for (int i = 0; i < n; ++i) {
		int ind = n - i - 1;
		asuna[S[i] - 'a'].push_back(S[ind] - 'a');
		++kristina[S[i] - 'a'];
	}

	for (int i = 0; i < n; ++i) {
		if (!vst[S[i] - 'a']) {
			maxi = -1;
			all = 0;
			DFS(S[i] - 'a');
			res += all - maxi;
		}
	}

	return res;
}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "geese"; int Arg1 = 2; verify_case(0, Arg1, getmin(Arg0)); }
	void test_case_1() { string Arg0 = "tattarrattat"; int Arg1 = 0; verify_case(1, Arg1, getmin(Arg0)); }
	void test_case_2() { string Arg0 = "xyyzzzxxx"; int Arg1 = 2; verify_case(2, Arg1, getmin(Arg0)); }
	void test_case_3() { string Arg0 = "xrepayuyubctwtykrauccnquqfuqvccuaakylwlcjuyhyammag"; int Arg1 = 11; verify_case(3, Arg1, getmin(Arg0)); }
	void test_case_4() { string Arg0 = "abaabb"; int Arg1 = 3; verify_case(4, Arg1, getmin(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	GooseTattarrattatDiv1 ___test;
	___test.run_test(-1);
}
// END CUT HERE
