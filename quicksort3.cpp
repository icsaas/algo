#include <iostream>
using namespace std;

int partition(int a[],int left,int right)
{
    int pivot=a[right];
    int storeIdx=left;
    for(int i=left;i<right;i++)
    {
        if(a[i]<pivot)
        {
            swap(a[i],a[storeIdx]);
            storeIdx++;
        }
    }
    swap(a[storeIdx],a[right]);
    return storeIdx;
}

void quicksort(int a[],int left,int right)
{
    if(left<right)
    {
        int mid=partition(a,left,right);
        quicksort(a,left,mid-1);
        quicksort(a,mid+1,right);
    }
}

int main()
{
    int a[]={10,10,9,8,7,6,5,4,3,2};
    quicksort(a,0,9);
    for(int i=0;i<10;i++)
        cout<<a[i]<<' ';
    cout<<endl;
    return 1;
}
