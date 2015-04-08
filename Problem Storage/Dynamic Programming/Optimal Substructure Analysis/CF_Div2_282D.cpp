#include <bits/stdc++.h>
using namespace std;

int a[3];
bool dp[305][305][305];
bool mini[305][305][305];
bool a0[305][305];

int main() {
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; ++i) scanf("%d", a + i);

	for (int i = 0; i <= a[0]; ++i) {
		bool a1[305] = { };
		for (int j = 0; j <= a[1]; ++j) {
			bool a2 = 0;
			for (int k = 0; k <= a[2]; ++k) {
				if (!i && !j && !k) continue;
				//update a2
				if (k) a2 |= !dp[i][j][k - 1];
				//update a1
				if (j) {
					a1[k] |= !dp[i][j - 1][k];
				}
				//update a0
				if (i) {
					a0[j][k] |= !dp[i - 1][j][k];
				}
				//update mini
				bool jj = 0, kk = 0;
				int mn = i;
				if (n > 1) {
					jj = 1;
					mn = min(mn, j);
				}
				if (n > 2) {
					kk = 1;
					mn = min(mn, k);
				}
				if (mn) {
					mini[i][j][k] |= mini[i - 1][j - jj][k - kk] | !dp[i - 1][j - jj][k - kk];
				}

				//update dp it self ;)
				dp[i][j][k] |= a2;
				dp[i][j][k] |= a1[k];
				dp[i][j][k] |= a0[j][k];
				dp[i][j][k] |= mini[i][j][k];
			}
		}
	}


	string ans[] = {"BitAryo", "BitLGM"};
	cout << ans[dp[a[0]][a[1]][a[2]]] << endl;
	return 0;
}

