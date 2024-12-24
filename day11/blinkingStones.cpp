#include <bits/stdc++.h>
using namespace std;

typedef vector<long long> vLL;
typedef long ll;

int noOfDigs(ll no) {
    int i = 0;
    while (no != 0) {
        no /= 10;
        i++;
    } return i;
}

vLL blink(vLL vec) {
    vLL newV;
    for (ll i : vec) {
        if (i == 0) {
            newV.push_back(1);
            continue;
        } if (noOfDigs(i) % 2 == 0) {
            ll div = static_cast<ll>(pow(10, noOfDigs(i)/2));
            newV.push_back(i / div);
            newV.push_back(i % div);
            continue;
        }
        newV.push_back(i * 2024);
    }
    return newV;
}

int main() {

    // vLL vec = {0, 1, 10, 99, 999};
    // vLL vec = {125, 17};

    vLL vec = {2, 72, 8949, 0, 981038, 86311, 246, 7636740};

    for (int i = 0; i < 25; i++) {
        vec = blink(vec);
        // for (auto i : vec) {
        //     cout << i << " ";
        // } cout << endl;
    }

    cout << vec.size() << endl;

    vec = {2, 72, 8949, 0, 981038, 86311, 246, 7636740};

    for (int i = 0; i < 75; i++) {
        vec = blink(vec);
        // for (auto i : vec) {
        //     cout << i << " ";
        // } cout << endl;
    }

    cout << vec.size() << endl;

    return 0;
}