#include <iostream>
using namespace std;

void bubblesort(int a[],int length)
{
    for(int i=0;i<=length-1;i++)
    {
        for(int j=length-1;j>i;j--)
        {
            if(a[j]<a[j-1])
            {
            int tmp=a[j];
            a[j]=a[j-1];
            a[j-1]=tmp;
            }
        }
    }
}

int main()
{
    int a[]={10,9,8,7,6,5,4,3,2,1};
    bubblesort(a,10);
    for(int i=0;i<10;i++)
    {
        cout<<a[i]<<' ';
    }
    cout<<endl;
}
