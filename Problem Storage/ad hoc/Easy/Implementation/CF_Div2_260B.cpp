#include <bits/stdc++.h>
using namespace std;

map<int, int> m;

int month[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int sstoi(string s) {
    int ret;
    stringstream(s) >> ret;
    return ret;
}

void go(string s) {
    if (isdigit(s[0]) && isdigit(s[1]) && s[2] == '-' && isdigit(s[3]) && isdigit(s[4]) && s[5] == '-' && isdigit(s[6]) && isdigit(s[7]) && isdigit(s[8]) && isdigit(s[9])) {
        int day = sstoi(s.substr(0, 2));
        int mm = sstoi(s.substr(3, 2));
        int year = sstoi(s.substr(6, 4));

        if (mm < 1 || mm > 12) return;
        if (day < 1 || day > month[mm - 1]) return;
        if (year < 2013 || year > 2015) return;

        m[(day * 100 + mm) * 10000 + year]++;
    }
}

int main() {
    string s;
    cin >> s;

    for (int i = 0; i < s.size() - 9; ++i) {
        go(s.substr(i, 10));
    }

    int mx = -1, val;
    for (auto it = m.begin(); it != m.end(); ++it) {
        if (mx < it->second) {
            mx = it->second;
            val = it->first;
        }
    }


    printf("%02d-%02d-%d\n", val / 1000000, val / 10000 % 100, val % 10000);
    return 0;
}
