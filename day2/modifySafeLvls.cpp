#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

bool isSafe(vector<int>& lvls);

bool modifyLvl(vector<int>& lvls) {
    if (isSafe(lvls)) return true;
    for (int i = 0; i < lvls.size(); i++) {
        vector<int> modLvl;
        for (int j = 0; j < lvls.size(); j++) {
            if (i != j) modLvl.push_back(lvls[j]);
        }
        if (isSafe(modLvl)) return true;
    }
    return false;
}

bool isSafe(vector<int>& lvls) {
  
  if (lvls.size() < 2) return true;
  bool dec = false, inc = false;
  for (int i = 1; i < lvls.size(); i++) {
      int diff = lvls[i] - lvls[i - 1];

      if (diff > 0) inc = true;
      else if (diff < 0) dec = true;

      if (abs(diff) < 1 || abs(diff) > 3) {
          return false;
      }

      if (inc && dec) {
          return false;
      }
  }

  return true;
}

int main() {
    ifstream inFile("input");
    string line;
    int safe = 0;
    while (getline(inFile, line)) {
        vector<int> levels;
        istringstream stream(line);
        int num;

        while (stream >> num) {
            levels.push_back(num);
        }

        if (modifyLvl(levels)) {
            ++safe;
        }
    }

    cout << "Safe lvls: " << safe << endl;

    return 0;
}
