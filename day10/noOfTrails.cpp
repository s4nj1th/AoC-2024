#include <bits/stdc++.h>
#include <fstream>
using namespace std;

bool isValid(vector<string>& grid, int r, int c, char h) {
    int rows = grid.size();
    int cols = grid[0].size();
    return r >= 0 && r < rows && c >= 0 && c < cols && grid[r][c] == h + 1;
}

int bfs(vector<string>& grid, int startRow, int startCol) {
    int rows = grid.size();
    int cols = grid[0].size();
    vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    queue<tuple<int, int, char>> q;
    set<pair<int, int>> visited;
    set<pair<int, int>> reachableNines;

    q.emplace(startRow, startCol, '0');
    visited.emplace(startRow, startCol);

    while (!q.empty()) {
        auto [r, c, currentHeight] = q.front();
        q.pop();

        if (grid[r][c] == '9') {
            reachableNines.emplace(r, c);
        }

        for (auto [dr, dc] : directions) {
            int nr = r + dr;
            int nc = c + dc;
            if (isValid(grid, nr, nc, currentHeight) && visited.find({nr, nc}) == visited.end()) {
                visited.emplace(nr, nc);
                q.emplace(nr, nc, grid[nr][nc]);
            }
        }
    }

    return reachableNines.size();
}

int sumTrailheadScores(vector<string>& grid) {
    int totalScore = 0;

    for (int r = 0; r < grid.size(); ++r) {
        for (int c = 0; c < grid[0].size(); ++c) {
            if (grid[r][c] == '0') {
                totalScore += bfs(grid, r, c);
            }
        }
    }

    return totalScore;
}

int main() {
    // vector<string> grid = {
    //     "89010123",
    //     "78121874",
    //     "87430965",
    //     "96549874",
    //     "45678903",
    //     "32019012",
    //     "01329801",
    //     "10456732"
    // };

    ifstream inFile("input");
    string line;
    vector<string> grid;
    while (getline(inFile, line)) {
        grid.push_back(line);
    }

    int result = sumTrailheadScores(grid);
    cout << "Sum of valid trailheads: " << result << endl;

    return 0;
}
