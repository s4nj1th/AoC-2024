#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

#define lint long int

lint concat(lint a, lint b) {
    string s1 = to_string(a),
        s2 = to_string(b);
    return stoll(s1+s2);
}

bool checkCombos2(const vector<lint>& nums, lint combination, lint target) {
    lint result = nums[0];
    for (lint i = 0; i < nums.size() - 1; i++) {
        lint op = (combination >> (2*i)) & 3;
        if (op == 0) {
            result *= nums[i + 1];
        } else if (op == 1) {
            result += nums[i + 1];
        } else if (op == 2) {
            result = concat(result, nums[i+1]);
        }
    }
    return (result == target);
}

bool checkCombos(const vector<lint>& nums, lint combination, lint target) {
    lint result = nums[0];
    for (int i = 0; i < nums.size() - 1; i++) {
        if (combination & (1 << i)) {
            result *= nums[i + 1];
        } else {
            result += nums[i + 1];
        }
    }
    return (result == target);
}

lint sumOfNums(const vector<lint>& nums, lint target) {
    lint n = nums.size(),
        totalCombinations = 1 << (n - 1);
    lint sum = 0;

    for (int combination = 0; combination < totalCombinations; combination++) {
        if(checkCombos(nums, combination, target)) {
          return target;
          }
    }
    return 0;
}


lint sumOfNums2(const vector<lint>& nums, lint target) {
    lint n = nums.size();
    lint totalCombinations = (n -1)*(n - 1)*(n - 1);
    lint sum = 0;

    for (lint combination = 0; combination < totalCombinations; combination++) {
        if(checkCombos2(nums, combination, target)) {
          return target;
          }
    }
    return 0;
}


int main() {
  ifstream inFile("input");
  string line;
  istringstream stream;

  vector<lint> ans = {};
  vector<vector<lint>> ints = {};

  while (getline(inFile, line)) {
    lint x;
    char colon;
    stream = istringstream(line);
    stream >> x >> colon;
    ans.push_back(x);
    vector<lint> curInts;
    lint num;
    while (stream >> num) {
      curInts.push_back(num);
    } ints.push_back(curInts);
  }

  lint sum = 0;
  for (lint i = 0; i < ans.size(); i++) {
    sum += sumOfNums(ints[i], ans[i]);
  }

  long long int sum2 = 0;
  for (lint i = 0; i < ans.size(); i++) {
      sum2 += sumOfNums2(ints[i], ans[i]);
  }

  cout << "Sum of valid combos: " << sum << endl;
  cout << "Sum of valid combos (2): " << sum2 << endl;

  return 0;
}
