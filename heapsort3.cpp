#include <iostream>
using namespace std;

void print(int a[],int n)
{
    for(int j=0;j<n;j++)
        cout<<a[j]<<" ";
    cout<<endl;
}


void HeapAdjust(int H[],int s,int len)
{
    int tmp=H[s];
    int child=2*s+1;
    while(child<len)
    {
        if (child+1<len && H[child]<H[child+1])
            ++child;
        if (H[s]<H[child])
        {
            H[s]=H[child];
            s=child;
            child=s*s+1;
        }
        else
           break;
        H[s]=tmp;
    }
    print(H,len);
}


void BuildHeap(int H[],int len)
{
    for(int i=(len-1)/2;i>=0;--i)
    {
        HeapAdjust(H,i,len);
    }
}

void HeapSort(int H[],int len)
{
    BuildHeap(H,len);
    for(int i=len-1;i>0;--i)
    {
        int tmp=H[i];
        H[i]=H[0];
        H[0]=tmp;
        HeapAdjust(H,0,i);
    }
}

int main()
{
    int a[]={5,4,3,2,1};
    HeapSort(a,5);
    for(int i=0;i<5;i++)
        cout<<a[i]<<' ';
    cout<<endl;
}
