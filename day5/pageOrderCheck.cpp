#include <iostream>
#include <sstream>
#include <vector>
#include <map>
#include <string>
#include <fstream>
#include <algorithm>
using namespace std;

int getIndex(vector<int>& pages, int element) {
  auto index = find(pages.begin(), pages.end(), element);
  if (index == pages.end()) return -1;
  return index - pages.begin();
}

int middleOfValid(vector<int>& pages, map<int, vector<int>>& rules) {
  int mid = pages[pages.size()/2];
  for (int i : pages) {
    auto keyIndex = rules.find(i);
    if (keyIndex != rules.end()) {
      for (auto j : rules[i]) {
        if (getIndex(pages, j) == -1) continue;
        else if (getIndex(pages, j) > getIndex(pages, i)) return 0;
      }
    }
  }
  cout << mid << endl;
  return mid;
}

int main() {
  ifstream inFile("input");

  // vector<string> grid;
  string line;
  // istringstream stream;
  map<int, vector<int>> rules;
  int sum = 0;

  while (getline(inFile, line, '\n') && !line.empty()) {
    char pipe;
    int x;
    int y;
    cin >> x >> pipe >> y;
    rules[y].push_back(x);
  } while (getline(inFile, line)) {
    vector<int> pages;
    string page;
    istringstream stream(line);
    while(getline(stream, page, ',')) {
      pages.push_back(stoi(page));
    }
    sum += middleOfValid(pages, rules);
  }

  cout << sum << endl;
  
  return 0;
}
