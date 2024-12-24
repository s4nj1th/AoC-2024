#include <bits/stdc++.h>
#include <cstdio>
#include <fstream>
using namespace std;

pair<int, int> getPosn(int x, int y, int vX, int vY, int n=100) {
    for (int i = 0; i < n; i++) {
        x += vX;
        y += vY;

        if (x >= 101) x = x%101;
        if (y >= 103) y = y%103;

        if (x < 0) x = x+101;
        if (y < 0) y = y+103;
    }

    return {x, y};
}

int main() {

    vector<pair<int, int>> posns;

    ifstream inFile("input");
    string line;
    while (getline(inFile, line)) {
        int x, y, vX, vY;
        sscanf(line.c_str(), "p=%d,%d v=%d,%d", &x, &y, &vX, &vY);

        auto pos = getPosn(x, y, vX, vY);
        posns.push_back(pos);
    }

    int q1 = 0,
        q2 = 0,
        q3 = 0,
        q4 = 0;

    for (auto& [x, y] : posns) {
        if (x < 50 && y < 51) q1++;
        else if (x < 50 && y > 51) q2++;
        else if (x > 50 && y < 51) q3++;
        else if (x > 50 && y > 51) q4++;
        else continue;
    }

    cout << "Qs 1 to 4: " << q1 << " "<< q2 << " "<< q3 << " "<< q4 << endl;

    cout << "Safety Factor: " << q1*q2*q3*q4 << endl;

    return 0;
}