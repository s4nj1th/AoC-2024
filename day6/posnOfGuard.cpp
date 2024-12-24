#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

vector<int> changeDir(int i, int j) {
    if (i == -1 && j == 0) return {0, 1};
    else if (i == 0 && j == 1) return {1, 0};
    else if (i == 1 && j == 0) return {0, -1};
    return {-1, 0};
}

vector<int> getPosn(vector<string>& grid) {
    int rows = grid.size(),
        cols = grid[0].size();

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (grid[i][j] == '^') return {i, j};
        }
    } return {-1, -1};
}

void moveThru(vector<string>& grid, int x, int y) {
    int rows = grid.size(),
        cols = grid[0].size(),
        dirX = -1,
        dirY = 0;

    int nextX = x + dirX,
        nextY = y + dirY;
    
    grid[x][y] = 'X';

    while (1) {
        if (x < 0 || x >= rows || y < 0 || y >= cols) break;
        grid[x][y] = 'X';

        int nextX = x + dirX, nextY = y + dirY;

        if (nextX < 0 || nextX >= rows || nextY < 0 || nextY >= cols) {
            return;
        } else if (grid[nextX][nextY] == '#') {
            auto newDir = changeDir(dirX, dirY);
            dirX = newDir[0];
            dirY = newDir[1];
        } else {
            x = nextX;
            y = nextY;
        }
    }
}

int countXs(vector<string>& grid) {
    int count = 0;
    for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[0].size(); j++) {
            if (grid[i][j] == 'X') count++;
        }
    }
    return count;
}

int noOfLoops(vector<string>& grid) {
    int loops = 0;
    auto init = getPosn(grid);
    moveThru(grid, init[0], init[1]);
    
    int dirX = -1,
        dirY = 0,
        x = init[0],
        y = init[1],
        rows = grid.size(),
        cols = grid[0].size();
    
    while (1) {
        if (1) return 1;
    } return 0;
}

int main() {

    string line;
    vector<string> grid;
    ifstream inFile("input");
    while (getline(inFile, line)) {
        grid.push_back(line);
    }
    auto grid2 = grid;
    
    vector<int> init = getPosn(grid);
    moveThru(grid, init[0], init[1]);

    cout << "No of distinct places: " << countXs(grid) << endl;
    cout << "No of possible loops: " << noOfLoops(grid2) << endl;

    ofstream outFile("output");
    for (auto s : grid) {
        outFile << s << "\n";
    }

    return 0;
}