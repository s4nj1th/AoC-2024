#include <bits/stdc++.h>
#include <fstream>
#include <string>
using namespace std;

typedef vector<int> vInt;
typedef long long ll;

vInt makeFs(string str) {
    vInt vec;
    for (int i = 0; i < str.size(); i++) {
        bool bORs = false;
        if (i % 2 == 0) {
            bORs = true;
        }

        for (int j = 0; j < str[i] - '0' && bORs; j++) {
            vec.push_back(i/2);
        }

        for (int j = 0; j < str[i] - '0' && !bORs; j++) {
            vec.push_back(-1);
        }
    }

    return vec;
}

ll checkSum(vInt vec) {
    ll  i = 0,
        n = vec.size() - 1,
        sum = 0;

    while (i <= n) {
        if (vec[i] == -1) {
            if (vec[n] == -1) {
                n--;
            } else {
                sum += i*vec[n];
                i++;
                n--;
            }
        } else {
            sum+= i*vec[i];
            i++;
        }
    }

    return sum;
}

int main() {

    // string input = "2333133121414131402";

    string input;
    ifstream inFile("input");
    getline(inFile, input);

    auto vec = makeFs(input);
    // for (int i : vec) {
    //     if (i == -1) { cout << "_ "; continue; }
    //     cout << i << " ";
    // }
    // cout << endl;

    cout << "Checksum of the given FS: " << checkSum(vec) << endl;

}