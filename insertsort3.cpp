#include <iostream>
using namespace std;

void insertsort(int a[],int length)
{
    for(int i=1;i<length;i++)
    {
        int tmp=a[i];
        int j=tmp;
        for(;j>0&&tmp<a[j-1];j--)
        {
            a[j]=a[j-1];
        }
        a[j]=tmp;
    }
}
