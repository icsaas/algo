#include <iostream>
using namespace std;

void bubblesort(int a[],int len)
{
    for(int i=0;i<len;i++)
        for(int j=len-1;j>i;j--)
        {
            if (a[j-1]>a[j])
            {
            int tmp=a[j-1];
            a[j-1]=a[j];
            a[j]=tmp;
            }
        }
}


int main()
{
    int a[]={5,7,9,1,2,3};
    bubblesort(a,6);
    for(int i=0;i<6;i++)
        cout<<a[i]<<' ';
    cout<<endl;
}
