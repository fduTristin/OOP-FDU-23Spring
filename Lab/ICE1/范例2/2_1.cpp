#include <iostream>

using std::cin;     using std::cout;

int main() {
    int a, n, m, x;
    cin >> a >> n >> m >> x;
    int u[n], v[n]; // u表示上车人数，v表示开出时车上人数
    if (x < 3) {
        cout << a;
        return 0;
    }
    u[1] = a;
    v[1] = a;
    v[2] = a;
    for (int i = 0; i < m; i++) {
        // 枚举第2站上车人数
        u[2] = i;
        for (int j = 3; j < n; j++) {
            u[j] = u[j - 1] + u[j - 2];
            v[j] = v[j - 1] + u[j - 2];
        }
        if (v[n - 1] == m){
            // 检验终点站人数是否满足条件
            cout << v[x];
            return 0;
        }
    }
    return 0;
}
