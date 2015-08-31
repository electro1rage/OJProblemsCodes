#include <bits/stdc++.h>
using namespace std;

struct data {
	int start, finish;
	string s;
};

int X;
vector<data> ans[26];
vector<int> flor[26], room[26], visittime[26];
priority_queue<pair<int, int> > timeq[11][12], waitq[11][12];
//                              {time, agent}, {agent, time}
pair<int, int> finishroom[11][12];
//             {time, agent}
int remelev[11];
//  time remaining for the next in queue to enter the elevator.
int b[26];

inline int get_num(char c) {
	return c - '0';
}

inline int get_seconds(int hh, int mm, int ss) {
	return hh * 60 * 60 + mm * 60 + ss;
}

inline char* get_time(int seconds) {
	int hh = seconds / (60 * 60);
	int mm = (seconds % (60 * 60)) / 60;
	int ss = (seconds % (60 * 60)) % 60, i;
	char *ret;
	ret = new char[10];
	for (i = 0; i < 10; ++i) ret[i] = 0;
	sprintf(ret, "%02d:%02d:%02d", hh, mm, ss);
	return ret;
}

inline void push_timeq(int f, int r, int c, int t) {
	timeq[f][r].push({-t, c});
}

inline void push_waitq(int f, int r, int c, int t) {
	waitq[f][r].push({-c, t});
}

inline pair<int, int> get_timeq(int f, int r) {
	pair<int, int> ret = timeq[f][r].top(); timeq[f][r].pop();
	ret.first *= -1;
	swap(ret.first, ret.second);
	return ret;
}

inline string get_code(int f, int r) {
	char ret[6];
	sprintf(ret, "%02d%02d", f, r);
	return ret;
}

inline void leave_room(int f, int r) {
	pair<int, int> temp = finishroom[f][r]; finishroom[f][r] = {-1, 0.0};
	int agent = temp.second, time = temp.first;
	++b[agent];
	if (b[agent] == room[agent].size()) {
		if (f == 1) {
			ans[agent].push_back({time, time + 30, "Exit"});
			return ;
		}
		push_timeq(f, 11, agent, time + 10);
		ans[agent].push_back({time, time + 10, "Transfer from room "+ get_code(f, r) + " to elevator"});
		return ;
	}
	if (flor[agent][b[agent]] == f) {
		push_timeq(f, room[agent][b[agent]], agent, time + 10);
		ans[agent].push_back({time, time + 10, "Transfer from room " + get_code(f, r) +" to room " + get_code(f, room[agent][b[agent]])});
	} else {
		push_timeq(f, 11, agent, time + 10);
		ans[agent].push_back({time, time + 10, "Transfer from room "+ get_code(f, r) + " to elevator"});
	}
}

inline void enter_room(int f, int r) {
	if (waitq[f][r].empty()) return ;
	pair<int, int> temp = waitq[f][r].top(); waitq[f][r].pop();
	int agent = -temp.first, time = temp.second;

	finishroom[f][r] = {X + visittime[agent][b[agent]], agent};
	if (time != X) ans[agent].push_back({time, X, "Waiting in front of room " + get_code(f, r)});
	ans[agent].push_back({X, X + visittime[agent][b[agent]], "Stay in room " + get_code(f, r)});
}

inline void enter_elevator(int f) {
	if (waitq[f][11].empty()) return ;
	pair<int, int> temp = waitq[f][11].top(); waitq[f][11].pop();

	int agent = -temp.first, time = temp.second;
	if (time != X) ans[agent].push_back({time, X, "Waiting in elevator queue"});
	if (b[agent] == room[agent].size()) {
		ans[agent].push_back({X, X + 30 * abs(f - 1), "Stay in elevator"});
		ans[agent].push_back({X + 30 * abs(f - 1), X + 30 * abs(f - 1) + 30, "Exit"});
		return ;
	}
	ans[agent].push_back({X, X + 30 * abs(f - flor[agent][b[agent]]), "Stay in elevator"});
	ans[agent].push_back({X + 30 * abs(f - flor[agent][b[agent]]), X + 30 * abs(f - flor[agent][b[agent]]) + 10, "Transfer from elevator to room " + get_code(flor[agent][b[agent]], room[agent][b[agent]])});

	push_timeq(flor[agent][b[agent]], room[agent][b[agent]], agent, X + 30 * abs(f - flor[agent][b[agent]]) + 10);
}

void simulate(int ss) {
	X = ss;
	int i, j;
	for (i = 1; i < 11; ++i) {
		for (j = 1; j < 12; ++j) {
			while (!timeq[i][j].empty() && -timeq[i][j].top().first == X) {
				pair<int, int> res = get_timeq(i, j);
				push_waitq(i, j, res.first, res.second);
			}
		}
	}
	for (i = 1; i < 11; ++i) {
		for (j = 1; j < 11; ++j) {
			if (finishroom[i][j].first == X) leave_room(i, j);
		}
	}
	for (i = 1; i < 11; ++i) {
		for (j = 1; j < 11; ++j) {
			if (finishroom[i][j].first == -1) enter_room(i, j);
		}
	}
	for (i = 1; i < 11; ++i) {
		if (remelev[i] != 0) --remelev[i];
	}
	for (i = 1; i < 11; ++i) {
		if (X % 5 == 0) enter_elevator(i);
	}
}

int main() {
	char c;
	while (cin >> c && c != '.') {
		int hh, mm, ss;
		scanf("%d:%d:%d", &hh, &mm, &ss);
		string s;
		while (cin >> s && s != "0") {
			flor[c - 'A'].push_back(get_num(s[0]) * 10 + get_num(s[1]));
			room[c - 'A'].push_back(get_num(s[2]) * 10 + get_num(s[3]));
			int x;
			cin >> x;
			visittime[c - 'A'].push_back(x);
		}
		ans[c - 'A'].push_back({get_seconds(hh, mm ,ss), get_seconds(hh, mm, ss) + 30, "Entry"});
		if (flor[c - 'A'][0] != 1) push_timeq(1, 11, c - 'A', get_seconds(hh, mm, ss) + 30);
		else push_timeq(1, room[c - 'A'][0], c - 'A', get_seconds(hh, mm ,ss) + 30);
	}

	int i, j;
	for (i = 1; i < 11; ++i) for (j = 1; j < 11; ++j) finishroom[i][j] = {-1, 0.0};
	for (i = 0; i < 24 * 60 * 60; ++i) simulate(i);

	for (i = 0; i < 26; ++i) {
		if (ans[i].empty()) continue;
		int sz = ans[i].size();
		printf("%c\n", i + 'A');
		for (j = 0; j < sz; ++j) {
			printf("%s %s %s\n", get_time(ans[i][j].start), get_time(ans[i][j].finish), ans[i][j].s.c_str());
		}
		puts("");
	}
	return 0;
}
