#include <bits/stdc++.h>
using namespace std;

//for precalculations.
//const int MOD = 1000000007;
//const int MAXN = 11;
//
//map<pair<int, int>, int> memo;
//int n;
//
//bool one(int mask, int i) {
//	return (mask >> i) & 1;
//}
//
//int fact(int n) {
//	int ret = 1;
//	for (int i = 1; i <= n; ++i)
//		ret = (1LL * ret * i) % MOD;
//	return ret;
//}
//
//int get_ans(int mask2, int mask3, int ind) {
//	if (ind == n) return fact(n);
//
//	if (memo.count({mask2, mask3})) return memo[{mask2, mask3}];
//	int &ret = memo[{mask2,mask3}];
//	ret = 0;
//	for (int i = ind; i <= ind; ++i) {
//		for (int j = 0; j < n; ++j) {
//			if (!one(mask2, j) && !one(mask3, (i + j) % n))
//				ret = (ret + get_ans(mask2 | (1 << j), mask3 | (1 << ((i + j) % n)), ind + 1)) % MOD;
//		}
//	}
//	return ret;
//}

int arr[] = {1, 0, 18, 0, 1800, 0, 670320, 0, 734832000, 0, 890786230, 0, 695720788, 0, 150347555, 0};

int main() {
	int n;
	scanf("%d", &n);
	printf("%d\n", arr[n - 1]);
	return 0;
}
