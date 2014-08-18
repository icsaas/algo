#include <stdio.h>
#include <stdlib.h>

void HeapBottomUp(int a[],int n)
{
    int i,j,k;
    int tmp;
    bool heap;
    for(i=n/2;i>0;i--)
    {
        tmp=a[i];
        k=i;
        heap=false;
        while(!heap&&2*k<=n)
        {
            j=2*k;
            if(j<n)
                if(a[j]<a[j+1])
                {
                j=j+1;
                }
            if (tmp>=a[j])
                heap=true;
            else
            {
                a[k]=a[j];
                k=j;
            }
        }
        a[k]=tmp;
    }
}

void FixHeapBottomUp(int a[],int n)
{
    int i,j;
    int tmp;
    bool flag;
    tmp=a[n];
    i=n;
    j=i/2;
    flag=true;
    while (flag&&j>0)
    {
        if (a[j]>=tmp)
            flag=false;
        else{
            a[i]=a[j];//较小节点往下移
            i=j;
            j=i/2;
        }
    }
    a[i]=tmp;
}

void FixHeapUpBottom(int a[],int n)
{
    int tmp;
    int i,j;
    int flag;
    tmp=a[1];
    flag=true;
    i=1;
    j=2*i;
    while (flag&&j<=n)
    {
        if (j+1<=n&&a[j+1]>a[j])
            j=j+1;
        if (a[j]<=tmp)
            flag=false;
        else
        {
            a[i]=a[j];//较大节点往上移
            i=j;
            j=2*i;
        }
    }
    a[i]=tmp;
}

void InsertNumber(int a[],int n,int num)
{
    int i,j;
    a[n]=num;
    FixHeapBottomUp(a,n);
}

int DeleteNumber(int a[],int n)
{
    int tmp;
    tmp=a[1];
    a[1]=a[n];
    a[n]=tmp;
    FixHeapUpBottom(a,n-1);
    return tmp;
}

void HeapSort(int a[],int n)
{
    int i;
    HeapBottomUp(a,n);
    for(i=n;i>1;i--)
        DeleteNumber(a,i);
}

int main(int argc,const char *argv[])
{
    int a[7]={0,2,9,7,6,5,8};
    int n=sizeof(a)/sizeof(int);
    HeapSort(a,n-1);
    for (int i=1;i<7;i++)
        printf("%d ",a[i]);
    printf("\n");
    return 0;
}
