#include <iostream>
using namespace std;

void insertsort(int a[],int length)
{
    for(int i=1;i<length;i++)
    {
        int tmp=a[i];
        int j=i;
        for(;j>0&&tmp<a[j-1];j--)
        {
            a[j]=a[j-1];
        }
        a[j]=tmp;
    }
}

int main()
{
    int a[]={10,9,8,7,6,5,4,3,2,1};
    insertsort(a,10);
    for(int i=0;i<10;i++){
    cout<<a[i]<<' ';
    }
    cout<<endl;
}
