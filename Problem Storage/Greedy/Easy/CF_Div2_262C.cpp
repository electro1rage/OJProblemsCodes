#include <bits/stdc++.h>
using namespace std;

int main() {
	int m;
	scanf("%d", &m);

	int bestdis = 1000000;
	for (int i = 0; i < m; ++i) {
		int dis;
		scanf("%d", &dis);
		bestdis = min(bestdis, dis);
	}

	int n;
	scanf("%d", &n);
	priority_queue<int> price;

	for (int i = 0; i < n; ++i) {
		int cost;
		scanf("%d", &cost);
		price.push(cost);
	}

	int money = 0;
	while (price.size() >= bestdis) {
		for (int i = 0; i < bestdis; ++i) {
			money += price.top();
			price.pop();
		}
		if (!price.empty()) price.pop();
		if (!price.empty()) price.pop();
	}

	while (!price.empty()) {
		money += price.top();
		price.pop();
	}

	printf("%d\n", money);
	return 0;
}






