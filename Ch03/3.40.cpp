#include<iostream>
#include<cstring>
using std::cout;
using std::cin;
using std::endl;
using std::string;
int main()
{
    char s1[] = "i love programming";
    char s2[] = "i love learning";
    char large[19];
    strcpy(large, s1);
    strcat(large, s2);
    cout << large << endl;
    return 0;
}
