#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using std::cin;
using std::cout;
using std::domain_error;
using std::endl;
using std::string;
using std::vector;

std::istream &read(std::istream &in, vector<string> &s)
{
    string x;
    while (in >> x)
    {
        s.push_back(x);
    }
    if (s.size() == 0)
        throw domain_error("No words entered. ");
    return in;
}

int main()
{
    vector<string> s;
    vector<int> flg;
    vector<int> count;
    int number_of_words = 0;
    string::size_type maxlen = 0;
    cout << "Enter some English words:" << endl;
    try
    {
        read(cin, s);
        for (int i = 0; i != s.size(); ++i)
        {
            flg.push_back(1);
            count.push_back(1);
        }
        for (int i = 0; i != s.size(); ++i)
        {
            if (flg[i])
            {
                number_of_words++;
                for (int k = i + 1; k != s.size() && flg[k]; ++k)
                {
                    if (s[k].size() != s[i].size())
                        flg[k] = 1;
                    else
                    {
                        flg[k] = 0;
                        for (int j = 0; j != s[k].size() && !flg[k]; ++j)
                        {
                            
                            if (s[k][j] >= 'A' && s[k][j] <= 'Z')
                            {
                                if (s[k][j] != s[i][j] && s[k][j] != s[i][j] - 32)
                                    flg[k] = 1;
                            }
                            else if (s[k][j] >= 'a' && s[k][j] <= 'z')
                            {
                                if (s[k][j] != s[i][j] && s[k][j] != s[i][j] + 32)
                                    flg[k] = 1;
                            }
                            else
                            {
                                if (s[k][j] != s[i][j])
                                    flg[k] = 1;
                            }
                        }
                    }
                    if (!flg[k])
                        count[i]++;
                    maxlen = std::max(maxlen, s[i].size());
                }
                
            }
        }
        cout << "number of the words: " << number_of_words << endl;
        for (int i = 0; i != s.size(); ++i)
        {
            if(flg[i])
            cout << s[i] << string(maxlen + 1 - s[i].size(), ' ') << count[i] << endl;
        }
    }
    catch (domain_error e)
    {
        cout << e.what() << "Please try again!" << endl;
    }
    return 0;
}