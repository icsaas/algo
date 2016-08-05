#include <iostream>
using namespace std;

void max_min(int *num,int l,int r,int &maxnum,int &minnum){
    if(l==r){   //数组只有一个元素
      maxnum = num[l];
      minnum = num[l];
      return;
    }
    if(l+1==r){  //数组有两个元素
     if(num[l]>num[r]){
     maxnum = num[l];
     minnum = num[r];
    }
    else {
      maxnum = num[r];
      minnum = num[l];
    }
  return;   //确定最大最小值之后必须返回，否则将进入死循环
    }
    int m = (l+r)/2;
    int lmax,lmin;
    max_min(num,l,m,lmax,lmin)  ;//递归球左半部分最大最小值
    
    int rmax,rmin;
    max_min(num,m,r,rmax,rmin);
   
    maxnum = max(lmax,rmax);
    minnum = min(lmin,rmin);
}


int main(){

     int a[10] = {0,9,1,5,3,4,8,2,7,5};
     int maxnum,minnum;
     max_min(a,0,9,maxnum,minnum);
     cout<<maxnum<<","<<minnum<<endl;
     return 0;
}
