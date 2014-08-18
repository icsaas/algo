#include <iostream>
#include <string>
#include <stdio.h>

const int TableSize=256;
using namespace std;

int Equalchar(char *str)
{
    int hashTable[TableSize];
    for(int i=0;i<TableSize;i++)
        hashTable[i]=0;
    char *phashKey=str;
    while(*phashKey)
    {
        hashTable[*phashKey]++;
        phashKey++;
    }
    phashKey=str;
    while(*phashKey)
    {
        if(hashTable[*phashKey]>1)
            return 1;
        phashKey++;
    }
    return 0;
}

int main()
{
    char s[1000];
    gets(s);
    cout<<Equalchar(s)<<endl;
    return 0;
}
