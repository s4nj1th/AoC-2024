#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>
#include <fstream>
using namespace std;

int main() {
  ifstream inFile("input");
  vector<long long int> list1, list2;
  string line;
  
  while (getline(inFile, line)) {
    istringstream stream(line);
    long long int n1, n2;
    if (stream >> n1 >> n2) {
      list1.push_back(n1);
      list2.push_back(n2);
    }
  }
  /*sort(list1.begin(), list1.end());*/
  /*sort(list2.begin(), list2.end());*/
  long long int sum = 0;
  for (int i = 0; i < 1000; i++) {
    sum += list1[i] * count(list2.begin(), list2.end(), list1[i]);
  } cout << sum;
  inFile.close();
  return 0;
}
