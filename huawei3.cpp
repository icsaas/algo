#include <iostream>
#include <cstring>

using namespace std;
const int maxn=100;
const int max_INT=10000;
int reminder_exist[max_INT];
int reminder_pos[max_INT];

void div(const int a,const int b,char *str)
{
    int numerator,denominator,quotient,reminder,outcnt=0;

    int flag = 0;
    int original_numerator = a;

    memset(reminder_exist, 0, sizeof(reminder_exist));
    memset(reminder_pos, 0, sizeof(reminder_pos));

    numerator=a;

    denominator=b;
    if (a*b<0)
    {
        flag=1;
    }
    //将分子和分母变成整数
    numerator=numerator<0?-numerator:numerator;
    denominator=denominator<0 ? -denominator:denominator;

    quotient=numerator/denominator;
    reminder=numerator%denominator;
    
    int integer=quotient;

    //找出循环
    
    int cycle_pos=maxn; //循环的位置
    int cycle_len=0;    //初始化循环长度

    int i=0;
    for(i=0;i<=maxn;i++)
    {
        //找出余数相等的情况，求出循环周期
        if(reminder_exist[reminder])
        {
            cycle_pos=reminder_pos[reminder];
            cycle_len=i-cycle_pos;
            break;
        }
        else
        {
            reminder_exist[reminder]=1;
            reminder_pos[reminder]=i;
        }
        
        numerator=reminder*10;
        quotient=numerator/denominator;
        reminder=numerator%denominator;

        str[outcnt++]=quotient+'0';//将更新的商存入字符串中

    }
       str[outcnt++]='\0';

       if(!flag)
       {
       cout<<integer<<".";
       }
       else{
         cout<<"-"<<integer<<".";
       }

       for(int j=0;j<cycle_pos;j++)
           cout<<str[j];
    
       cout<<"(";
       for(int j=cycle_pos;j<i;j++)
           cout<<str[j];

       cout<<")"<<endl;
}

int main()
{
    int a,b,flag=0;
    char s[maxn];
    cin>>a>>b;
    if(!a&&!b)
    {
        return 0;
    }
    div(a,b,s);
    return 0;

}
