#include <iostream>
using namespace std;

void HeapAdjust(int a[],int s,int len)
{
    int tmp=a[s];
    int child=2*s+1;
    while(child<len)
    {
        if (child+1<len && a[child+1]>a[child])
            child++;
        if (a[s]<a[child])
        {
            a[s]=a[child];
            s=child;
            a[s]=tmp;
            child=2*s+1;
        }
        else
            break;
        //a[s]=tmp;
    }
}


void BuildHeap(int a[],int len)
{
    for(int s=(len-1)/2;s>=0;s--)
    {
        HeapAdjust(a,s,len);
    }
}

void HeapSort(int a[],int len)
{
    BuildHeap(a,len);
    for(int i=len-1;i>0;i--)
    {
        int tmp=a[i];
        a[i]=a[0];
        a[0]=tmp;
        HeapAdjust(a,0,i);
    }
}


int main()
{
    int a[]={5,4,3,2,1,1,2,3,4,5};
    HeapSort(a,10);
    for(int i=0;i<10;i++)
        cout<<a[i]<<' ';
    cout<<endl;
}
