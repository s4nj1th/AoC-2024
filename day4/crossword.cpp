#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

bool findH(vector<string>& grid, int i, int j) {
  if (j <= grid[0].size()-4) {
      if (grid[i][j] == 'X' &&
          grid[i][j+1] == 'M' &&
          grid[i][j+2] == 'A' &&
          grid[i][j+3] == 'S') return true;
  } return false;
}
bool findV(vector<string>& grid, int i, int j) {
  if (i <= grid.size()-4) {
      if (grid[i][j] == 'X' &&
          grid[i+1][j] == 'M' &&
          grid[i+2][j] == 'A' &&
          grid[i+3][j] == 'S') return true;
  } return false;
}
bool findD(vector<string>& grid, int i, int j) {
  if (j <= grid[0].size()-4 && i <= grid.size()-4) {
    if (grid[i][j] == 'X' &&
        grid[i+1][j+1] == 'M' &&
        grid[i+2][j+2] == 'A' &&
        grid[i+3][j+3] == 'S') return true;
  } return false;
}
bool findD2(vector<string>& grid, int i, int j) {
  if (j >= 3 && i <= grid.size()-4) {
    if (grid[i][j] == 'X' &&
        grid[i+1][j-1] == 'M' &&
        grid[i+2][j-2] == 'A' &&
        grid[i+3][j-3] == 'S') return true;
  } return false;
}
bool findHRev(vector<string>& grid, int i, int j) {
  if (j >= 3) {
      if (grid[i][j] == 'X' &&
          grid[i][j-1] == 'M' &&
          grid[i][j-2] == 'A' &&
          grid[i][j-3] == 'S') return true;
  } return false;
}
bool findVRev(vector<string>& grid, int i, int j) {
  if (i >= 3) {
      if (grid[i][j] == 'X' &&
          grid[i-1][j] == 'M' &&
          grid[i-2][j] == 'A' &&
          grid[i-3][j] == 'S') return true;
  } return false;
}
bool findDRev(vector<string>& grid, int i, int j) {
  if (j >= 3 && i >= 3) {
    if (grid[i][j] == 'X' &&
        grid[i-1][j-1] == 'M' &&
        grid[i-2][j-2] == 'A' &&
        grid[i-3][j-3] == 'S') return true;
  } return false;
}
bool findD2Rev(vector<string>& grid, int i, int j) {
  if (j <= grid[0].size()-4 && i >= 3) {
    if (grid[i][j] == 'X' &&
        grid[i-1][j+1] == 'M' &&
        grid[i-2][j+2] == 'A' &&
        grid[i-3][j+3] == 'S') return true;
  } return false;
}

int findWord(vector<string>& grid) {
  int rows = grid.size(),
      cols = grid[0].size(),
      sum = 0;

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      if (grid[i][j] == 'X') {
        if (findH(grid, i, j)) sum++;
        if (findV(grid, i, j)) sum++;
        if (findD(grid, i, j)) sum++;
        if (findD2(grid, i, j)) sum++;
        if (findHRev(grid, i, j)) sum++;
        if (findVRev(grid, i, j)) sum++;
        if (findDRev(grid, i, j)) sum++;
        if (findD2Rev(grid, i, j)) sum++;
      }
    }
  } return sum;
}

bool check(vector<string>& grid, int i, int j) {
  if (i >= 1 && j >= 1 && i <= grid.size()-1 && j <= grid[0].size()-1) {
    if (((grid[i-1][j-1] == 'M' && grid[i+1][j+1] == 'S') ||
          (grid[i-1][j-1] == 'S' && grid[i+1][j+1] == 'M')) &&
        ((grid[i+1][j-1] == 'M' && grid[i-1][j+1] == 'S') ||
         (grid[i+1][j-1] == 'S' && grid[i-1][j+1] == 'M'))) return true;
  }
  return false;
}

int findWord2(vector<string>& grid) {
  int rows = grid.size(),
      cols = grid[0].size(),
      sum = 0;

  for (int i = 1; i < rows-1; i++) {
    for (int j = 1; j < cols-1; j++) {
      if (grid[i][j] == 'A') {
        if (check(grid, i, j)) sum++;
      }
    }
  } return sum;
}

int main() {
  ifstream inFile("input");
  vector<string> grid;
  string line;
  while (getline(inFile, line)) {
    grid.push_back(line);
  }
  cout << "No of times \"XMAS\": " << findWord(grid) << endl;
  cout << "No of times \"X-MAS\": " << findWord2(grid) << endl;

  return 0;
}
