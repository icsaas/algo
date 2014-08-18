#include <iostream>
using namespace std;

int partition(int a[],int left,int right){
   int pivot=a[right];
   int i=left-1;
   for(int j=left;j<right;j++)
   {
       if(a[j]<=pivot)
       {
           i++;
           swap(a[i],a[j]);
       }
   }
   swap(a[i+1],a[right]);
   return i+1;
}

void quicksort(int a[],int left,int right)
{
// cout<<"quick sort starting" <<endl; 
  if (left<right)
  {
     int mid=partition(a,left,right);
     quicksort(a,left,mid-1);
     quicksort(a,mid+1,right);
  }
}

void quicksortnd(int a[],int len)
{
    if (len<2) return;
    int *stk=new int[len];

    int p=0;
    int l,h,m;
    stk[p++]=0;
    stk[p++]=len-1;
    while(p!=0)
    {
        h=stk[--p];
        l=stk[--p];

        if (l<h)
        {
            m=partition(a,l,h);
            if (m-1>l)
            {
                stk[p++]=l;
                stk[p++]=m-1;
            }
            if(m+1<h)
            {
                stk[p++]=m+1;
                stk[p++]=h;
            }
        }
    }
    delete[] stk;
}

int main()
{
    int a[10]={4,5,6,9,1,7,8,2,3,11};
    for (int i=0;i<10;i++)
    cout<<a[i]<<' ';
    cout<<endl;
    quicksort(a,0,9);
    for (int i=0;i<10;i++)
    cout<<a[i]<<' '; 
    cout<<endl;
    return 1;
}
