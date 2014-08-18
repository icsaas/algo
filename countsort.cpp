#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
using namespace std;

void countsort(int *a,int *b,int *order,int n,int k)
{
    int *c=new int[k+1];
    int i;
    memset(c,0,sizeof(int)*(k+1));
    for(i=1;i<=n;i++)
        c[a[i]]++;
    for(i=2;i<=k;i++)
        c[i]+=c[i-1];
    for(i=n;i>=1;i--)
    {
        b[c[i]]=a[i];
        order[c[a[i]]]=i;
        c[a[i]]--;
    }
}

int main()
{

}
