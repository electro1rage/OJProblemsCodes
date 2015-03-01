#include <bits/stdc++.h>
using namespace std;

long long box[100005];

int main() {
	int n, ind;
	scanf("%d %d", &n, &ind);
	--ind;

	for (int i = 0; i < n; ++i)
		cin >> box[i];

	long long mini = *min_element(box, box + n);
	long long sbox = mini * n;

	while (box[ind] != mini) {
		++sbox;
		--box[ind];
		ind = (ind - 1 + n) % n;
	}

	for (int i = 0; i < n; ++i)
		box[i] -= mini;
	box[ind] = sbox;

	for (int i = 0; i < n; ++i)
		cout << box[i] << ' ';cout << endl;
	return 0;
}
