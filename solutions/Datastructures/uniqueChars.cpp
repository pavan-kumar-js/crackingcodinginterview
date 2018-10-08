
#include<iostream>
#include <assert.h>
#include <string>
#include <algorithm>

using namespace std;
// Custom Assertion ////////////////////////////////////

bool assert_str(string a, string b) {
    return a.compare(b) == 0;
}

bool assert_int(int a, int b) {
    return a == b;
}

void assertp_int(int a, int b) {
    if (assert_int(a, b)) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }
}

//Method 1 - Bruteforce
// O(n^2) - Time
// O(1) - Space
bool unique_chars(string value) {

    int i, n = value.size();
    if (n == 1) {
        return true;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (j == i) {
                continue;
            }
            if (value[i] == value[j]) {
                return false;
            }
        }
    }
    return true;
}

//Method 2 - Sorting
// O(n * logn) - Time
// O(1) - Space
bool unique_chars2(string value) {

    int n = value.size();
    sort(value.begin(), value.end());

    for (int i = 0; i < n - 1; i++) {
        if (value[i] == value[i + 1]) {
            return false;
        }
    }
    return true;
}

//Method 3 - Hashing
// O(n) - Time
// O(1) - Space
bool unique_chars3(string value) {

    int track[128] = {0};

    int n = value.size();

    for (int i = 0; i < n; i++) {
        if (track[value[i]]) {
            return false;
        }
        track[value[i]] = 1;
    }
    return true;
}


int main() {

    string val = "abcdef";

    //assertp_int(unique_chars("abcdef"),6);

    cout << unique_chars3("");

    return 0;
}