#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

using namespace std;

void OutPutEmptyLine()
{
    cout<<"\n";
}

//逐词读取，词之间用空格区分
void ReadDataFromFileWBW()
{
    ifstream fin("data.txt");
    string s;
    while(fin>>s)
    {
        cout<<"Read from file: "<<s<<endl;
    }
}

//逐行读取
void ReadDataFromFileLBLIntoCharArray()
{
    ifstream fin("data.txt");
    const int LINE_LENGTH=100;
    char str[LINE_LENGTH];
    while(fin.getline(str,LINE_LENGTH))
    {
        cout<<"READ from file: "<<str<<endl;
    }
}

//逐行读取
void ReadDataFromFileLBLIntoString()
{
    ifstream fin("data.txt");
    string s;
    while(getline(fin,s))
    {
        cout<<"Read from file: "<<s<<endl;
    }
}

//带错误检测的读取方式 
void ReadDataWithErrChecking()
{
    string filename="dataFUNNY.txt";
    ifstream fin(filename.c_str());
    if(!fin)
    {
        cout<<"Error opening"<<filename<<"for input"<<endl;
        exit(-1);
    }
}

int main()
{
    ReadDataFromFileWBW();
    OutPutEmptyLine();

    ReadDataFromFileLBLIntoCharArray();
    OutPutEmptyLine();

    ReadDataFromFileLBLIntoString();
    OutPutEmptyLine();

    ReadDataWithErrChecking();
    return 0;
}
