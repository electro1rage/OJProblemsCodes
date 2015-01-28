#include <bits/stdc++.h>
using namespace std;

const double EPS = 1e-9;
const double PI = 3.14159265358979323846;

class ParticleCollision {
public:
	vector <double> collision(int vx, int vy, int vz, int x0, int y0, int z0) {
		double a = vx * vx + vy * vy;
		double b = 2 * vx * x0 + 2 * vy * y0;
		double c = x0 * x0 + y0 * y0 - 1;
		double d = b * b - 4 * a * c;
		if (!vx && !vy) {
			if (x0 * x0 + y0 * y0 == 1) {
				if (vz != 0)
					return vector<double> (3);
				else {
					if (abs(x0 - cos(PI * z0)) < EPS && abs(y0 - sin(PI * z0)) < EPS) {
						return vector<double> {x0, y0, z0};
					}
					return vector<double> ();
				}
			} else {
				return vector<double> ();
			}
		}

		if (d < 0)
			return vector<double> ();

		double t1 = (-b + sqrt(d)) / (2 * a);
		double t2 = (-b - sqrt(d)) / (2 * a);

		double x1 = vx * t1 + x0;
		double y1 = vy * t1 + y0;
		double z1 = vz * t1 + z0;
		bool ok1 = (abs(x1 - cos(PI * z1)) < EPS) && (abs(y1 - sin(PI * z1)) < EPS);

		double x2 = vx * t2 + x0;
		double y2 = vy * t2 + y0;
		double z2 = vz * t2 + z0;
		bool ok2 = (abs(x2 - cos(PI * z2)) < EPS) && (abs(y2 - sin(PI * z2)) < EPS);

		if (ok1 && ok2 && d != 0) {
			return vector<double> (3);
		}

		if (ok1) {
			return vector<double> {x1, y1, z1};
		}

		if (ok2) {
			return vector<double> {x2, y2, z2};
		}

		return vector<double> ();
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <double> &Expected, const vector <double> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { int Arg0 = 0; int Arg1 = 0; int Arg2 = 0; int Arg3 = 0; int Arg4 = 0; int Arg5 = 0; double Arr6[] = { }; vector <double> Arg6(Arr6, Arr6 + (sizeof(Arr6) / sizeof(Arr6[0]))); verify_case(0, Arg6, collision(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5)); }
	void test_case_1() { int Arg0 = 2; int Arg1 = 4; int Arg2 = 1; int Arg3 = -1; int Arg4 = -1; int Arg5 = 0; double Arr6[] = {0.0, 1.0, 0.5 }; vector <double> Arg6(Arr6, Arr6 + (sizeof(Arr6) / sizeof(Arr6[0]))); verify_case(1, Arg6, collision(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5)); }
	void test_case_2() { int Arg0 = 4; int Arg1 = 4; int Arg2 = 2; int Arg3 = 5; int Arg4 = 4; int Arg5 = 0; double Arr6[] = {0.0, 0.0, 0.0 }; vector <double> Arg6(Arr6, Arr6 + (sizeof(Arr6) / sizeof(Arr6[0]))); verify_case(2, Arg6, collision(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5)); }
	void test_case_3() { int Arg0 = 0; int Arg1 = 0; int Arg2 = 1; int Arg3 = 1; int Arg4 = 0; int Arg5 = 0; double Arr6[] = {0.0, 0.0, 0.0 }; vector <double> Arg6(Arr6, Arr6 + (sizeof(Arr6) / sizeof(Arr6[0]))); verify_case(3, Arg6, collision(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	ParticleCollision ___test;
	___test.run_test(-1);
}
// END CUT HERE
