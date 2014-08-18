#include <iostream>
using namespace std;

void AdjustHeap(int a[],int s,int len)
{
    int child=2*s+1;
    int tmp=a[s];
    while(child<len)
    {
        if (child+1<len && a[child]<a[child+1])
            child++;
        if(tmp<a[child])
        {
            a[s]=a[child];
            s=child;
            child=2*s+1;
        }
        else
            break;
    }
    a[s]=tmp;
}


void BuildHeap(int a[],int len)
{
    for(int s=(len-1)/2;s>=0;s--)
        AdjustHeap(a,s,len);
}


void HeapSort(int a[],int len)
{
    BuildHeap(a,len);
    for(int i=len-1;i>0;i--)
    {
        int tmp=a[i];
        a[i]=a[0];
        a[0]=tmp;
        AdjustHeap(a,0,i);
    }
}

int main()
{
    int a[5]={5,4,3,2,1};
    HeapSort(a,5);
    for(int i=0;i<5;i++)
        cout<<a[i]<<' ';
    cout<<endl;

}
