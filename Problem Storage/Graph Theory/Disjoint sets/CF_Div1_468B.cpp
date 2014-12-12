#include <bits/stdc++.h>
using namespace std;

map<int, int> Akame;
int Asuna[100005];
int Kristina[100005];
int Mikasa[100005];
int can[100005];

int parent(int i) {
	while (Asuna[i] != i) {
		Asuna[i] = Asuna[Asuna[i]];
		i = Asuna[i];
	}
	return i;
}

int main() {
	int n, a, b;
	scanf("%d %d %d", &n, &a, &b);

	for (int i = 0; i < n; ++i) {
		int x;
		scanf("%d", &x);
		Akame[x] = i;
		Asuna[i] = i;
		Mikasa[i] = x;
	}

	for (int i = 0; i < n; ++i) {
		if (Akame.count(a - Mikasa[i])) Asuna[parent(Akame[a - Mikasa[i]])] = parent(i), Kristina[i] |= 1;
		if (Akame.count(b - Mikasa[i])) Asuna[parent(Akame[b - Mikasa[i]])] = parent(i), Kristina[i] |= 2;
	}

	for (int i = 0; i < n; ++i)
		can[i] = 3;
	for (int i = 0; i < n; ++i)
		can[parent(i)] &= Kristina[i];

	for (int i = 0; i < n; ++i)
		if (!can[parent(i)]) {
			puts("NO");
			return 0;
		}

	puts("YES");
	for (int i = 0; i < n; ++i) {
		int val = can[parent(i)];
		putchar('0' + (!(val & 1)));
		if (i != n - 1) putchar(' ');
	}
	puts("");

	return 0;
}
