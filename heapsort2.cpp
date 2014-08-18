#include <iostream>
using namespace std;

void print(int a[],int n){
  for(int j=0;j<n;j++){
     cout<<a[j]<<" ";
  }
  cout<<endl;
}

/**
 * 已知H[s..m]除了H[s]外均满足堆的定义
 * 调整H[s],使其成为大顶堆，即将对第s个节点为根的子树筛选，
 *
 * @param H是待调整的堆数组
 * @param s是待调整的数组元素的位置
 * @param length是数组的长度
 */
void HeapAdjust(int H[],int s,int length)
{
    int tmp = H[s];
    int child = 2*s+1;
    while (child<length)
    {
        if (child+1<length && H[child]<H[child+1])
        {
            ++child;
        }
        if (H[s]<H[child])
        {
            H[s]=H[child];
            s=child;
            child=2*s+1;
        }
        else
        {
            break;
        }
        H[s]=tmp;
    }
    print(H,length);
}
void BuildingHeap(int H[],int length)
{
for(int i=(length-1)/2;i>=0;--i)
{
    HeapAdjust(H,i,length);
}
}

void HeapSort(int H[],int length)
{
    BuildingHeap(H,length);

    for(int i=length-1;i>0;--i)
    {
        int tmp=H[i];
        H[i]=H[0];
        H[0]=tmp;
        HeapAdjust(H,0,i);
    }
}

int main()
{
    int H[10]={3,1,5,7,2,4,9,6,10,8};
    cout<<"初始值: ";
    print(H,10);
    HeapSort(H,10);
    cout<<"结果:";
    print(H,10);
}
