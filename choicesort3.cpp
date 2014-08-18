#include <iostream>
using namespace std;

void choicesort(int a[],int len)
{
    for(int i=0;i<len;i++)
    {
        int min=i;
        int tmp=a[i];
        for(int j=i;j<len;j++)
            if(a[j]<a[min])
            {
                min=j;
            }
        a[i]=a[min];
        a[min]=tmp;
    }
}

int main()
{
    int a[]={5,4,3,2,1,1,2,3,4,5};
    choicesort(a,10);
    for(int i=0;i<10;i++)
        cout<<a[i]<<' ';
    cout<<endl;
}
