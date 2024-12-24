#include <iostream>
#include <sstream>
#include <vector>
#include <map>
#include <string>
#include <fstream>
#include <algorithm>
using namespace std;

// Helper function to find the index of an element in a vector
int getIndex(const vector<int>& vec, int element) {
    auto it = find(vec.begin(), vec.end(), element);
    if (it != vec.end()) return it - vec.begin();
    return -1;
}

// Function to validate an update and return its middle element if valid
int middleOfValid(const vector<int>& pages, const map<int, vector<int>>& rules) {
    // Create a cache for indices of pages for optimization
    map<int, int> indexCache;
    for (size_t i = 0; i < pages.size(); ++i) {
        indexCache[pages[i]] = i;
    }

    // Validate the update against the rules
    for (int key : pages) {
        auto it = rules.find(key);
        if (it != rules.end()) { // Key has dependencies in rules
            for (int dependency : it->second) {
                if (indexCache.find(dependency) != indexCache.end() &&
                    indexCache[dependency] > indexCache[key]) {
                    return 0; // Rule violated
                }
            }
        }
    }

    // Return the middle element if valid
    return pages[pages.size() / 2];
}

int main() {
    ifstream inFile("input");
    if (!inFile) {
        cerr << "Error: Cannot open file!" << endl;
        return 1;
    }

    map<int, vector<int>> rules;
    string line;

    // Read rules
    while (getline(inFile, line) && !line.empty()) {
        istringstream ruleStream(line);
        int x, y;
        char pipe;
        ruleStream >> x >> pipe >> y;
        rules[y].push_back(x); // Store rule y depends on x
    }

    int sum = 0;

    // Read and process updates
    while (getline(inFile, line)) {
        vector<int> pages;
        istringstream pageStream(line);
        string page;
        while (getline(pageStream, page, ',')) {
            pages.push_back(stoi(page));
        }
        sum += middleOfValid(pages, rules);
    }

    cout << "Sum of middle pages: " << sum << endl;

    return 0;
}
