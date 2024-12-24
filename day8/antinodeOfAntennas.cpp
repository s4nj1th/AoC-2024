#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

vector<pair<int, int>> findAll(int i, int j, vector<string> OGgrid) {
    vector<pair<int, int>> pairs = {};

    for (int k = 0; k < OGgrid.size(); k++) {
        for (int l = 0; l < OGgrid[0].size(); l++) {
            if (k != i && l != j && OGgrid[k][l] == OGgrid[i][j]) {
                int delI = k-i,
                    delJ = l-j;
                pairs.push_back({k+delI, l+delJ});
                pairs.push_back({i-delI, j-delJ});
            }
        }
    }
    return pairs;
}

bool checkBounds(int i, int j, vector<string> grid) {
    int h = grid.size(),
        w = grid[0].size();
    
    if (i >= 0 && i < h &&
        j >= 0 && j < w) return true;
    return false;
}

int noOfAntinodes(vector<string> OGgrid) {
    vector<string> grid;
    int no = 0;

    for (int i = 0; i < OGgrid.size(); i++) {
        string line = "";
        for (int j = 0; j < OGgrid[0].size(); j++) {
            line += '.';
        }
        grid.push_back(line);
    }

    for (int i = 0; i < OGgrid.size(); i++) {
        for (int j = 0; j < OGgrid[0].size(); j++) {
            if (OGgrid[i][j] != '.') {
                for (auto [k, l] : findAll(i, j, OGgrid)) {
                    if (checkBounds(k, l, OGgrid)) grid[k][l] = '#';
                }
            }
        }
    }

    for (int i = 0; i < OGgrid.size(); i++) {
        for (int j = 0; j < OGgrid[0].size(); j++) {
            if (grid[i][j] == '#') no++;
        }
    }

    for (auto i : grid) {
        cout << i << endl;
    }

    return no;
}

int main() {

    ifstream inFile("input");
    string line;
    vector<string> grid;
    while (getline(inFile, line)) {
        grid.push_back(line);
    }

    // cout << "No of possible anti-nodes: " << noOfAntinodes(grid) << endl;
    cout << noOfAntinodes(grid) << endl;

    return 0;
}
