#include <iostream>
using namespace std;

void choicesort(int a[],int length)
{
    int min;
    for(int i=0;i<length;i++)
    {
        min=i;
        for(int j=i;j<length;j++)
        {
        if (a[j]<a[min])
           min=j;
        }
        int tmp=a[i];
        a[i]=a[min];
        a[min]=tmp;
    }
}

int main()
{
    int a[]={4,3,1,2,10,9,8,7,6,5};
    choicesort(a,10);
    for(int i=0;i<10;i++)
    {
        cout<<a[i]<<' ';
    }
    cout<<endl;
}
