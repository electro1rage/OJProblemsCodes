#include <bits/stdc++.h>
using namespace std;

#define PI 3.14159265

class TrianglesContainOrigin {
public:
vector<double> a;

int biggerSmallerThan(double val) {
	int start = 0, end = a.size() - 1;
	int res = -1;
	while (start <= end) {
		int mid = (start + end) / 2;
		if (a[mid] < val) {
			start = mid + 1;
			res = mid;
		}
		else {
			end = mid - 1;
		}
	}
	return res;
}

long long count(vector <int> x, vector <int> y) {
	long long res = 0;
	a.clear();
	int n = x.size();

	for (int i = 0; i < n; ++i) {
		double res = atan2(y[i], x[i]) * 180 / PI;
		if (res < 0) {
			a.push_back(360 + res);
		}
		else {
			a.push_back(res);
		}
	}

	sort(a.begin(), a.end());

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (i == j) continue;
			int x1 = x[i], y1 = y[i];
			int x2 = x[j], y2 = y[j];

			double one = atan2(y1, x1) * 180 / PI;
			if (one < 0) one += 360;
			double two = atan2(y2, x2) * 180 / PI;
			if (two < 0) two += 360;

			one = (one + 180);
			two = (two + 180);

			if (one >= 360) one -= 360;
			if (two >= 360) two -= 360;

			if (one > two) swap(one, two);

			int ind1, ind2;
			if (two - one > 180) {
				ind1 = biggerSmallerThan(one);
				ind2 = upper_bound(a.begin(), a.end(), two) - a.begin();

				if (ind1 == -1 && ind2 == -1) continue;

				if (ind2 != -1) res += n - ind2;
				if (ind1 != -1) res += ind1 + 1;
			}
			else {
				ind2 = biggerSmallerThan(two);
				ind1 = upper_bound(a.begin(), a.end(), one) - a.begin();
				if (ind1 == -1 || ind2 == -1) continue;
				if (a[ind1] < two) {
					res += ind2 - ind1 + 1;
				}
				else continue;
			}
		}
	}

	return res / 6;
}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {-1,-1,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,-1,0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arg2 = 1LL; verify_case(0, Arg2, count(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {-1,-1,1,2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,-1,2,-1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arg2 = 2LL; verify_case(1, Arg2, count(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {-1,-2,3,3,2,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {-2,-1,1,2,3,3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arg2 = 8LL; verify_case(2, Arg2, count(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {1,5,10,5,-5,7,-9,-6,-3,0,8,8,1,-4,7,-3,10,9,-6}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {5,-6,-3,4,-2,-8,-7,2,7,4,2,0,-4,-8,7,5,-5,-2,-9}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arg2 = 256LL; verify_case(3, Arg2, count(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	TrianglesContainOrigin ___test;
	___test.run_test(-1);
}
// END CUT HERE
