#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <cmath> // For abs()

using namespace std;

// Function to check if a report is safe
bool isSafe(const vector<int>& levels) {
    if (levels.size() < 2) {
        return true; // A single number or an empty report is safe by default
    }

    bool increasing = false;
    bool decreasing = false;

    for (size_t i = 1; i < levels.size(); ++i) {
        int diff = levels[i] - levels[i - 1];

        if (diff > 0) {
            increasing = true;
        } else if (diff < 0) {
            decreasing = true;
        }

        // Check if difference is outside the safe range
        if (abs(diff) < 1 || abs(diff) > 3) {
            return false; // Unsafe due to invalid difference
        }

        // If both increasing and decreasing trends are observed, it's unsafe
        if (increasing && decreasing) {
            return false;
        }
    }

    return true;
}

int main() {
    ifstream inFile("input"); // Open the file
    if (!inFile) {
        cerr << "Error opening file!" << endl;
        return 1;
    }

    string line;
    int safeReports = 0;

    // Process each line (each report)
    while (getline(inFile, line)) {
        vector<int> levels;
        istringstream stream(line);
        int num;

        // Read all numbers from the line into the vector
        while (stream >> num) {
            levels.push_back(num);
        }

        // Check if the current report is safe
        if (isSafe(levels)) {
            ++safeReports;
        }
    }

    inFile.close(); // Close the file

    // Output the number of safe reports
    cout << "Number of safe reports: " << safeReports << endl;

    return 0;
}
