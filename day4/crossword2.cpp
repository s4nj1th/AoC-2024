#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

// Define directions for the search (row_delta, col_delta)
const vector<pair<int, int>> DIRECTIONS = {
    {0, 1},   // Horizontal (right)
    {0, -1},  // Horizontal (left)
    {1, 0},   // Vertical (down)
    {-1, 0},  // Vertical (up)
    {1, 1},   // Diagonal (bottom-right)
    {-1, -1}, // Diagonal (top-left)
    {1, -1},  // Diagonal (bottom-left)
    {-1, 1}   // Diagonal (top-right)
};

// Function to check if the word exists starting from (row, col) in a given direction
bool searchWord(const vector<string>& grid, const string& word, int row, int col, int dirRow, int dirCol) {
    int wordLen = word.size();
    int rows = grid.size();
    int cols = grid[0].size();

    for (int i = 0; i < wordLen; ++i) {
        int newRow = row + i * dirRow;
        int newCol = col + i * dirCol;

        // Check if we are out of bounds
        if (newRow < 0 || newRow >= rows || newCol < 0 || newCol >= cols) {
            return false;
        }

        // Check if the character matches
        if (grid[newRow][newCol] != word[i]) {
            return false;
        }
    }
    return true;
}

// Function to count occurrences of the word in the grid
int countWordOccurrences(const vector<string>& grid, const string& word) {
    int rows = grid.size();
    int cols = grid[0].size();
    int count = 0;

    for (int row = 0; row < rows; ++row) {
        for (int col = 0; col < cols; ++col) {
            // Try all directions from the current cell
            for (const auto& direction : DIRECTIONS) {
                if (searchWord(grid, word, row, col, direction.first, direction.second)) {
                    ++count;
                }
            }
        }
    }

    return count;
}

int main() {
    ifstream inFile("input");
    if (!inFile) {
        cerr << "Error opening file!" << endl;
        return 1;
    }

    // Read the grid from the file
    vector<string> grid;
    string line;
    while (getline(inFile, line)) {
        grid.push_back(line);
    }

    string word = "XMAS";
    int occurrences = countWordOccurrences(grid, word);

    cout << "Total occurrences of \"" << word << "\": " << occurrences << endl;

    return 0;
}
