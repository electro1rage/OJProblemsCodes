#include <bits/stdc++.h>
using namespace std;

int main() {
	//Try some polygons, draw the polygon mid point and the lines going from this midpoint to each other point on the polygon.
	//The sum of angels around the mid point should be 360.
	//Test if there is a number of edges/angles that can achieve this at each angle.
	bool good[180] = {};

	for (int i = 1; i < 180; ++i)
		good[i] = 360 % (180 - i) == 0;

	int t;
	scanf("%d", &t);

	string res[] = {"NO", "YES"};
	while (t--) {
		int angle;
		scanf("%d", &angle);

		cout << res[good[angle]] << endl;
	}
	return 0;
}
