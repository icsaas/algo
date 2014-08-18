#include <iostream>

using namespace std;

int main()
{
    int n;
    int cnt=0;
    cin>>n;
    for(int x=1;;x++)
    {
        int y=x*x;
        if(y>n)
            break;
        cnt++;
    }
    cout<<cnt<<endl;
}
