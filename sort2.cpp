#include <iostream>
using namespace std;

void print(int a[],int len)
{
    for(int i=0;i<len;i++)
        cout<<a[i]<<' ';
    cout<<endl;
}
void bubblesort(int a[],int len)
{
    for(int i=0;i<len;i++)
    {
        for(int j=len-1;j>i;j--)
            if(a[j]<a[j-1])
                swap(a[j],a[j-1]);
    }
}

void bubblesort2(int a[],int len)
{
    for(int i=0;i<len;i++)
    {
        for(int j=0;j<len-i-1;++j)
        {
            if (a[j]>a[j+1])
            {
                swap(a[j],a[j+1]);
            }
        }
    }
}

int partition(int a[],int left,int right)
{
    int pivot=a[right];
    int i=left;
    for(int j=left;j<right;j++)
    {
        if (a[j]<=pivot)
        {
            swap(a[i],a[j]);
            i++;
        }
    }
    swap(a[i],a[right]);
    return i;
}

int partition2(int a[],int left,int right)
{
    int pivot=a[left];
    while(left<right)
    {
         while(left<right && a[right]>=pivot) --right;
         swap(a[left],a[right]);
         while(left<right && a[left]<=pivot) ++left;
         swap(a[left],a[right]);
    }
    return left;
}

void quicksort(int a[],int left,int right)
{
    if(left<right)
    {
        int mid=partition2(a,left,right);
        quicksort(a,left,mid-1);
        quicksort(a,mid+1,right);
    }
}
void insertsort(int a[],int len)
{
    for(int i=1;i<len;i++)
    {
        int tmp=a[i];
        int j=i;
        for(;j>0&&tmp<a[j-1];j--)
            a[j]=a[j-1];
        a[j]=tmp;
    }
}

void shellinsertsort(int a[],int len,int dk)
{
    for(int i=dk;i<len;++i)
    {
        if (a[i]<a[i-dk])
        {
            int j=i-dk;
            int x=a[i];
            a[i]=a[i-dk];
            while(j>=0 && x<a[j])
            {
                a[j+dk]=a[j];
                j-=dk;
            }
            a[j+dk]=x;
        }
    }
}

void shellsort(int a[],int len)
{
    int dk=len/2;
    while(dk>=1)
    {
    shellinsertsort(a,len,dk);
    dk = dk/2;
    }
}

void choicesort(int a[],int len)
{
    for(int i=0;i<len;i++)
    {
        int min=i;
        int tmp=a[i];
        for(int j=i;j<len;j++)
        {
            if (a[j]<a[min])
            {
                min=j;
            }
        }
        a[i]=a[min];
        a[min]=tmp;
    }
}

void HeapAdjust(int a[],int s,int len)
{
    int child=2*s+1;
    int tmp=a[s];
    while(child<len)
    {
        if (child+1<len && a[child+1]>a[child])
            child++;
        if (a[s]<a[child])
        {
            a[s]=a[child];
            s=child;
            child=2*s+1;
        }
        else
            break;
        a[s]=tmp;
    }
}


void BuildHeap(int a[],int len)
{
    for(int i=(len-1)/2;i>=0;i--)
    {
      HeapAdjust(a,i,len);
    }
}

void HeapSort(int a[],int len)
{
    BuildHeap(a,len);
    for(int i=len-1;i>0;i--)
    {
        swap(a[0],a[i]);
        HeapAdjust(a,0,i);
    }
}
void merge(int a[],int first,int mid,int last,int tmp[])
{
    int i=first,j=mid+1;
    int m=mid,n=last;
    int k=0;
    while(i<=m && j<=n)
    {
        if (a[i]<=a[j])
            tmp[k++]=a[i++];
        else
            tmp[k++]=a[j++];
    }
    while(i<=m)
        tmp[k++]=a[i++];
    while(j<=n)
        tmp[k++]=a[j++];

    for(i=0;i<k;i++)
        a[first+i]=tmp[i];
}

void mergesort(int a[],int first,int last,int tmp[])
{
    if (first<last)
    {
        int mid=(first+last)/2;
        mergesort(a,first,mid,tmp);
        mergesort(a,mid+1,last,tmp);
        merge(a,first,mid,last,tmp);
    }
}

int main()
{
    int a[]={5,4,3,2,1};
    //quicksort(a,0,4);
    int *p=new int[5];
    mergesort(a,0,4,p);
    delete[] p;

    print(a,5);
}
