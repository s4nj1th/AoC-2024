#include <bits/stdc++.h>
using namespace std;

int calculateTokens(int Ax, int Ay, int Bx, int By, int Px, int Py) {
    for (int a = 0; a <= 100; ++a) {
        for (int b = 0; b <= 100; ++b) {
            int x = a * Ax + b * Bx;
            int y = a * Ay + b * By;

            if (x == Px && y == Py) {
                return a * 3 + b * 1;
            }
        }
    }
    return INT_MAX;
}

int main() {
    ifstream inFile("input");
    string line;
    vector<int> numbers;
    vector<vector<int>> machines;
    int totalTokens = 0;
    int prizesWon = 0;

    while (getline(inFile, line)) {
        int Ax, Ay, Bx, By, Px, Py;

        sscanf(line.c_str(), "Button A: X+%d, Y+%d", &Ax, &Ay);
        getline(inFile, line);

        sscanf(line.c_str(), "Button B: X+%d, Y+%d", &Bx, &By);
        getline(inFile, line);

        sscanf(line.c_str(), "Prize: X=%d, Y=%d", &Px, &Py);
        getline(inFile, line);

        int cost = calculateTokens(Ax, Ay, Bx, By, Px, Py);
        if (cost != INT_MAX) {
            totalTokens += cost;
            prizesWon++;
        }
    }

    inFile.close();

    for (int i = 0; i < machines.size(); i += 3) {
        int Ax = machines[i][0], Ay = machines[i][1];
        int Bx = machines[i + 1][0], By = machines[i + 1][1];
        int Px = machines[i + 2][0], Py = machines[i + 2][1];

        int cost = calculateTokens(Ax, Ay, Bx, By, Px, Py);
        if (cost != INT_MAX) {
            totalTokens += cost;
            prizesWon++;
        }
    }

    cout << "Prizes won: " << prizesWon << endl;
    cout << "Total tokens spent: " << totalTokens << endl;

    return 0;
}
