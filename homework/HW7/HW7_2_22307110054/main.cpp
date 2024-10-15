#include "Str.h"
#include "Vec.h"

using std::cin;
using std::cout;
using std::domain_error;
using std::endl;

struct Word
{
    Str str;
    int count = 1;
};

std::istream &read(std::istream &in, Vec<Word> &s)
{
    Word w;
    while (in >> w.str)
    {
        s.push_back(w);
    }
    if (s.size() == 0)
        throw domain_error("No words entered. ");
    return in;
}

bool isSame(Str &x, Str &y)
{
    bool flg = 1;
    if (x.size() != y.size())
        flg = 0;

    else
    {
        for (Str::size_type i = 0; i != x.size(); ++i)
        {
            if ((x[i]) != (y[i]))
                flg = 0;
        }
    }
    return flg;
}

bool cmp(Word &x, Word &y)
{
    return x.str < y.str;
}
int main()
{
    Vec<Word> vec_word;
    Str::size_type maxlen = 0;
    cout << "Enter some text: ";
    try
    {
        read(cin, vec_word);
        for (Vec<Str>::size_type i = 0; i != vec_word.size(); ++i)
            vec_word[i].str.transfer();
        for (Vec<Str>::size_type i = 0; i != vec_word.size(); ++i)
        {
            for (Vec<Str>::size_type j = i + 1; j != vec_word.size(); ++j)
                if (isSame(vec_word[i].str, vec_word[j].str) && vec_word[j].count)
                {
                    vec_word[i].count++;
                    vec_word[j].count = 0;
                }

            maxlen = std::max(maxlen, vec_word[i].str.size());
        }

        std::sort(vec_word.begin(), vec_word.end(), cmp);
        for (int i = 0; i != vec_word.size(); ++i)
        {
            if (vec_word[i].count)
                cout << vec_word[i].str << Str(maxlen + 1 - vec_word[i].str.size(), ' ') << vec_word[i].count << endl;
        }
    }
    catch (domain_error e)
    {
        cout << e.what() << "Please try again!" << endl;
    }
    return 0;
}