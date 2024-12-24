#include <iostream>
#include <fstream>
#include <string>
#include <regex>

using namespace std;

int sumOfLine(string& line) {
  int sum = 0;
  regex pattern(R"(mul\((\d+),(\d+)\))");
  smatch matches;
  auto searchStart = line.cbegin();
  while (regex_search(searchStart, line.cend(), matches, pattern)) {
    sum += stoi(matches[1].str()) * stoi(matches[2].str());
  }
  return sum;
}

int main() {
    ifstream inFile("input");
    if (!inFile) {
        cerr << "Error opening file!" << endl;
        return 1;
    }

    int sum = 0;
    string line;
    while (getline(inFile, line)) {
      sum += sumOfLine(line);
    }

    cout << sum << endl;

    return 0;
}
