#include <bits/stdc++.h>
using namespace std;

int memo[1 << 18];
vector<string> s;

class Tdetectived2 {
public:
	int k, n;
	int get_ans(int mask) {
		int &ret = memo[mask];
		if (ret != -1) return ret;

		ret = 1010101010;

		int sub[18] = {}, i, j;
		for (i = 0; i < n; ++i) {
			if ((mask >> i) & 1) {
				for (j = 0; j < n; ++j) {
					sub[j] = max(sub[j], s[i][j] - '0');
				}
			}
		}
		vector<pair<int, int> > v;
		for (i = 0; i < n; ++i) {
			if ((mask >> i) & 1) continue;
			v.push_back({sub[i], i});
		}
		sort(v.rbegin(), v.rend());

		for (i = 0; i < v.size(); ++i) {
			if (v[i].first != v[0].first) break;
			if (v[i].second == k) return ret = 1;
			ret = min(ret, get_ans(mask | (1 << v[i].second)) + 1);
		}
		return ret;
	}
	int reveal(vector <string> s) {
		int n = s.size(), ans[18], ret, i;
		this->n = n;
		::s = s;
		for (i = 1; i < n; ++i) {
			memset(memo, -1, sizeof memo);
			k = i;
			ans[i] = get_ans(1);
		}
		ret = 0;
		for (i = 1; i < n; ++i) ret += i * ans[i];
		return ret;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"000","000","000"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(0, Arg1, reveal(Arg0)); }
	void test_case_1() { string Arr0[] = {"0224","2011","2104","4140"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 10; verify_case(1, Arg1, reveal(Arg0)); }
	void test_case_2() { string Arr0[] = {"0886","8086","8801","6610"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 12; verify_case(2, Arg1, reveal(Arg0)); }
	void test_case_3() { string Arr0[] = {"064675511","603525154","430262731","652030511","726302420","552020464","517544052","153126500","141104200"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 170; verify_case(3, Arg1, reveal(Arg0)); }
	void test_case_4() { string Arr0[] = {"0313131","3030020","1301132","3010031","1010003","3233003","1021330"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 37; verify_case(4, Arg1, reveal(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	Tdetectived2 ___test;
	___test.run_test(-1);
}
// END CUT HERE
