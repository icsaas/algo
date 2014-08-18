#include <iostream>
using namespace std;

void insertsort(int a[],int len)
{
    for(int i=1;i<len;i++)
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

int main(){
int a[]={5,4,3,2,1};
insertsort(a,5);
for(int i=0;i<5;i++)
{
    cout<<a[i]<<' ';
}
cout<<endl;
}
