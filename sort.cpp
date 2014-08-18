#include <iostream>
using namespace std;
void bubblesort(int a[],int length)
{   //O(n^2)  stable
    for(int i=0;i<=length-1;i++)
    {
        for(int j=length-1;j>i;j--)
        {
        if (a[j]<a[j-1])
        {
            int tmp=a[j];
            a[j]=a[j-1];
            a[j-1]=tmp;
        }
        }
    }
}


void choicesort(int a[],int length)
{   //o(n^2) unstable
    int min;
    for(int i=0;i<length-1;i++)
    {
       min=i;
       for(int j=i+1;j<length;j++)
       {
           if (a[j]<a[min])
               min=j;
       }
       int tmp=a[min];
       a[min]=a[i];
       a[i]=tmp;
    }
}

void insertsort(int a[],int length){
    //O(n^2) stable
    for(int i=1;i<length;i++)
    {
        int tmp=a[i];
        //j>0 && tmp<array[j-1]为每一轮排序停止条件
        int j;
        for(j=i;j>0&&tmp<a[j-1];j--)
        {
            a[j]=a[j-1];
        }
        a[j]=tmp;
    }
}

void shellsort(int a[],int n)
{
    int i,j,gap;
    for( gap=n/2; gap>0; gap/=2)
        for(i=0;i<gap;i++)
        {
            for(j = i+gap;j < n;j += gap)
            if (a[j] < a[j-gap])
            {
                int tmp = a[j];
                int k = j-gap;
                while( k>=0 && a[k]>tmp)
                {
                    a[k+gap] = a[k];
                    k -= gap;
                }
                a[k+gap]=tmp;
            }
        }
}

void shellsort2(int a[],int n)
{
    int j,gap;
    for(gap=n/2;gap>0;gap/=2)
    {
        for(j=gap;j<n;j++)
            if(a[j]<a[j-gap])
            {
                int tmp=a[j];
                int k=j-gap;
                while(k>=0&&a[k]>tmp)
                {
                    a[k+gap]=a[k];
                    k-=gap;
                }
                a[k+gap]=tmp;
            }
    }
}


int main(){
    int a[]={5,3,2,1,3,5};
    for (int i=0;i<6;i++)
    cout<<a[i]<<' ';
    cout<<endl;
    //bubblesort(a,6);
    //choicesort(a,6);
    insertsort(a,6);
    for(int i=0;i<6;i++)
    cout<<a[i]<<' ';
    cout<<endl;
}
