#include <iostream>
using namespace std;

struct node
{
    char data;
    struct node *next;
};

typedef struct node NODE;

void test_exercise006()
{
    NODE *head=new NODE;
    head->next=NULL;
    //创建链表
    
    NODE *current,*previous;
    previous=head;
    char input;
    cout<<"Input your list table NODE data,end with '#':";

    cin>>input;
    
    while(input!='#')
    {
        current=new NODE;
        current->data=input;
        current->next=NULL;
        previous->next=current;
        previous=previous->next;
        cout<<"Input your list table NODE data,end with'#':";
        cin>>input;
    }

    /*输出链表*/
    current=head->next;
    while(current!=NULL)
    {
        cout<<current->data<<" ";
        current=current->next;
    }
    cout<<endl;
    /*倒转链表*/
    current=head->next;
    NODE *p=current->next;
    NODE *q=p->next;

    while(q!=NULL)
    {
        p->next=current;
        current=p;
        p=q;
        q=q->next;
    }

    p->next=current;
    current=p;
    head->next->next=NULL;
    head->next=current;

    //输出链表
    current=head->next;
    while(current!=NULL)
    {
        cout<<current->data<<" ";
        current=current->next;
    }
}

int main()
{
     test_exercise006();
     return 1;
}
