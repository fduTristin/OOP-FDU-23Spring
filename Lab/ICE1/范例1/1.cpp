#include <iostream>
#include <string>

using std::cin;     using std::endl;
using std::cout;    using std::string;

int main() {
    cout << "Enter 3 English words: ";
    string a, b, c;
    cin >> a >> b >> c;
    string temp;
    if (a > b) { temp = a; a = b; b = temp; }
    if (b > c) { temp = b; b = c; c = temp; }
    if (a > b) { temp = a; a = b; b = temp; }
    cout << a << ' ' << b << ' ' << c << endl;
    return 0;
}