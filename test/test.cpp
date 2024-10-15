#include <iostream>
#include <string>
using namespace std;

int main()
{
    static char* const TIOBE[] = {(char*)"java"};
    TIOBE[0][0]='a';

}