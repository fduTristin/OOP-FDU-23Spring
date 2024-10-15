#include "Str.h"

using std::cin;
using std::cout;
using std::endl;

int main()
{
    cout << "Please enter your first name: ";
    Str name;
    cin >> name;

    cout << "please enter the number of the blanks surrounding the greeting: ";
    int pad;
    cin >> pad;
    cout << endl;

    const Str greeting = "Hello, " + name + "!";
    const int rows = 2 * pad + 3;
    const Str::size_type cols = greeting.size() + 2 * pad + 2;
    cout << endl;

    int r = 0;

    for (r = 0; r != rows; r++)
    {
        Str::size_type c = 0;
        while (c != cols)
        {
            if (r == pad + 1 && c == pad + 1)
            {
                cout << greeting;
                c += greeting.size();
            }
            else
            {
                if (r == 0 || r == rows - 1 || c == 0 || c == cols - 1)
                    cout << "*";
                else
                    cout << ' ';
                ++c;
            }
        }
        cout << endl;
    }

    cout<<"逐个字符输出greeting(字符之间以空格分离):"<<endl;
    for(Str::size_type i = 0; i!= greeting.size(); ++i)
    {
        cout<<greeting[i]<<" ";
    }
    return 0;
}