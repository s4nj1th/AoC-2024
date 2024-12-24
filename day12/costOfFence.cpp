#include <bits/stdc++.h>
using namespace std;

const vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

bool isValid(int r, int c, const vector<string>& grid, vector<vector<bool>>& visited) {
    int rows = grid.size();
    int cols = grid[0].size();
    return r >= 0 && r < rows && c >= 0 && c < cols && !visited[r][c];
}

pair<int, int> floodFill(const vector<string>& grid, vector<vector<bool>>& visited, int startRow, int startCol) {
    int rows = grid.size();
    int cols = grid[0].size();
    char plantType = grid[startRow][startCol];
    int area = 0, perimeter = 0;

    queue<pair<int, int>> q;
    q.emplace(startRow, startCol);
    visited[startRow][startCol] = true;

    while (!q.empty()) {
        auto [r, c] = q.front();
        q.pop();
        area++;

        for (auto [dr, dc] : directions) {
            int nr = r + dr;
            int nc = c + dc;

            if (nr >= 0 && nr < rows && nc >= 0 && nc < cols) {
                if (grid[nr][nc] == plantType && !visited[nr][nc]) {
                    visited[nr][nc] = true;
                    q.emplace(nr, nc);
                } else if (grid[nr][nc] != plantType) {
                    perimeter++;
                }
            } else {
                perimeter++;
            }
        }
    }

    return {area, perimeter};
}

int totalFencingCost(const vector<string>& grid) {
    int rows = grid.size();
    int cols = grid[0].size();
    vector<vector<bool>> visited(rows, vector<bool>(cols, false));
    int totalCost = 0;

    for (int r = 0; r < rows; ++r) {
        for (int c = 0; c < cols; ++c) {
            if (!visited[r][c]) {
                auto [area, perimeter] = floodFill(grid, visited, r, c);
                totalCost += area * perimeter;
            }
        }
    }

    return totalCost;
}

int main() {
    // vector<string> grid = {
    //     "RRRRIICCFF",
    //     "RRRRIICCCF",
    //     "VVRRRCCFFF",
    //     "VVRCCCJFFF",
    //     "VVVVCJJCFE",
    //     "VVIVCCJJEE",
    //     "VVIIICJJEE",
    //     "MIIIIIJJEE",
    //     "MIIISIJEEE",
    //     "MMMISSJEEE"
    // };

    vector<string> grid;
    string line;
    ifstream inFile("input");

    while (getline(inFile, line)) {
        grid.push_back(line);
    }

    cout << "Total fencing cost: " << totalFencingCost(grid) << endl;

    return 0;
}
