#include <iostream>

using namespace std;

void reverseString(string &str) {

    int i = 0, n = str.size() - 1;

    while (i < n) {
        swap(str[i], str[n]);
        i++;
        n--;
    }
}


int main() {

    string str = "Pavan";

    cout << str << endl;

    reverseString(str);

    cout << str;

}