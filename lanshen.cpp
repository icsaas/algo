#include <stdio.h>

int main(){
int a,b,c[20000]={0},k=0;
scanf("%d%d",&a,&b);
for (int i=a;i<=b;i++)
{
    int sum=0;
    for (int j=1;j<i;j++)
    {
    if (i%j==0)sum+=j;
    }
    if (sum>a&&sum<b){
    c[i]=sum;
    }
}
for (int m=a;m<=b;m++){
    if(m==c[c[m]]&&c[m]!='\0'&&c[m]!=m)
    {
        printf("%d %d ok\n",m,c[m]);
        c[c[m]]=0;
    }
}
return 0;
}
