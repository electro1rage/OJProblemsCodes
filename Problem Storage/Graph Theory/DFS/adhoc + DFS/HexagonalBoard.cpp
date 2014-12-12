#include <bits/stdc++.h>
using namespace std;

int vst[55][55];
int dx[] = {-1 , -1 , 0 , 0 , 1 , 1};
int dy[] = {0 , 1 , 1 , -1 , -1 , 0};
vector<string> board;

class HexagonalBoard {
public:
	int res , n;
	void DFS(int x , int y , int color) {
		if(res == 3)return;
		if(vst[x][y] != -1 && vst[x][y] != color) {
			res = 3;
			return;
		}
		if(vst[x][y] == -1) {
			res = max(res , color + 1);
			vst[x][y] = color;
		}
		else return;

		for(int i = 0 ; i < 6 ; ++i) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if(nx >= 0 && nx < n && ny >= 0 && ny < n && board[nx][ny] == 'X') {
				DFS(nx , ny , !color);
			}
		}
	}
	int minColors(vector <string> board) {
		n = board.size();
		res = 0;
		memset(vst , -1 , sizeof vst);
		::board = board;

		for(int i = 0 ; i < n ; ++i) {
			for(int j = 0 ; j < n ; ++j) {
				if(vst[i][j] == -1 && board[i][j] == 'X')DFS(i , j , 0);
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
	void test_case_0() { string Arr0[] = {"---",
 "---",
 "---"}
 ; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(0, Arg1, minColors(Arg0)); }
	void test_case_1() { string Arr0[] = {"-X--",
 "---X",
 "----",
 "-X--"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(1, Arg1, minColors(Arg0)); }
	void test_case_2() { string Arr0[] = {"XXXX",
 "---X",
 "---X",
 "---X"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(2, Arg1, minColors(Arg0)); }
	void test_case_3() { string Arr0[] = {"XX-XX--"
,"-XX-XXX"
,"X-XX--X"
,"X--X-X-"
,"XX-X-XX"
,"-X-XX-X"
,"-XX-XX-"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(3, Arg1, minColors(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	HexagonalBoard ___test;
	___test.run_test(-1);
}
// END CUT HERE
