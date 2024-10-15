#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

int main()
{
    int n;
    int flg = -1;
    cout<<"Enter a positive integer: ";
    cin >> n;
    cout<<endl;
    vector<int> a(n, 0);
    vector<vector<int>> s(n, a);
    int k = 1;
    for (int i = 0; i != 2 * n - 1; ++i)
    {
        for (int j = flg > 0 ? i : 0; j >= 0 && j <= 2 * n - 1; j -= flg)
        {
            if (j >= 0 && j < n && (i - j) >= 0 && (i - j) < n)
                s[j][i - j] = k++;
        }
        flg = -flg;
    }

    for (int i = 0; i != n; ++i)
    {
        for (int j = 0; j != n; ++j)
            cout << s[i][j] <<'\t';
        cout << endl<<endl;
    }

    return 0;
}