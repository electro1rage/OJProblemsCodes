#include <bits/stdc++.h>
using namespace std;


class GUMIAndSongsDiv1 {
public:
	int getTime(vector<pair<int, int> > Asuna) {
		if (Asuna.empty()) return 0;

		int time = 0;
		int n = Asuna.size();

		for (int i = 0; i < n; ++i)
			time += Asuna[i].second;

		return time + Asuna[n - 1].first - Asuna[0].first;
	}
int maxSongs(vector <int> duration, vector <int> tone, int T) {
	int res = 0;

	int n = duration.size();
	vector<pair<int, int> > Asuna;


	for (int i = 0; i < n; ++i) {
		if (duration[i] <= T) Asuna.push_back(make_pair(tone[i], duration[i]));
	}

	n = Asuna.size();
	sort(Asuna.begin(), Asuna.end());

	if (n) res = 1;

	for (int i = 0; i < n; ++i) {
		for (int j = i + 1; j < n; ++j) {
			vector<pair<int, int> > Kristina(Asuna.begin() + i, Asuna.begin() + j + 1);
			while (getTime(Kristina) > T) {
				int sz = j - i + 1;

				if (sz == 2) goto THERE;

				int best, t = 0;
				for (int k = 1; k < sz - 1; ++k) {
					if (t < Kristina[k].second) {
						t = Kristina[k].second;
						best = k;
					}
				}

				Kristina.erase(Kristina.begin() + best);
			}
			res = max(res, (int)Kristina.size());
			THERE:
			continue;
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
	void test_case_0() { int Arr0[] = {3, 5, 4, 11}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2, 1, 3, 1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 17; int Arg3 = 3; verify_case(0, Arg3, maxSongs(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arr0[] = {100, 200, 300}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, 2, 3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 99; int Arg3 = 0; verify_case(1, Arg3, maxSongs(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arr0[] = {1, 2, 3, 4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, 1, 1, 1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 100; int Arg3 = 4; verify_case(2, Arg3, maxSongs(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arr0[] = {9, 11, 13, 17}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2, 1, 3, 4}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 20; int Arg3 = 1; verify_case(3, Arg3, maxSongs(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arr0[] = {87,21,20,73,97,57,12,80,86,97,98,85,41,12,89,15,41,17,68,37,21,1,9,65,4,
 67,38,91,46,82,7,98,21,70,99,41,21,65,11,1,8,12,77,62,52,69,56,33,98,97}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {88,27,89,2,96,32,4,93,89,50,58,70,15,48,31,2,27,20,31,3,23,86,69,12,59,
 61,85,67,77,34,29,3,75,42,50,37,56,45,51,68,89,17,4,47,9,14,29,59,43,3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 212; int Arg3 = 12; verify_case(4, Arg3, maxSongs(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	GUMIAndSongsDiv1 ___test;
	___test.run_test(-1);
}
// END CUT HERE
