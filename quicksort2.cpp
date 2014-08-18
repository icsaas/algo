#include <iostream>
using namespace std;

int partition(int a[],int left,int right)
{
    int i,j;
    int pivot=a[right];
    j=left;

    for(i=left;i<right;++i)
    {
        if (a[i]<pivot)
        {
            swap(a[i],a[j]);
            j++;
        }
    }
    swap(a[j],a[right]);
    return j;
}

int quicksort(int a[],int left,int right)
{
    if (left<right)
    {
    int mid=partition(a,left,right);
    quicksort(a,left,mid-1);
    quicksort(a,mid+1,right);
    }
}

int main()
{
    int a[10]={10,8,9,7,6,5,4,3,2,1};
    quicksort(a,0,9);
    for(int i=0;i<10;i++)
    cout<<a[i]<<' ';
    cout<<endl;
}
