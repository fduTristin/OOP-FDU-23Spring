#include <iostream>

using std::cin;     using std::cout;

int main() {
    int a, n, m, x;
    cin >> a >> n >> m >> x;
    if (x < 3) {
        cout << a;
        return 0;
    }
    int b; // b表示第2站上车的人数
    int f[n] = {0, 1}; // f表示斐波那契数列
    for (int i = 2; i < n; i++) {
        f[i] = f[i - 1] + f[i - 2];
    }
    int u[n] = {0, 1, 1}; // u表示开出时车上人数a的系数
    int v[n] = {0, 0, 0}; // v表示开出时车上人数b的系数
    for (int i = 3; i < n; ++i) {
        u[i] = u[i - 1] + f[i - 2] - f[i - 3];
        v[i] = v[i - 1] + f[i - 1] - f[i - 2];
    }
    b = (m - u[n - 1] * a) / v[n - 1];
    cout << u[x] * a + v[x] * b;
    return 0;
}